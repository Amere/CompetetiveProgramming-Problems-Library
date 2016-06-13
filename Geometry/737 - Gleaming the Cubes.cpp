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
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y; }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };

double dist(point p1, point p2) { // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y); }

int insideCircle(point p, point c, double r) { // all double version
    double dx = p.x - c.x, dy = p.y - c.y;
    double Euc = dx * dx + dy * dy, rSq = r * r;             // all double
    return Euc + EPS < rSq ? 0 : abs(Euc-rSq) == EPS ? 1 : 2; } //inside/border/outside

struct vec { double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {} };

/* convert two points to vector */
vec toVec(point a, point b) {       // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y); }
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0; }

struct line { double a, b, c; };



/* get the line from two points */
void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) {              // vertical line is fine
        l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;           // default values
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    } }
bool areParallel(line l1, line l2) {
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }

bool areSame(line l1, line l2) {
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS); }

int main() {
    int n;
    while (true) {
        cin>>n;
        if (n==0) {
            break;
        }
        bool flg = false;
        int startIntersectX=-1,startIntersectY=-1,startIntersectZ=-1,endIntersectX=-1,endIntersectY=-1,endIntersectZ=-1;
        for (int i=0; i<n; i++) {
            int x,y,z,move;
            cin>>x>>y>>z>>move;
            if (startIntersectX==-1) {
                startIntersectX = x;
                endIntersectX = x+move;
                startIntersectY = y;
                endIntersectY = y+move;
                startIntersectZ = z;
                endIntersectZ = z+move;
            }else{
                startIntersectX = max(x,startIntersectX);
                endIntersectX = min(x+move,endIntersectX);
                startIntersectY = max(startIntersectY,y);
                endIntersectY = min(y+move,endIntersectY);
                startIntersectZ = max(z,startIntersectZ);
                endIntersectZ = min(z+move,endIntersectZ);
            }
            if (endIntersectX<=startIntersectX||endIntersectY<=startIntersectY||endIntersectZ<=startIntersectZ) {
                flg = true;
            }
        }
        if (flg) {
            cout<<0<<endl;
        }else{
            cout<<((endIntersectX-startIntersectX)*(endIntersectY-startIntersectY)*(endIntersectZ-startIntersectZ))<<endl;
        }
    }
    return 0;
}
