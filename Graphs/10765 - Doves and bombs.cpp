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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef map<int, int>::iterator it_type;
#define INF 1000000000
#define llINF 9223372036854775807
#define EPS 1e-9
#define sz(v)        static_cast<int>((v).size())
#define pb(...)      push_back(__VA_ARGS__)
#define mp(x, y)     make_pair((x), (y))
#define clr(x) memset(x, 0, sizeof(x))
#define dREP(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define DFS_WHITE -1
#define DFS_BLACK 1
ll mo = 1000000007;


vi dfs_low,dfs_num,dfs_parent;
vi articulation_vertex;
int dfsNumberCounter = 0, dfsRoot = 0, rootChildren = 0;
vector<vii> AdjList;

void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == DFS_WHITE) {                          // a tree edge
            dfs_parent[v.first] = u;
            if (u == dfsRoot) rootChildren++;  // special case, count children of root
            articulationPointAndBridge(v.first);
            if (dfs_low[v.first] >= dfs_num[u])              // for articulation point
                articulation_vertex[u]++;           // store this information first
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);       // update dfs_low[u]
        }
        else if (v.first != dfs_parent[u])       // a back edge and not direct cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);       // update dfs_low[u]
    }
}
bool cmp(ii a,ii b){
    if (a.second>b.second || a.second<b.second)
        return a.second>b.second;
    return a.first<b.first;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    while (true) {
        cin>>n>>m;
        if (!n&&!m)break;
        articulation_vertex.assign(n, 1);
        dfs_num.assign(n, DFS_WHITE);
        dfs_low.assign(n,0);
        dfs_parent.assign(n, 0);
        dfsNumberCounter=0;
        rootChildren=0;
        dfsRoot=0;
        AdjList.assign(n, vii());
        while (true) {
            int a,b;
            cin>>a>>b;
            if (a==-1&&b==-1)break;
            AdjList[a].push_back(ii(b,0));
            AdjList[b].push_back(ii(a,0));
        }
        articulationPointAndBridge(0);
        articulation_vertex[0] = rootChildren;
        vii results;
        for (int i=0; i<n; i++)
            results.push_back(make_pair(i,articulation_vertex[i]));
        sort(results.begin(), results.end(),cmp);
        for (int i=0; i<m; i++) {
            cout<<results[i].first<<" "<<results[i].second<<endl;
        }
        cout<<endl;
    }
    return 0;
}
