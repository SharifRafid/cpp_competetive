import json
import re
from datetime import datetime

def parse_schedule_data(data):
    """Parse the schedule data from excel-to-json format into section-based format."""
    # Convert the data to a list if it's not already
    rows = []
    if isinstance(data, dict):
        for key in data:
            if data[key] and any(data[key].values()):  # Only include non-empty rows
                rows.append(data[key])
    elif isinstance(data, list):
        rows = [row for row in data if row and any(row.values())]  # Only include non-empty rows

    # Initialize variables to track the current state
    sections_data = {}
    current_day = None
    current_time_slots = []
    is_time_slot_row = False
    is_header_row = False

    # Day mapping for more compact representation
    day_map = {
        "SATURDAY": 0,
        "SUNDAY": 1,
        "MONDAY": 2,
        "TUESDAY": 3,
        "WEDNESDAY": 4,
        "THURSDAY": 5,
        "FRIDAY": 6
    }

    # Process each row
    for i, row in enumerate(rows):
        # Check if this is a day row
        day_value = row.get("0", "")
        # Convert to uppercase for case-insensitive comparison
        day_value_upper = day_value.upper() if isinstance(day_value, str) else ""
        if day_value_upper in day_map:
            current_day = day_value_upper
            is_time_slot_row = True  # The next row should be a time slot row
            continue

        # Check if this is a time slot row
        if is_time_slot_row:
            # Extract time slots
            current_time_slots = [
                row.get("0", "").strip(),   # 08:30-10:00
                row.get("3", "").strip(),   # 10:00-11:30
                row.get("6", "").strip(),   # 11:30-01:00
                row.get("9", "").strip(),   # 01:00-02:30
                row.get("12", "").strip(),  # 02:30-04:00
                row.get("15", "").strip()   # 04:00-05:30
            ]
            is_time_slot_row = False
            is_header_row = True  # The next row should be a header row (Room, Course, Teacher)
            continue

        # Skip the header row (Room, Course, Teacher)
        if is_header_row:
            is_header_row = False
            continue

        # Skip rows that don't have a valid room or are not class data
        if not day_value or "Effective From" in day_value or "Classes starting with" in day_value:
            continue

        # Process class data for each time slot
        room_base = day_value  # The first column contains the room

        # Process all 6 time slots (columns come in groups of 3: room, course, teacher)
        for slot_idx, col_start in enumerate([0, 3, 6, 9, 12, 15]):
            course_col = str(col_start + 1)
            teacher_col = str(col_start + 2)
            room_col = str(col_start)

            # Skip if course info is missing
            if course_col not in row or not row[course_col]:
                continue

            course_info = row[course_col]
            teacher_info = row.get(teacher_col, "")
            room_info = row.get(room_col, room_base)

            # Extract course code and section using regex
            match = re.match(r"([A-Z]+\s*\d+)\(([^)]+)\)", course_info)
            if match:
                course_code = match.group(1).replace(" ", "")
                section = match.group(2)

                # Create section entry if it doesn't exist
                if section not in sections_data:
                    sections_data[section] = {
                        "c": []  # courses (shortened key name)
                    }

                # Add course data with shortened key names and numeric day
                time_slot = current_time_slots[slot_idx] if slot_idx < len(current_time_slots) else f"Slot {slot_idx+1}"
                sections_data[section]["c"].append([
                    course_code,                # 0: course code
                    day_map[current_day],       # 1: day as number (0-6)
                    time_slot,                  # 2: time slot
                    room_info,                  # 3: room
                    teacher_info                # 4: teacher
                ])

    return sections_data

def optimize_schedule_data(sections_data):
    """Further optimize and structure the data by section."""
    # Day names for reference (0-6)
    day_names = ["SAT", "SUN", "MON", "TUE", "WED", "THU", "FRI"]

    # Function to parse time slot for sorting
    def parse_time_slot(time_slot):
        if not time_slot or "-" not in time_slot:
            return "99:99"  # Default for invalid time slots
        return time_slot.split("-")[0]  # Return start time for sorting

    for section, data in sections_data.items():
        # Sort courses by day and then by time slot
        data["c"].sort(key=lambda x: (
            x[1],  # Sort by day (already numeric 0-6)
            parse_time_slot(x[2])  # Then by time slot start time
        ))

        # Group courses by course code
        course_groups = {}
        for course in data["c"]:
            code = course[0]  # course code is at index 0
            if code not in course_groups:
                course_groups[code] = []
            course_groups[code].append(course)

        # Extract section info
        section_parts = section.split('_')
        batch = section_parts[0] if len(section_parts) > 0 else ""
        sub_section = section_parts[1] if len(section_parts) > 1 else ""

        # Add metadata with minimal array format
        # [batch, sub_section, total_courses, total_classes]
        data["m"] = [batch, sub_section, len(course_groups), len(data["c"])]

        # Create a course summary with ultra-compact structure
        data["s"] = []  # summary
        for code, classes in course_groups.items():
            # Find unique teachers for this course
            teachers = list(set(cls[4] for cls in classes if cls[4]))

            # Create a compact schedule format - just combine day, time, room
            schedule = []
            for cls in classes:
                # Format: "day_num:time:room"
                schedule.append(f"{cls[1]}:{cls[2]}:{cls[3]}")

            # [code, [teachers], class_count, [schedules]]
            data["s"].append([code, teachers, len(classes), schedule])

    return sections_data

