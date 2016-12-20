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

struct crane{
    int x,y,r;
    crane(int x,int y,int r):x(x),y(y),r(r){}
};
ll pow(ll x) {return x*x;}
int n;
bool check[20][20];
bool doInter(crane p1,crane p2){
    if (pow(p1.r+p2.r) >= (pow(p1.y-p2.y)+pow(p1.x-p2.x))) {
        return true;
    }else return false;
}
ll maxi;
bool vis[20];
vector<crane> v;
ll solve(int idx){
    ll res = 0;
    if (!vis[idx]) {
        vis[idx] = 1;
        res = v[idx].r*v[idx].r;
        REP(i, 0, n){
            if (check[idx][i]) {
                vis[i] = 1;
            }
        }
        REP(i, 0, n){
            if (!vis[i]) {
                res+=solve(i);
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while (t--) {

        clr(vis);
        cin>>n;
        v.clear();
        REP(i, 0, n){
            int x,y,r;
            cin>>x>>y>>r;
            v.push_back(crane(x,y,r));
        }
        REP(i, 0, n)
            REP(j, 0, n)
                    check[i][j] = doInter(v[i], v[j]);

        maxi = 0;
        REP(i, 0, n) {
            maxi = max(solve(i),maxi);
            clr(vis);
        }
        cout<<maxi<<endl;
    }

    return 0;
}
