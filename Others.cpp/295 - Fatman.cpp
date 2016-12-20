#include <map>
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
#define PI acos(-1.0);
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
int mod  = 1000000007;
using namespace std;
inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef map<int, int>::iterator it_type;
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }
void printV(vector<int> v){
    for (int i=0; i<v.size(); i++) {
        if (i) {
            cout<<" "<<v[i];
        }else cout<<v[i];
    }
}
int fixMod(int a){
    return (a % mod + mod) % mod;
}


class UnionFind {                                              // OOP style
private:
    vi p, rank, setSize;                       // remember: vi is vector<int>
    int numSets;
public:
    UnionFind(int N) {
        setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
        p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) { numSets--;
            int x = findSet(i), y = findSet(j);
            // rank is used to keep the tree short
            if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
            else                   { p[x] = y; setSize[y] += setSize[x];
                if (rank[x] == rank[y]) rank[y]++; } } }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

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

bool doInter(point p1,point p2,double l){
    return dist(p1, p2)<l+EPS;
}

vector<point> points;
int X,Y,n;


bool f(double l){
    UnionFind UF(n+2);

    REP (i, 0, n) {
        if(points[i].y < l + EPS)
            UF.unionSet(n+1, i);
        if(X - points[i].y < l + EPS)
            UF.unionSet(n, i);
        REP(j, i+1, n){
            if (doInter(points[i], points[j],l)) {
                UF.unionSet(i, j);
            }
        }
    }
    return UF.isSameSet(n, n+1);
}



double BSdouble(double start,double end){
    double maxL = 0;
    REP(i, 0, 80){
        double mid = start + (end-start)/2.0;
        if(!f(mid)) {
            start = mid;
          //  cout<<mid<<endl;
            maxL = max(maxL,mid);
        }
        else{
            end = mid;
        }
    }
    return maxL;
}



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    int tC = 0;
    while (t--) {
        tC++;
        points.clear();
        cin>>Y>>X;
        cin>>n;
        REP(i, 0, n){
            double x,y;
            cin>>x>>y;
            points.push_back(point(x,y));
        }
        sort(points.begin(), points.end());
        printf("Maximum size in test case %d is %.4lf.\n",tC,BSdouble(0,X));
    }
    return 0;
}