def create_searchable_index(sections_data):
    """Create additional indexes for quick searching."""
    # Create course-to-sections index
    course_index = {}
    # Create teacher-to-sections index
    teacher_index = {}
    # Create batch index
    batch_index = {}

    for section, data in sections_data.items():
        # Extract batch from section code (first element of metadata array)
        batch = data["m"][0] if data["m"] and len(data["m"]) > 0 else ""
        if batch and batch not in batch_index:
            batch_index[batch] = [[], set()]  # [sections, courses]
        if batch and section not in batch_index[batch][0]:
            batch_index[batch][0].append(section)

        for course in data["c"]:
            course_code = course[0]  # course code at index 0
            teacher = course[4]      # teacher at index 4

            # Add course to batch courses
            if batch and course_code:
                batch_index[batch][1].add(course_code)

            # Add to course index
            if course_code not in course_index:
                course_index[course_code] = []
            if section not in course_index[course_code]:
                course_index[course_code].append(section)

            # Add to teacher index
            if teacher and teacher not in teacher_index:
                teacher_index[teacher] = []
            if teacher and section not in teacher_index[teacher]:
                teacher_index[teacher].append(section)

    # Sort sections in batch index by batch number and convert course sets to lists
    for batch, data in batch_index.items():
        data[0].sort()  # Sort sections
        data[1] = sorted(list(data[1]))  # Convert course set to sorted list

    # Return minimal structure
    return [course_index, teacher_index, batch_index]  # [c, t, b]

def main():
    # Load the JSON data from the input file
    try:
        with open('xcel/output2.json', 'r') as f:
            input_data = json.load(f)

        print("Successfully loaded input JSON data.")

        # Parse the data to extract sections
        sections_data = parse_schedule_data(input_data)
        print(f"Found {len(sections_data)} different sections in the data.")

        # Further optimize and structure the data
        optimized_data = optimize_schedule_data(sections_data)

        # Create searchable indexes
        indexes = create_searchable_index(optimized_data)

        # Prepare the final output with minimal structure
        # [metadata, sections, indexes]
        final_output = [
            [len(optimized_data), datetime.now().strftime("%Y-%m-%d")],  # metadata [totalSections, date]
            optimized_data,  # sections
            indexes  # indexes
        ]

        # Write the output to a JSON file without indentation to save space
        with open('xcel/class_schedule_by_section.json', 'w') as f:
            json.dump(final_output, f, separators=(',', ':'))  # Remove whitespace

        # Also create a readable version for debugging
        with open('xcel/class_schedule_readable.json', 'w') as f:
            json.dump(final_output, f, indent=2)

        # Create a legend file to document the data structure
        legend = {
            "dataStructure": {
                "root": "[metadata, sections, indexes]",
                "metadata": "[totalSections, date]",
                "sections": {
                    "sectionKey": "Section identifier (e.g., '62_G')",
                    "c": "Array of classes, each class is [courseCode, day, timeSlot, room, teacher]",
                    "m": "Metadata array [batch, subSection, totalCourses, totalClasses]",
                    "s": "Summary array of courses, each is [code, [teachers], classCount, [schedules]]"
                },
                "indexes": "[courseIndex, teacherIndex, batchIndex]",
                "days": "0=SAT, 1=SUN, 2=MON, 3=TUE, 4=WED, 5=THU, 6=FRI"
            }
        }

        with open('xcel/class_schedule_legend.json', 'w') as f:
            json.dump(legend, f, indent=2)

        print(f"Successfully processed {len(optimized_data)} sections!")
        print("Output saved to 'xcel/class_schedule_by_section.json'")
        print("Readable version saved to 'xcel/class_schedule_readable.json'")
        print("Legend file saved to 'xcel/class_schedule_legend.json'")

        # Print sample of the first section (for verification)
        if optimized_data:
            first_section = list(optimized_data.keys())[0]
            print(f"\nSample data for section {first_section}:")
            print(f"  Total courses: {optimized_data[first_section]['m'][2]}")
            print(f"  Total classes: {optimized_data[first_section]['m'][3]}")
            if optimized_data[first_section]['c']:
                print(f"  First class: {optimized_data[first_section]['c'][0]}")

    except FileNotFoundError:
        print("Error: Input file 'xcel/output2.json' not found.")
    except json.JSONDecodeError:
        print("Error: The input file is not valid JSON.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    main()