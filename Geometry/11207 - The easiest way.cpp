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

bool inside_triangle(point x,point y,point z,point p){
    if ((ccw(x, y, p)&&ccw(y, z, p)&&ccw(z, x, p))||(!ccw(x, y, p)&&!ccw(y, z, p)&&!ccw(z, x, p))) {
        return true;
    }else{
        return false;
    }
}
bool inside_rectangle(point upLeft,point downRight,point p){
    return p.x>upLeft.x&&p.x<downRight.x&&p.y<upLeft.y&&p.y>downRight.y;
}
double perimeter(double ab, double bc, double ca) {
    return ab + bc + ca; }

double perimeter(point a, point b, point c) {
    return dist(a, b) + dist(b, c) + dist(c, a); }

double area(double ab, double bc, double ca) {
    // Heron's formula, split sqrt(a * b) into sqrt(a) * sqrt(b); in implementation
    double s = 0.5 * perimeter(ab, bc, ca);
    return sqrt(s) * sqrt(s - ab) * sqrt(s - bc) * sqrt(s - ca); }

int main() {
    int n;
    while (true) {
        double maximum = -INF;
        int idx = -1;
        cin>>n;
        if (n==0) {
            break;
        }
        for (int i=0; i<n; i++) {
            double w,h;
            cin>>w>>h;
            double we = max(w,h);
            double we1 = min(w,h)/2;
            we/=4.0;
            if (we>EPS+min(w,h)) {
                w=min(w,h);
            }else{
                w=we;
            }
            w = max(w,we1);
//            double bird = 0.0;
//            bird += area(w/2,w/2,((sqrt(2)*w)/2.0));
//            bird += 0.5 * (sqrt(2)*w/2.0+sqrt(2)*w/4.0)*(sqrt(2)*w/4.0);
            if (w>maximum+EPS) {
                maximum = w;
                idx = i+1;
            }
        }
        cout<<idx<<endl;
    }

    return 0;
}
