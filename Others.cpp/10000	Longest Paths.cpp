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
#define amora cout<<"amora l fshee5 :D"<<endl;
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
void printV(vector<int> v){
    for (int i=0; i<v.size(); i++) {
        if (i) {
            cout<<" "<<v[i];
        }else cout<<v[i];
    }
}
int fixMod(int a){
    return (a % mod + mod) % mod;
}

int vis[105][105];
vector<vi> AdjList;
int V,E,resF;
int memo[105];
int backtrack(int idx){
    if (memo[idx]!=-1) {
        return memo[idx];
    }
    int res = 0;
    for (int i=0; i<AdjList[idx].size(); i++) {
        int child = AdjList[idx][i];
        if (!vis[idx][child]) {
            vis[idx][child] = 1;
            res = max(res,1+backtrack(child));
            vis[idx][child] = 0;
        }
    }
    return memo[idx] = res;
}
int getDest(int idx,int cnt){
    if (cnt==resF) {
        return idx;
    }
    int curR = INF;
    for (int i=0; i<AdjList[idx].size(); i++) {
        if (memo[AdjList[idx][i]]+1==memo[idx]) {
            curR = min(curR,getDest(AdjList[idx][i],cnt+1));
        }
    }
    return curR;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tC = 0;
    while (true) {
        tC++;
        cin>>V;
        if (!V) {
            break;
        }
        clr(vis);
        memset(memo, -1, sizeof(memo));
        AdjList.assign(V, vi());
        int s;
        cin>>s;
        s--;
        while (true) {
            int a,b;
            cin>>a>>b;
            if (!a && !b) {
                break;
            }
            a--;
            b--;
            AdjList[a].push_back(b);
        }
        resF = backtrack(s);
        int dest = getDest(s,0);

        cout<<"Case "<<tC<<": The longest path from "<<s+1<<" has length "<<resF<<", finishing at "<<dest+1<<".\n";
        cout<<endl;
    }
    return 0;
}
