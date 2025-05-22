# Next.js Class Schedule Viewer

## Project Overview
Create a Next.js application that displays university class schedules from an optimized JSON file. The application includes client-side caching, section search functionality, and user-friendly display of class information.

## Data Structure
The application uses two JSON files:
1. `class_schedule_by_section.json` - The optimized data file (226KB)
2. `class_schedule_legend.json` - The legend file explaining the data structure

The data is structured as follows:
- Root: `[metadata, sections, indexes]`
- Metadata: `[totalSections, date]`
- Sections: Object with section keys (e.g., "62_G")
  - Each section has:
    - `c`: Array of classes, each class is `[courseCode, day, timeSlot, room, teacher]`
    - `m`: Metadata array `[batch, subSection, totalCourses, totalClasses]`
    - `s`: Summary array of courses, each is `[code, [teachers], classCount, [schedules]]`
- Days are represented as numbers: 0=SAT, 1=SUN, 2=MON, 3=TUE, 4=WED, 5=THU, 6=FRI

## Project Setup

```bash
npx create-next-app class-schedule-viewer
cd class-schedule-viewer
npm install @mantine/core @mantine/hooks swr
```

## Implementation

### 1. Data Fetching and Caching (hooks/useScheduleData.js)

```javascript
import useSWR from 'swr';

const fetcher = (url) => fetch(url).then((res) => res.json());

export function useScheduleData() {
  const { data, error, isLoading } = useSWR('/class_schedule_by_section.json', fetcher, {
    revalidateOnFocus: false,
    revalidateOnReconnect: false,
    dedupingInterval: 3600000, // 1 hour
  });
  
  return {
    data,
    isLoading,
    isError: error
  };
}

export function useLegendData() {
  const { data, error, isLoading } = useSWR('/class_schedule_legend.json', fetcher, {
    revalidateOnFocus: false,
    revalidateOnReconnect: false,
    dedupingInterval: 3600000, // 1 hour
  });
  
  return {
    legend: data,
    isLegendLoading: isLoading,
    isLegendError: error
  };
}
```

### 2. Utility Functions (utils/dataTransformers.js)

```javascript
export const dayMap = ['Saturday', 'Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday'];

export function convertDayNumberToName(dayNumber) {
  return dayMap[dayNumber] || 'Unknown';
}

export function parseScheduleString(scheduleStr) {
  const [dayNum, timeSlot, room] = scheduleStr.split(':');
  return {
    day: convertDayNumberToName(parseInt(dayNum)),
    time: timeSlot,
    room: room
  };
}

export function formatClassInfo(classData) {
  return {
    courseCode: classData[0],
    day: convertDayNumberToName(classData[1]),
    timeSlot: classData[2],
    room: classData[3],
    teacher: classData[4]
  };
}

export function getSectionData(data, sectionName) {
  if (!data || !data[1] || !data[1][sectionName]) return null;
  
  const sectionData = data[1][sectionName];
  const metadata = sectionData.m;
  
  return {
    metadata: {
      batch: metadata[0],
      subSection: metadata[1],
      totalCourses: metadata[2],
      totalClasses: metadata[3]
    },
    classes: sectionData.c.map(formatClassInfo),
    summary: sectionData.s.map(course => ({
      code: course[0],
      teachers: course[1],
      classCount: course[2],
      schedules: course[3].map(parseScheduleString)
    }))
  };
}

// Group classes by day for weekly view
export function groupClassesByDay(classes) {
  const dayGroups = {};
  
  // Initialize all days
  dayMap.forEach((day, index) => {
    dayGroups[index] = {
      name: day,
      classes: []
    };
  });
  
  // Add classes to appropriate days
  classes.forEach(cls => {
    const dayIndex = dayMap.indexOf(cls.day);
    if (dayIndex >= 0) {
      dayGroups[dayIndex].classes.push(cls);
    }
  });
  
  // Sort classes by time within each day
  Object.values(dayGroups).forEach(day => {
    day.classes.sort((a, b) => {
      const timeA = a.timeSlot.split('-')[0];
      const timeB = b.timeSlot.split('-')[0];
      return timeA.localeCompare(timeB);
    });
  });
  
  return dayGroups;
}

// Get all available sections from the data
export function getAllSections(data) {
  if (!data || !data[1]) return [];
  return Object.keys(data[1]).sort();
}
```

### 3. Main Page Component (pages/index.js)

