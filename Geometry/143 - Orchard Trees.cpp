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
#define EPS 1e-15
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
struct vec { double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {} };
struct point { double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}     //Point p(0,6);
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y; }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };



/* convert two points to vector */
vec toVec(point a, point b) {       // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y); }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r))> 0; }


bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }

bool onSegment(point p, point q, point r)
{
    if (q.x <EPS+ max(p.x, r.x) && q.x +EPS> min(p.x, r.x) &&
        q.y <EPS+ max(p.y, r.y) && q.y +EPS> min(p.y, r.y))
        return true;

    return false;
}

bool inside_triangle(point x,point y,point z,point p){
    if (ccw(x, y, p)&&ccw(y, z, p)&&ccw(z, x, p)) {
        return true;
    }else{
        if ((onSegment(x, p, y)&&collinear(x, y, p))||(onSegment(x,p,z)&&collinear(x, z, p))||(onSegment(y, p, z)&&collinear(y, z, p))) {
            return true;
        }
        return false;
    }
}


int main() {
    while (true) {
        int count = 0;
        double x,y,x1,y1,x2,y2;
        scanf("%lf %lf %lf %lf %lf %lf",&x,&y,&x1,&y1,&x2,&y2);
        if (x==0&&y==0&&x1==0&&y1==0&&x2==0&&y2==0) {
            break;
        }
        //cout<<x<<" "<<y<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    for (int i=1; i<100; i++) {
        for (int j=1; j<100; j++) {
            if ((inside_triangle(point(x,y), point(x1,y1), point(x2,y2), point(i,j)))||(inside_triangle(point(x1,y1), point(x,y), point(x2,y2), point(i,j)))||(inside_triangle(point(x,y), point(x2,y2), point(x1,y1), point(i,j)))||(inside_triangle(point(x1,y1), point(x2,y2), point(x,y), point(i,j)))||(inside_triangle(point(x2,y2), point(x1,y1), point(x,y), point(i,j)))||(inside_triangle(point(x2,y2), point(x,y), point(x1,y1), point(i,j)))) {
                count++;
            }
        }
    }
        printf("%d",count);
    }
    return 0;
}
