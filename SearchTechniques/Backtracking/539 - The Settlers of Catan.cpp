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
int mod  = 1000000007;

using namespace std;
inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef map<int, int>::iterator it_type;
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }
vector<vi> AdjList;
int vis[26][26];
int n,m;
int maxi;

void backtrack(int idx,int count){
    maxi = max(maxi,count);
    for (int i=0; i<AdjList[idx].size(); i++) {
        int child = AdjList[idx][i];
        if(!vis[idx][child]){
            vis[idx][child] = 1;
            vis[child][idx] = 1;
            backtrack(child,count+1);
            vis[idx][child] = 0;
            vis[child][idx] = 0;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt", "w", stdout);
    while (true) {
        cin>>n>>m;
        if(!n&&!m) break;
        memset(vis, 0, sizeof(vis));
        AdjList.assign(n, vi());
        for (int i=0; i<m; i++) {
            int a,b;
            cin>>a>>b;
            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
        }
        maxi = 0;
        for(int i=0;i<n;i++){
            backtrack(i,0);
        }
        cout<<maxi<<endl;
    }
    return 0;
}
