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
#define PI 2*acos(0) // important constant; alternative #define PI (2.0 * acos(0.0))
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

struct line { double a, b, c; };
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

// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;            // no intersection
    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else                  p.y = -(l2.a * p.x + l2.c);
    return true; }

double perimeter(double ab, double bc, double ca) {
    return ab + bc + ca; }

double area(double ab, double bc, double ca) {
    // Heron's formula, split sqrt(a * b) into sqrt(a) * sqrt(b); in implementation
    double s = 0.5 * perimeter(ab, bc, ca);
    return sqrt(s) * sqrt(s - ab) * sqrt(s - bc) * sqrt(s - ca); }


double rCircumCircle(double ab, double bc, double ca) {
    return ab * bc * ca / (4.0 * area(ab, bc, ca)); }

int main() {
    double n , m;
    int cc = 0;
    while (true) {
        cc++;
        cin>>n>>m;
        if (n==0&&m==0) {
            break;
        }
        vector<double> v;
        for (int i=0; i<n; i++) {
            for (int j=0;j<m; j++) {
                double t;
                cin>>t;
                v.push_back(t);
            }
        }
        sort(v.begin(), v.end());
        double amount;
        cin>>amount;
        double curHeight=v[0];
        double curVol = 0;
        int flodded = 1;
        for (int i=1; i<v.size(); i++) {
          //  cout<<curHeight<<endl;
           // double temp = curHeight;
            curHeight+=(v[i]-v[i-1]);
            curVol+= (v[i]-v[i-1])*(i*1.0)*10.0*10.0;
            //cout<<vol<<endl;
            if (curVol<=amount) {
                //cout<<curVol<<endl;
                flodded++;
            }else{
               // cout<<curVol;
                curHeight-=(v[i]-v[i-1]);
                curVol-=(v[i]-v[i-1])*(i*1.0)*10.0*10.0;
                double he = (amount-curVol)/(10.0*10.0*i);
                curVol+=(he)*i*1.0*10*10;
                curHeight+=he;
                break;
            }
        }
        if(curVol<amount+EPS){
           // cout<<"Here";
            double he = (amount-curVol)/(10.0*10.0*n*m);
            curHeight+=he;
        }
        printf("Region %d\n",cc);
        printf("Water level is %.2f meters.\n",curHeight);
        printf("%.2f percent of the region is under water.\n\n",((flodded*1.0)/(n*m))*100.00);


    }

    return 0;
}
