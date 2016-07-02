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
using namespace std;
inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef map<int, int>::iterator it_type;
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
ll mo = 1000000007;


vector<vii> AdjList;
int E,V;
int res[1000+1][1000+1];
vi dfs_low,dfs_num,dfs_parent;       // additional information for articulation points/bridges/SCCs
int dfsNumberCounter, dfsRoot, rootChildren;

void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == DFS_WHITE) {                          // a tree edge
            dfs_parent[v.first] = u;
            articulationPointAndBridge(v.first);
            if (dfs_low[v.first] > dfs_num[u]){
                res[u][v.first] = res[v.first][u] = 1;
            }else{
                if(!res[v.first][u])res[u][v.first]=1;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);       // update dfs_low[u]
        }
        else if (v.first != dfs_parent[u]) {      // a back edge and not direct cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);       // update dfs_low[u]
            if(!res[v.first][u])res[u][v.first]=1;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int cas = 0;
    while (true) {
        cas ++;
        cin>>V>>E;
        if (!V&&!E)
            break;
        clr(res);
        AdjList.assign(V, vii());
        dfs_num.assign(V, DFS_WHITE);
        dfs_low.assign(V, 0);
        dfs_parent.assign(V, 0);
        for (int i=0; i<E; i++) {
            int a,b;
            cin>>a>>b;
            a--,b--;
            AdjList[a].push_back(ii(b,0));
            AdjList[b].push_back(ii(a,0));
        }
        dfsNumberCounter=0;
        dfsRoot = 0;
        cout<<cas<<"\n\n";
        articulationPointAndBridge(0);
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                if(res[i][j])
                    cout<<i+1<<" "<<j+1<<'\n';
        cout<<"#"<<endl;
    }

    return 0;
}
