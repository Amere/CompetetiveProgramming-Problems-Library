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

struct point { double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y; }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };

struct tree{
    vector<point> v;
    tree(vector<point> v):v(v){}
};

vector<vi> AdjList;
vector<tree> trees;
vector<point> doctors;
int n,m,k,d,x,y,b;

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y); }
bool checkTree(tree t1,tree t2){
    for (int i=0; i<t1.v.size(); i++) {
        point p1 = t1.v[i];
        for (int j=0; j<t2.v.size(); j++) {
            point p2 = t2.v[j];
            if (dist(p1, p2) < k+EPS) {
                return true;
            }
        }
    }
    return false;
}
bool checkDoc(tree t1){
    for (int i=0; i<t1.v.size(); i++) {
        point p1 = t1.v[i];
        for (int j=0; j<doctors.size(); j++) {
            point p2 = doctors[j];
            if (dist(p1, p2) < d+EPS) {
                return true;
            }
        }
    }
    return false;
}

bool vis[100+2];
bool res;
void dfs(int idx){
    if (vis[idx]) {
        return;
    }
    res|=checkDoc(trees[idx]);
    vis[idx] = 1;
    for (int i=0; i<AdjList[idx].size(); i++) {
        dfs(AdjList[idx][i]);
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while (t--) {
        cin>>n>>m>>k>>d;
        clr(vis);
        res = false;
        doctors.clear();
        AdjList.clear();
        trees.clear();
        for (int i=0; i<m; i++) {
            cin>>x>>y;
            doctors.push_back(point(x,y));
        }
        for (int i=0; i<n; i++) {
            cin>>b;
            vector<point> t;
            while (b--) {
                cin>>x>>y;
                t.push_back(point(x,y));
            }
            trees.push_back(tree(t));
        }
        AdjList.assign(n, vi());
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i!=j) {
                    if (checkTree(trees[i], trees[j])) {
                        AdjList[i].push_back(j);
                    }
                }
            }
        }
        dfs(0);
        if (res) {
            cout<<"Tree can be saved :)\n";
        }else{
            cout<<"Tree can't be saved :(\n";
        }
    }
    return 0;
}
