#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int x, y;
};

float getArea(const vector<Point> &points)
{
    float area = 0;
    for (size_t t = 0; t < points.size(); t++)
    {
        size_t j = (t + 1) % points.size();
        area += ((points[t].x * points[j].y) - (points[j].x * points[t].y));
    }
    return abs(area) / 2.0;
}

void solve()
{
    vector<Point> points(4);
    for (size_t t = 0; t < points.size(); t++)
    {
        cin >> points[t].x >> points[t].y;
    }
    Point centeroid = {0, 0};
    for (const auto &p : points)
    {
        centeroid.x += p.x;
        centeroid.y += p.y;
    }
    centeroid.x /= points.size();
    centeroid.y /= points.size();

    sort(points.begin(), points.end(), [&centeroid](const Point &a, const Point &b)
         {
        double angleA = atan2(a.y - centeroid.y, a.x-centeroid.x);
        double angleB = atan2(b.y - centeroid.y, b.x-centeroid.x);
        return angleA < angleB; });

    Point p;
    cin >> p.x >> p.y;
    float totalArea = getArea(points);
    
    if (totalArea == 0)
    {
        cout << " O>" << endl;
        cout << "<| " << endl;
        cout << "/ >" << endl;
        return;
    }

    float area1 = getArea({points[0], points[1], p});
    float area2 = getArea({points[1], points[2], p});
    float area3 = getArea({points[2], points[3], p});
    float area4 = getArea({points[3], points[0], p});

    if (area1 == 0 || area2 == 0 || area3 == 0 || area4 == 0)
    {
        cout << "\\O/" << endl;
        cout << " | " << endl;
        cout << "/ \\" << endl;
        return;
    }

    float totalAreaWithPoint = area1 +
                               area2 +
                               area3 +
                               area4;

    if (abs(totalAreaWithPoint) - abs(totalArea) > 1e-6)
    {
        cout << " O>" << endl;
        cout << "<| " << endl;
        cout << "/ >" << endl;
    }
    else
    {
        cout << "\\O/" << endl;
        cout << " | " << endl;
        cout << "/ \\" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}