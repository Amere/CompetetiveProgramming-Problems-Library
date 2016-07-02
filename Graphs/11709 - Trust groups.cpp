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
#define INF 1000000000;
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

vi taken;
priority_queue<ii> pq;
vector<vii> AdjList;
int E,V;

vi S, visited,dfs_num,dfs_low;
int numSCC,dfsNumberCounter;

void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    S.push_back(u);
    visited[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == DFS_WHITE)
            tarjanSCC(v.first);
        if (visited[v.first])
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
    }

    if (dfs_low[u] == dfs_num[u]) {
        ++numSCC;
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            if (u == v) break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    map<string,int> m;
    while (true) {
        cin>>V>>E;
        m.clear();
        if (!E&&!V)break;
        AdjList.assign(V, vii());
        dfs_num.assign(V, DFS_WHITE); dfs_low.assign(V, 0); visited.assign(V, 0);
        dfsNumberCounter = numSCC = 0;
        string s , s1 , s2;
        getline(cin,s);
        for (int i=0; i<V; i++) {
            getline(cin,s);
            m[s] = i;
        }
        for (int i=0; i<E; i++) {
            getline(cin,s1);
            getline(cin,s2);
            int a = m[s1];
            int b = m[s2];
            AdjList[a].push_back(ii(b,0));
        }
        for (int i = 0; i < V; i++)
            if (dfs_num[i] == DFS_WHITE)
                tarjanSCC(i);
        cout<<numSCC<<endl;
    }

    return 0;
}
