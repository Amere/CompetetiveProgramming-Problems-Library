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


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int V;
    while (true) {
        cin>>V;
        if (V==0) {
            break;
        }
        AdjList.assign(V, vii());
        while(true){
            int a,b;
            cin>>a>>b;
            if (!a&&!b) {
                break;
            }
            a--,b--;
            AdjList[a].push_back(ii(b,0));
            AdjList[b].push_back(ii(a,0));

        }
        queue<int> q;
        vi d(AdjList.size(),INF);
        int source = 0;
        int color[V];
        color[source] = 0;
        bool isBiparitite = true;
        d[source] = 0; /*distance from the source to the source is 0 */ q.push(source);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = 0; i < AdjList[u].size(); i++) {
                ii child = AdjList[u][i];
                if (d[child.first]==INF) {
                    d[child.first] = d[u] + 1;
                    q.push(child.first);
                    color[child.first]=1-color[u];
                }else
                    if(color[u]==color[child.first]){ isBiparitite=false;break;};
            }
        }
        if (isBiparitite) {
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}
