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
#include <assert.h>
#define PI acos(-1.0);
#define INF 2000000000
#define llINF 2022337203685406
#define EPS 1e-12
#define sz(v)        static_cast<int>((v).size())
#define pb(...)      push_back(__VA_ARGS__)
#define mp(x, y)     make_pair((x), (y))
#define clr(x) memset(x, 0, sizeof(x))
#define clr1(x) memset(x, INF, sizeof(x))
#define dREP(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, v) for(int i=0;i<sz(v);++i)
#define DFS_WHITE -1
#define DFS_BLACK 1
#define DFS_GRAY 2
#define cntBIT(n) __builtin_popcount(n)

int mod  = 1000000007;
using namespace std;
inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> matrix;
typedef map<int, int>::iterator it_type;
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }
int fixMod(int a){
    return (a % mod + mod) % mod;
}
int res[50+5];
int s1,s2;
vi vis;
vector<vi> AdjList;
void dfs(int u){
	if(vis[u]) return;
	vis[u] = 1;
	for(int j =0 ; j<AdjList[u].size(); j++){
		int v = AdjList[u][j];
		dfs(v);
	}
}
int main () {
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(1){
        int V;
        cin>>V;
        if(V==-1) break;
        int E;
        vi powers(V,0);
        AdjList.assign(V,vi());
        for(int i = 0 ; i < V ; i++){
            int power;
            cin>>power;
            powers[i] = power;
            cin>>E;
            for(int j=0;j<E;j++){
                int t;
                cin>>t;
                t--;
                AdjList[i].pb(t);
            }
        }
        vi dist(V, -INF);
        dist[0] = 100;
        for (int i = 0; i < V - 1; i++)
            for (int u = 0; u < V; u++)
                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                    int v = AdjList[u][j];
                    if(dist[u] + powers[v] > 0 && dist[u]+powers[v] > dist[v]){
                       dist[v] = dist[u] + powers[v];
                    }
                }
        bool hasNegativeCycle = false;
        for (int u = 0; u < V; u++)
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                if (dist[u] + powers[v] > 0 && dist[u]+powers[v] > dist[v]){
                	s1 = u;
                	s2 = v;
                    hasNegativeCycle = true;
                }
            }
        bool connected = 0;
        vis.assign(V,0);
        if(hasNegativeCycle){
        	dfs(s1);
        	dfs(s2);
        	connected = vis[V-1];
        }
        if(dist[V-1]>0 || (hasNegativeCycle && connected)){
            cout<<"winnable\n";
        }else{
            cout<<"hopeless\n";
        }
    }

    return 0;
}
