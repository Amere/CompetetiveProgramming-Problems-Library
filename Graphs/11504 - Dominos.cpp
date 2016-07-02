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
#define DFS_GRAY 2
ll mo = 1000000007;

vector<vii> AdjList;
vi ts,dfs_num;
void dfs(int u){
    dfs_num[u] = DFS_BLACK;
    for (int i=0;  i < (int)AdjList[u].size(); i++) {
        ii child = AdjList[u][i];
        if (dfs_num[child.first]==DFS_WHITE)
            dfs(child.first);
    }
    ts.push_back(u);
}
void dfs2(int u){
    dfs_num[u] = DFS_BLACK;
    for (int i=0;  i < (int)AdjList[u].size(); i++) {
        ii child = AdjList[u][i];
        if (dfs_num[child.first]==DFS_WHITE)
            dfs2(child.first);
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while (t--) {
        int V,m;
        cin>>V>>m;
        AdjList.assign(V, vii());
        dfs_num.assign(V, DFS_WHITE);
        ts.clear();
        for (int i=0; i<m; i++) {
            int a,b;
            cin>>a>>b;
            a--,b--;
            AdjList[a].push_back(ii(b,0));
        }
        for (int i=0; i<V; i++) {
            if (dfs_num[i]==DFS_WHITE) {
                dfs(i);
            }
        }
        dfs_num.assign(V, DFS_WHITE);
        int cnt = 0;
        reverse(ts.begin(), ts.end());
        for (int i=0; i<V; i++) {
            if (dfs_num[ts[i]]==DFS_WHITE) {
                cnt++;
                dfs2(ts[i]);
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
