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

point rotateRel(point p1,point p2,double theta){
    double rad = DEG_to_RAD(theta);
    return point((p1.x-p2.x) * cos(rad) - (p1.y-p2.y) * sin(rad) + p2.x,
                 (p1.x-p2.x) * sin(rad) + (p1.y-p2.y) * cos(rad) + p2.y);
}



int circumCircle(point p1, point p2, point p3, point &ctr, double &r){
    double a = p2.x - p1.x, b = p2.y - p1.y;
    double c = p3.x - p1.x, d = p3.y - p1.y;
    double e = a * (p1.x + p2.x) + b * (p1.y + p2.y);
    double f = c * (p1.x + p3.x) + d * (p1.y + p3.y);
    double g = 2.0 * (a * (p3.y - p2.y) - b * (p3.x - p2.x));
    if (fabs(g) < EPS) return 0;

    ctr.x = (d*e - b*f) / g;
    ctr.y = (a*f - c*e) / g;
    r = dist(p1, ctr);  // r = distance from center to 1 of the 3 points
    return 1; }


int main() {
    int n;
    int count=0;
    while (true) {
        count++;
        cin>>n;
        if (!n) {
            break;
        }
        double x,y,x1,y1,x2,y2;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        point center;
        double r;
        circumCircle(point(x,y), point(x1,y1), point(x2,y2), center, r);
        vector<point> pol;
        pol.push_back(point(x,y));
        double theta = 360.0/(1.0*n);
        for (int i=1; i<n; i++) {
            pol.push_back(rotateRel(pol[i-1],center,theta));
        }
        point maxX,maxY,minX,minY;
        maxX.x=-INF;
        maxY.y=-INF;
        minX.x=INF;
        minY.y=INF;
        for (int i=0; i<n; i++) {
            if (pol[i].x>maxX.x) {
                maxX=pol[i];
            }
            if (pol[i].x<minX.x) {
                minX=pol[i];
            }
            if (pol[i].y>maxY.y) {
                maxY=pol[i];
            }
            if (pol[i].y<minY.y) {
                minY=pol[i];
            }
        }
        minX.y=maxX.y;
        maxY.x=minY.x;
        printf("Polygon %d: %.3f\n",count,dist(maxX,minX)*dist(maxY,minY));
    }
    return 0;
}
