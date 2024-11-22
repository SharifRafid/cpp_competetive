#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int x, y;
};

int crossProd(const Point &a, const Point &b, const Point &c)
{
    int dx1 = b.x - a.x, dy1 = b.y - a.y;
    int dx2 = c.x - b.x, dy2 = c.y - b.y;

    return dx1 * dy2 - dy1 * dy2;
}

bool isRectangle(const vector<Point> &points)
{
    return crossProd(points[0], points[1], points[2]) == 0 &&
           crossProd(points[1], points[2], points[3]) == 0 &&
           crossProd(points[2], points[3], points[0]) == 0 &&
           crossProd(points[3], points[0], points[1]) == 0;
}

bool isPointIn(const vector<Point> &points, Point &point)
{
    int cross1 = crossProd(points[0], points[1], point);
    int cross2 = crossProd(points[1], points[2], point);
    int cross3 = crossProd(points[2], points[3], point);
    int cross4 = crossProd(points[3], points[0], point);
    return (cross1 >= 0 && cross2 >= 0 && cross3 >= 0 && cross4 >= 0) || (cross1 <= 0 && cross2 <= 0 && cross3 <= 0 && cross4 <= 0);
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    vector<Point> points(4);

    int i = 4;
    while (i--)
    {
        cin >> points[i].x >> points[i].y;
    }

    Point p;
    cin >> p.x >> p.y;

    if (!isRectangle(points))
    {
        cout << " O>" << endl;
        cout << "<| " << endl;
        cout << "/ >" << endl;
        return 0;
    }

    if (isPointIn(points, p))
    {
        cout << "\\O/" << endl;
        cout << " | " << endl;
        cout << "/ \\" << endl;
    }
    else
    {
        cout << " O>" << endl;
        cout << "<| " << endl;
        cout << "/ >" << endl;
    }

    return 0;
}