```jsx
import { useState, useMemo } from 'react';
import { useScheduleData, useLegendData } from '../hooks/useScheduleData';
import { getSectionData, groupClassesByDay, getAllSections } from '../utils/dataTransformers';
import { 
  Container, TextInput, Title, Text, Tabs, 
  Table, Paper, Loader, Group, Badge, Autocomplete,
  Card, SimpleGrid, Box
} from '@mantine/core';

export default function Home() {
  const [sectionName, setSectionName] = useState('');
  const { data, isLoading, isError } = useScheduleData();
  const { legend } = useLegendData();
  
  // Get all available sections for autocomplete
  const allSections = useMemo(() => {
    return getAllSections(data);
  }, [data]);
  
  const sectionData = data && sectionName ? getSectionData(data, sectionName) : null;
  
  // Group classes by day for weekly view
  const classesByDay = useMemo(() => {
    if (!sectionData) return null;
    return groupClassesByDay(sectionData.classes);
  }, [sectionData]);
  
  return (
    <Container size="lg" py="xl">
      <Title order={1} align="center" mb="xl">University Class Schedule</Title>
      
      <Autocomplete
        label="Enter Section Name"
        placeholder="e.g., 62_G"
        value={sectionName}
        onChange={setSectionName}
        data={allSections}
        mb="lg"
      />
      
      {isLoading && <Loader size="xl" mx="auto" my="xl" />}
      
      {isError && (
        <Text color="red" align="center">Error loading data. Please try again.</Text>
      )}
      
      {sectionData ? (
        <Paper shadow="xs" p="md">
          <Group position="apart" mb="md">
            <div>
              <Text weight={700}>Batch: {sectionData.metadata.batch}</Text>
              <Text weight={700}>Section: {sectionData.metadata.subSection}</Text>
            </div>
            <div>
              <Badge size="lg">Courses: {sectionData.metadata.totalCourses}</Badge>
              <Badge size="lg" ml="xs">Classes: {sectionData.metadata.totalClasses}</Badge>
            </div>
          </Group>
          
          <Tabs defaultValue="all">
            <Tabs.List>
              <Tabs.Tab value="all">All Classes</Tabs.Tab>
              <Tabs.Tab value="by-course">By Course</Tabs.Tab>
              <Tabs.Tab value="weekly">Weekly Schedule</Tabs.Tab>
            </Tabs.List>
            
            <Tabs.Panel value="all" pt="xs">
              <Table striped highlightOnHover>
                <thead>
                  <tr>
                    <th>Course</th>
                    <th>Day</th>
                    <th>Time</th>
                    <th>Room</th>
                    <th>Teacher</th>
                  </tr>
                </thead>
                <tbody>
                  {sectionData.classes.map((cls, index) => (
                    <tr key={index}>
                      <td>{cls.courseCode}</td>
                      <td>{cls.day}</td>
                      <td>{cls.timeSlot}</td>
                      <td>{cls.room}</td>
                      <td>{cls.teacher}</td>
                    </tr>
                  ))}
                </tbody>
              </Table>
            </Tabs.Panel>
            
            <Tabs.Panel value="by-course" pt="xs">
              {sectionData.summary.map((course, index) => (
                <div key={index} style={{ marginBottom: '20px' }}>
                  <Title order={3}>{course.code}</Title>
                  <Text>Teachers: {course.teachers.join(', ')}</Text>
                  <Table>
                    <thead>
                      <tr>
                        <th>Day</th>
                        <th>Time</th>
                        <th>Room</th>
                      </tr>
                    </thead>
                    <tbody>
                      {course.schedules.map((schedule, idx) => (
                        <tr key={idx}>
                          <td>{schedule.day}</td>
                          <td>{schedule.time}</td>
                          <td>{schedule.room}</td>
                        </tr>
                      ))}
                    </tbody>
                  </Table>
                </div>
              ))}
            </Tabs.Panel>
            
            <Tabs.Panel value="weekly" pt="xs">
              <SimpleGrid cols={3} spacing="md">
                {classesByDay && Object.values(classesByDay).map((day, index) => (
                  <Card key={index} shadow="sm" p="md">
                    <Card.Section p="md" style={{ backgroundColor: '#f8f9fa' }}>
                      <Title order={4}>{day.name}</Title>
                    </Card.Section>
                    
                    {day.classes.length > 0 ? (
                      day.classes.map((cls, idx) => (
                        <Box key={idx} p="xs" mb="xs" style={{ borderBottom: '1px solid #eee' }}>
                          <Text weight={700}>{cls.courseCode}</Text>
                          <Text size="sm">{cls.timeSlot}</Text>
                          <Text size="sm">Room: {cls.room}</Text>
                          <Text size="xs">Teacher: {cls.teacher}</Text>
                        </Box>
                      ))
                    ) : (
                      <Text color="dimmed" align="center" py="md">No classes</Text>
                    )}
                  </Card>
                ))}
              </SimpleGrid>
            </Tabs.Panel>
          </Tabs>
        </Paper>
      ) : sectionName && !isLoading ? (
        <Text align="center">No data found for section "{sectionName}"</Text>
      ) : null}
    </Container>
  );
}
```

### 4. Setup for JSON Files

Place the JSON files in the `public` folder of your Next.js project:
- `public/class_schedule_by_section.json`
- `public/class_schedule_legend.json`

## Features

1. **Section Search with Autocomplete**
   - Users can search for sections with autocomplete suggestions

2. **Multiple Views**
   - All Classes: Shows all classes in a table
   - By Course: Groups classes by course code
   - Weekly Schedule: Displays classes in a weekly calendar view

3. **Client-Side Caching**
   - Uses SWR for efficient data fetching and caching
   - Minimizes network requests with long cache duration

4. **Responsive Design**
   - Works well on both desktop and mobile devices

5. **Data Transformation**
   - Converts numeric day codes to day names
   - Formats time slots for better readability
   - Parses the compact schedule format

## Additional Enhancements

1. **Dark Mode**
   - Add a dark/light mode toggle using Mantine's ColorSchemeProvider

2. **Export Functionality**
   - Add options to export the schedule as PDF or iCal

3. **Filtering Options**
   - Add filters for specific days, courses, or teachers

4. **Batch View**
   - Add a view to see all sections in a specific batch

5. **Teacher Schedule**
   - Add a view to see a specific teacher's schedule

## Deployment

Deploy your Next.js application using Vercel:

```bash
npm install -g vercel
vercel
```

This implementation provides a fast, user-friendly interface for viewing class schedules, with efficient client-side caching to minimize data loading. The application correctly handles classes on all days of the week and presents them in an organized, easy-to-navigate format.
