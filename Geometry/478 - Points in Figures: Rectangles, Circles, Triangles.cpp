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

int main() {
    char c;
    vector<pair<int,pair<point, point>>> rectangles;
    vector<pair<int,pair<point, double>>> circles;
    vector<pair<int,pair<point, pair<point, point>>>> triangles;
    int count=0;
    while (true) {
        count++;
        cin>>c;
        if (c=='*') {
            break;
        }
        if (c=='r') {
            double x,y,xx,yy;
            cin>>x>>y>>xx>>yy;
            rectangles.push_back(make_pair(count, make_pair(point(x,y), point(xx, yy))));
        }else{
            if (c=='c') {
                double x,y,r;
                cin>>x>>y>>r;
                circles.push_back(make_pair(count, make_pair(point(x, y), r)));
            }else{
                if (c=='t') {
                    double x,y,xx,yy,xxx,yyy;
                    cin>>x>>y>>xx>>yy>>xxx>>yyy;
                    triangles.push_back(make_pair(count, make_pair(point(x, y), make_pair(point(xx, yy), point(xxx, yyy)))));
                }
            }
        }
    }
    vector<point> points;
    while (true) {
        double x,y;
        cin>>x>>y;
        if (fabs(x-9999.9)<EPS&&fabs(y-9999.9)<EPS) {
            break;
        }
        points.push_back(point(x,y));
    }
    for (int i=0; i<points.size(); i++) {
        vector<int> results;
        for (int j=0;j<rectangles.size() ; j++) {
            if (inside_rectangle(rectangles[j].second.first,rectangles[j].second.second,points[i])) {
                results.push_back(rectangles[j].first);
            }
        }
        for (int j=0;j<triangles.size() ; j++) {
            if (inside_triangle(triangles[j].second.first, triangles[j].second.second.first, triangles[j].second.second.second,points[i])) {
                results.push_back(triangles[j].first);
            }
        }
        for (int j=0;j<circles.size() ; j++) {
            if (insideCircle(points[i], circles[j].second.first, circles[j].second.second)==0) {
                results.push_back(circles[j].first);
            }
        }
        if (results.size()==0) {
            printf("Point %d is not contained in any figure\n",i+1);
        }else{
            sort(results.begin(), results.end());
            for (int j=0;j<results.size() ; j++) {
                printf("Point %d is contained in figure %d\n",i+1,results[j]);
            }
        }
    }

    return 0;
}
