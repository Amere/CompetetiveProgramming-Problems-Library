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

double dist(point p1, point p2) { // hypot(xx, yy) returns sqrt(xx * xx + yy * yy)
    return hypot(p1.x - p2.x, p1.y - p2.y); }

struct vec { double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {} };

/* convert two points to vector */
vec toVec(point a, point b) {       // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y); }


double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }


bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0; }

/* Colinear test */
// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }


point pivot;
bool angleCmp(point a, point b) {                 // angle-sorting function
    if (collinear(pivot, a, b))                               // special case
        return dist(pivot, a) < dist(pivot, b);    // check which one is closer
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; }   // compare two angles

vector<point> CH(vector<point> P) {   // the content of P may be reshuffled
    int i, j, n = (int)P.size();
    if (n <= 3) {
        if (!(P[0] == P[n-1])) P.push_back(P[0]); // safeguard from corner case
        return P;                           // special case, the CH is P itself
    }
    // first, find P0 = point with lowest Y and if tie: rightmost X
    int P0 = 0;
    for (i = 1; i < n; i++)
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;

    point temp = P[0]; P[0] = P[P0]; P[P0] = temp;    // swap P[P0] with P[0]

    // second, sort points by angle w.r.t. pivot P0
    pivot = P[0];                    // use this global variable as reference
    sort(++P.begin(), P.end(), angleCmp);              // we do not sort P[0]

    // third, the ccw tests
    vector<point> S;
    S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);   // initial S
    i = 2;                                         // then, we check the rest
    while (i < n) {           // note: N must be >= 3 for this method to work
        j = (int)S.size()-1;
        if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);  // left turn, accept
        else S.pop_back(); }   // or pop the top of S until we have a left turn
    return S; }                                          // return the result
double area(const vector<point> &P) {
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)P.size()-1; i++) {
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0; }



int main() {

    int n;
    int count = 0;
    while (true) {
        cin>>n;
        if (n==0) {
            break;
        }
        count++;
        vector<point> pol;
        for (int i=0; i<n; i++) {
            double t,tt;
            cin>>t>>tt;
            pol.push_back(point(t,tt));
        }
        pol.push_back(pol[0]);
        double area1 = area(pol);
        vector<point> hull = CH(pol);
        double area2 = area(hull);
        double area3 = area2-area1;
        printf("Tile #%d\nWasted Space = %.2f ",count,(area3/area2)*100.0);
        cout<<"%\n\n";
    }
    return 0;
}
