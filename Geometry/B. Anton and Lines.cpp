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

typedef std::pair<point, int> myPair_type;
struct mypair_comp{
    bool operator()(myPair_type const& lhs, myPair_type const& rhs){
        if(fabs(lhs.first.y-rhs.first.y) <EPS) return lhs.second<rhs.second;
        else return lhs.first.y+EPS<rhs.first.y;
    }
};

/* convert two points to vector */
vec toVec(point a, point b) {       // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y); }
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }


struct line { double a, b, c;
    line(){a=0,b=0,c=0;}
    line(double _a,double _b,double _c) : a(_a),b(_b),c(_c){}
};

bool areParallel(line l1, line l2) {
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }

bool areSame(line l1, line l2) {
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS); }

void pointSlopeToLine(point p, double m, line &l) {
    l.a = -m;
    l.b = 1;
    l.c = -((l.a * p.x) + (l.b * p.y)); }

bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;            // no intersection
    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else                  p.y = -(l2.a * p.x + l2.c);
    return true; }
void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) {              // vertical line is fine
        l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;           // default values
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    } }


int main() {

    int n;
    cin>>n;
    vector<line> v;
    vector<pair<point, int>> x1Inters;
    vector<pair<point, int>> x2Inters;
    int x1,x2;
    cin>>x1>>x2;

    for (int i=0; i<n; i++) {
        int m,c;
        cin>>m>>c;
        line l;
        pointSlopeToLine(point(0,c), m, l);
        v.push_back(l);
        point p1,p2;
        line l1,l2;
        pointsToLine(point(x1, 0), point(x1,x1), l1);
        pointsToLine(point(x2, 0), point(x2,x2), l2);

        if (areIntersect(l, l1, p1)) {
            x1Inters.push_back(make_pair(p1, i));
        }
        if (areIntersect(l, l2, p2)) {
            x2Inters.push_back(make_pair(p2, i));
        }
    }

    sort(x1Inters.begin(), x1Inters.end(),mypair_comp());
    sort(x2Inters.begin(), x2Inters.end(),mypair_comp());

    bool flg = false;
    for (int i=0; i<x1Inters.size(); i++) {
        point p;
        bool b = areIntersect(v[x1Inters[i].second], v[x2Inters[i].second], p);
        if (b) {
            b = !(fabs(p.x-x1)<EPS) && !(fabs(p.x-x2)<EPS);
        }else{
            b = false;
        }
        if (x1Inters[i].second!=x2Inters[i].second && b) {
            flg=true;
            break;
        }
    }
    if (flg) {
        cout<<"YES";
    }else{
        cout<<"NO";
    }

    return 0;
}
