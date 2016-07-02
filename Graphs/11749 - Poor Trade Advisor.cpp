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
#define INF 2147483648
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
vi dfs_num;
ll maxi;

ll dfs(int u){
    dfs_num[u] = DFS_BLACK;
    ll count = 1;
    for (int i=0; i<AdjList[u].size(); i++) {
        ii child = AdjList[u][i];
        if (dfs_num[child.first]==DFS_BLACK || child.second!=maxi) {
            continue;
        }
        count+=dfs(child.first);
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    while (true) {
        cin>>V>>E;
        if (!V&&!E) {
            break;
        }
        maxi = -INF;
        AdjList.assign(V, vii());
        dfs_num.assign(V, -1);
        for (int i=0; i<E; i++) {
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            AdjList[u].push_back(ii(v,w));
            AdjList[v].push_back(ii(u,w));
            maxi = max (maxi,(ll)w);
        }
        ll res = 0;
        for (int i=0; i<V; i++) {
            if (dfs_num[i]==DFS_WHITE) {
                res = max (res , dfs(i));
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
