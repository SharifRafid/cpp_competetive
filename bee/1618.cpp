#include<bits/stdc++.h>

using namespace std;

struct Point {
	int x, y;
	Point () {
		this->x = 0;
		this->y = 0;
	}	
	Point (int x, int y) {
		this->x = x;
		this->y = y;
	}	
	bool operator ==(const Point& p) {
		return (this->x == p.x and this->y == p.y);
	}
	void operator -=(const Point& p) {
		this->x -= p.x;
		this->y -= p.y;
	}
	Point operator -(const Point& p) const {
		Point q;
		q.x = this->x - p.x;
		q.y = this->y - p.y;
		return q;
	}
	long long operator *(const Point& p) const {
		return 1LL * x * p.y - 1LL * y * p.x;
	}
	bool isInside(Point& a, Point& b) const { // if p is inside segment a-b
		if ((a - *this) * (b - *this) != 0) return false;
		bool d1 = this->x >= min(a.x, b.x) and this->x <= max(a.x, b.x); 
		bool d2 = this->y >= min(a.y, b.y) and this->y <= max(a.y, b.y);
		return d1 and d2;
	}
	bool rayIntersect(Point a, Point b) {
		Point q(this->x, INT32_MAX);	// if p-q ray intersects segment a-b
		for (int rep = 0; rep < 2; ++rep) {
			if ((a - *this) * (q - *this) <= 0 and (b - *this) * (q - *this) > 0 and (a - *this) * (b - *this) < 0) {
				return true;
			}
			swap(a, b);
		}
		return false;
	}
	friend istream& operator >>(istream& cin, Point& p) {  
		cin >> p.x >> p.y;
		return cin;
	}
	friend ostream& operator <<(ostream& cout, const Point& p) {
		cout << p.x << " " << p.y;
		return cout;
	}
};
 
bool isCollinear(Point a, Point b, Point c, Point d) {
	return ((b - a) * (c - a) == 0 and (c - a) * (d - a) == 0);
}

void makeSerial(vector<Point>& v) {
    auto checkOrientation = [](const Point& a, const Point& b, const Point& c, const Point& d) {
        long long d1 = (b - a) * (c - a);
        long long d2 = (d - a) * (c - a);
        return d1 * d2 < 0;
    };
    vector<Point> ret;
    if (checkOrientation(v[0], v[1], v[2], v[3])) {
        ret = {v[2], v[0], v[3], v[1]};
        if ((v[3] - v[0]) * (v[1] - v[0]) < 0) swap(ret[0], ret[2]);
    } 
    else if (checkOrientation(v[0], v[1], v[3], v[2])) {
        ret = {v[1], v[0], v[3], v[2]};
        if ((v[2] - v[0]) * (v[3] - v[0]) < 0) swap(ret[0], ret[2]);
    } 
    else if (checkOrientation(v[0], v[2], v[3], v[1])) {
        ret = {v[1], v[0], v[2], v[3]};
        if ((v[3] - v[0]) * (v[2] - v[0]) < 0) swap(ret[0], ret[2]);
    }
    v = ret;
}

void solve(){
    Point a,b,c,d,r;
    cin >> a >> b >> c >> d >> r;

}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}