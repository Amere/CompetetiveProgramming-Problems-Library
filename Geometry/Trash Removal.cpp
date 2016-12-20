
#include <map>
#include <unordered_map>
#include <set>
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
#include <bitset>
#define amora cout<<"amora l fshee5 :D"<<endl;
#define PI acos(-1.0)
#define INF 1000000000
#define llINF 9223372036854775807
#define EPS 1e-9
#define sz(v)        static_cast<int>((v).size())
#define pb(...)      push_back(__VA_ARGS__)
#define mp(x, y)     make_pair((x), (y))
#define clr(x) memset(x, 0, sizeof(x))
#define clr1(x) memset(x, INF, sizeof(x))
#define dREP(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define DFS_WHITE -1
#define DFS_BLACK 1
#define DFS_GRAY 2
#define cntBIT(n) __builtin_popcount(n)
#define NOT(x)    (1^(x))
#define toLowerCase(s)  transform(s.begin(),s.end(),s.begin(),::tolower)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef map<int, int>::iterator it_type;
int mod  = 1000000007;
inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
inline ll toll(string s){ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }


struct point { double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y; }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };
struct vec { double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {} };
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y); }
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0; }
bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }
double dist(point p1, point p2) {     return hypot(p1.x - p2.x, p1.y - p2.y); }
point pivot;
bool angleCmp(point a, point b) {
    if (collinear(pivot, a, b))
        return dist(pivot, a) < dist(pivot, b);
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; }

vector<point> CH(vector<point> P) {
    int i, j, n = (int)P.size();
    if (n <= 3) {
        if (!(P[0] == P[n-1])) P.push_back(P[0]);
        return P;
    }
    int P0 = 0;
    for (i = 1; i < n; i++)
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;

    point temp = P[0]; P[0] = P[P0]; P[P0] = temp;

    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp);
    vector<point> S;
    S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);
    i = 2;
    while (i < n) {
        j = (int)S.size()-1;
        if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);
        else S.pop_back(); }
    return S; }

vec scale(vec v, double s) {
    return vec(v.x * s, v.y * s); }


point translate(point p, vec v) {

    return point(p.x + v.x , p.y + v.y); }
double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
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
double distToLine(point p, point a, point b, point &c) {
    // formula: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));                  // translate a to c
    return dist(p, c); }

int main (){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    int tC = 0;
    while (1) {
        cin>>n;
        if (!n) {
            break;
        }
        vector<point> v;
        for (int i = 0; i<n; i++) {
            int x,y;
            cin>>x>>y;
            v.pb(point(x,y));
        }
        v.pb(v[0]);
        vector<point> convexH = CH(v);
        double finalRes = INF;

        for (int i=0; i<(int)convexH.size()-1; i++) {
            double curRes = 0;
            for (int j = 0; j<(int)convexH.size() - 1; j++) {
                if (i == j || i+1 == j) {
                    continue;
                }
                point p;
                curRes = max(curRes,distToLine(convexH[j], convexH[i], convexH[i+1], p));
            }
            finalRes = min(finalRes,curRes);
        }
        printf("Case %d: %.2f\n",++tC,finalRes);
    }
    return 0;
}
