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
#define llINF 9223372036854775807
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
typedef std::pair<int, int> myPair_type;
struct mypair_comp{
    bool operator()(myPair_type const& lhs, myPair_type const& rhs){
        return lhs.first < rhs.first;
    }
};
struct point { double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}     //Point p(0,6);
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y; }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };
struct vec { double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {} };

/* convert two points to vector */
vec toVec(point a, point b) {       // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y); }
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
bool onSegment(point p, point q, point r)
{
    if (q.x <EPS+ max(p.x, r.x) && q.x +EPS> min(p.x, r.x) &&
        q.y <EPS+ max(p.y, r.y) && q.y +EPS> min(p.y, r.y))
        return true;

    return false;
}
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
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

        int n;
        cin>>n;
        for (int i=1; i<=n; i++) {
            int x,y,x1,y1;
            cin>>x>>y>>x1>>y1;
            int xx,yy,xx1,yy1;
            cin>>xx>>yy>>xx1>>yy1;
            int side1 = 0, side2 = 0;
            side1 = max(side1,(min(x1,xx1))-(max(x,xx)));
            side2 = max(side2,(min(y1,yy1))-(max(y,yy)));

            int ar1,ar2,ar3;
            ar1 = side1*side2;
            ar2 = (((x1-x)*(y1-y))-ar1)+(((xx1-xx)*(yy1-yy))-ar1);
            ar3 = (100*100)-ar2-ar1;
            printf("Night %d: %d %d %d\n",i,ar1,ar2,ar3);
        }

    return 0;
}
