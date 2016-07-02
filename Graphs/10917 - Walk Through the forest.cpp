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

vi dist;
vector<vii> AdjList;
int dp[1000+5];
int E,V;

int solve(int u){
    if (dp[u]!=-1) {
        return dp[u];
    }
    int count = 0;
    for (int i=0; i<AdjList[u].size(); i++) {
        ii child = AdjList[u][i];
        if (dist[child.first]>dist[u]) {
            count += solve(child.first);
        }
    }
    return dp[u] = count;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    while (cin>>V) {
        if (!V) {
            break;
        }
        cin>>E;
        AdjList.assign(V, vii());
        for (int i=0; i<E; i++) {
            int a,b,c;
            cin>>a>>b>>c;
            a--,b--;
            AdjList[a].push_back(ii(b,c));
            AdjList[b].push_back(ii(a,c));
        }
        int s = 1;
        dist.assign(V, INF);
        dist[s] = 0;
        priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
        while (!pq.empty()) {
            ii front = pq.top(); pq.pop();     // greedy: pick shortest unvisited vertex
            int d = front.first, u = front.second;
            if (d > dist[u]) continue;   // this check is important, see the explanation
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j];                       // all outgoing edges from u
                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;
                    pq.push(ii(dist[v.first], v.first));
                }
            }
        }
        memset(dp, -1, sizeof(dp));
        dp[0] = 1;
        cout<<solve(1)<<endl;

    }

    return 0;
}
