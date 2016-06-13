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
    int t;
    cin>>t;
    while (t--) {

        int n;
        cin>>n;
        vector<pair<pair<point,point>, double>> v;
        vector<point> startE;
        double maxY = -INF;
        for (int i=0; i<n; i++) {
            double x,y,x1,y1,p;
            cin>>x>>y>>x1>>y1>>p;
            v.push_back(make_pair(make_pair(point(x,y), point(x1,y1)), p));
            startE.push_back(point(x, y));
            startE.push_back(point(x1,y1));
            maxY = max(maxY,max(y,y1));
        }

        sort(startE.begin(), startE.end());

        cout<<startE.size()+1<<endl;
        printf("-inf %.3f %.3f\n",startE[0].x,(double)1);
        for (int i=0; i<startE.size()-1;i++) {
            point x = startE[i];
            point y = startE[i+1];
            double res = (double)1;

            for (int j=0; j<v.size(); j++) {
                bool r = doIntersect(point(x.x+0.001, maxY),point(x.x+0.001, 0), v[j].first.first, v[j].first.second);
                if (r) {
                    res*=v[j].second;
                }
            }

            printf("%.3f %.3f %.3f\n",x.x,y.x,res);
        }
        printf("%.3f +inf %.3f\n",startE[startE.size()-1].x,(double)1);


        if (t) {
            cout<<endl;
        }
    }

    return 0;
}
