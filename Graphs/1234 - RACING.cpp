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

vi taken;                                  // global boolean flag to avoid cycle
priority_queue<ii> pq;            // priority queue to help choose shorter edges
vector<vii> AdjList;
int E,V;
void process(int vtx) {    // so, we use -ve sign to reverse the sort order
    taken[vtx] = 1;
    for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
        ii v = AdjList[vtx][j];
        if (!taken[v.first]) pq.push(ii(v.second, v.first));
    } }

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while (t--) {
        cin>>V>>E;
        ll all = 0;
        AdjList.assign(V, vii());
        for (int i=0; i<E; i++) {
            int a,b,c;
            cin>>a>>b>>c;
            a--,b--;
            AdjList[a].push_back(ii(b,c));
            AdjList[b].push_back(ii(a,c));
            all+=c;
        }
        taken.assign(V, 0);
        while (pq.size()) {
            pq.pop();
        }
        process(0);
        int mst_cost = 0;
            while (!pq.empty()) {  // repeat until V vertices (E=V-1 edges) are taken
                ii front = pq.top(); pq.pop();
                int u = front.second; int w = front.first;  // negate the id and weight again
                if (!taken[u])                 // we have not connected this vertex yet
                    mst_cost += w, process(u); // take u, process all edges incident to u
            }                                        // each edge is in pq only once!
        cout<<all-mst_cost<<endl;
    }
    cin>>t;

    return 0;
}
