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
point rotate(point p, double theta) {
    double rad = DEG_to_RAD(theta);    // multiply theta with PI / 180.0
    return point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad));
}

int main() {
    double x1,y1,x2,y2;
    while (cin>>x1>>y1>>x2>>y2) {
        double mixx,miyy,xx,yy,x3,x4,y3,y4;
        mixx=(x1+x2)/2.0;
        miyy=(y1+y2)/2.0;
        xx=mixx-x1;
        yy=miyy-y1;
        x3=mixx-yy;
        y3=miyy+xx;
        x4=mixx+yy;
        y4=miyy-xx;
        printf("%.10lf %.10lf %.10lf %.10lf\n",x3,y3,x4,y4);
    }
    return 0;
}
