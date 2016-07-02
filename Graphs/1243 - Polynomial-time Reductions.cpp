/* Not accepted yet WA */

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
#define dREP(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define DFS_WHITE -1
#define DFS_BLACK 1
#define DFS_GRAY 2
ll mo = 1000000007;


int AdjMatrix[200][200];

int V,E;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int cas = 1;
    while (true) {
        clr(AdjMatrix);
        cin>>V>>E;
        if (!V&&!E) break;
        for (int i=0; i<E; i++) {
            int a,b;
            cin>>a>>b;
            a--,b--;
            AdjMatrix[a][b] = 1;
        }
        int ans = V;
        for (int k = 1; k < V; k++) // common error: remember that loop order is k->i->j
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    if (AdjMatrix[i][k] && AdjMatrix[k][j] && AdjMatrix[i][j] ){
                        AdjMatrix[i][j] = 0;
                        ans--;
                    }
        cout<<"Case "<<cas<<": "<<ans<<endl;
        cas++;
    }
    return 0;
}
