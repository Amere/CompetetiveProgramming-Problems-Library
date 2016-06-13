#include <set>
#include <map>
#include <list>
#include <bitset>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <sstream>
#include <fstream>
#include <iomanip>
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))
using namespace std;
#define DFS_WHITE -1
#define DFS_BLACK 1
#define DFS_GRAY 2
#define REP(i, a, b) \
for (int i = int(a); i < int(b); i++)
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef map<int, int>::iterator it_type;
typedef long long ll;
typedef map<int, int> mii;
typedef std::pair<double, int> myPair_type;
struct mypair_comp{
    bool operator()(myPair_type const& lhs, myPair_type const& rhs){
        return lhs.first +EPS < rhs.first;
    }
};
double DEG_to_RAD(double d) { return d * PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }
struct point { double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}     //Point p(0,6);
    bool operator < (point other) const {
        if (fabs(y - other.y) > EPS)
            return y < other.y;
        return x < other.x; }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };

double dist(point p1, point p2) { // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y); }

struct line { double a, b, c; };

struct segment { point a, b;
 segment(point _x, point _y) : a(_x), b(_y) {}
    bool operator < (segment other) const {
        if (fabs(max(a.y,b.y) - max(other.a.y,other.b.y)) > EPS)
            return max(a.y,b.y) < max(other.a.y,other.b.y);
        return max(a.x,b.x) < max(other.a.x,other.b.x); }
};



/* get the line from two points */
void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) {              // vertical line is fine
        l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;           // default values
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    } }
bool onSegment(point p, point q, point r)
{
    if (q.x <EPS+ max(p.x, r.x) && q.x +EPS== min(p.x, r.x) &&
        q.y <EPS+ max(p.y, r.y) && q.y +EPS== min(p.y, r.y))
        return true;

    return false;
}

int orientation(point p, point q, point r)
{
    double val = (q.y - p.y) * (r.x - q.x) -
    (q.x - p.x) * (r.y - q.y);

    if (abs(val) < EPS) return 0;  // colinear

    return (val > EPS)? 1: 2; // clock or counterclock wise
}
bool doIntersect(point p1, point q1, point p2, point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
    return false; // Doesn't fall in any of the above cases
}

int main() {

    int t;
    cin>>t;
    while (t--) {
        vector<segment> segs;
        int n;
        cin>>n;
        for (int i=0; i<n; i++) {
            double x,y,x1,y1;
            cin>>x>>y>>x1>>y1;
            segs.push_back(segment(point(x,y),point(x1,y1)));
        }
        sort(segs.rbegin(),segs.rend());
        vector<point> srcs;
        int m;
        cin>>m;
        for (int i=0; i<m; i++) {
            int x,y;
            cin>>x>>y;
            srcs.push_back(point(x,y));
        }
        for (int i=0; i<m; i++) {
            segment se(srcs[i], point(srcs[i].x,0));
            for (int j=0; j<n; j++) {
                if (doIntersect(segs[j].a, segs[j].b, se.a, se.b)) {
                    if (segs[j].a.y<segs[j].b.y) {
                        se.a=segs[j].a;
                    }else{
                        se.a=segs[j].b;
                    }
                }
            }
            srcs[i]=se.a;
        }
        for (int i=0; i<m; i++) {
            cout<<(int)srcs[i].x<<endl;
        }
        if (t) {
            cout<<endl;
        }
    }

    return 0;
}
