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
int vis[26];
int n,m,k;
set<vi> results;
set<vi> test;
void backtrack(int idx,int count,vector<int> res){
    if (count==k) {
        results.insert(res);
        return;
    }
    for (int i=0; i<AdjList[idx].size(); i++) {
        int child = AdjList[idx][i];
        if(!vis[child]){
            vis[child] = 1;
            res.push_back(child);
            backtrack(child,count+1,res);
            res.pop_back();
            vis[child] = 0;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt", "w", stdout);
    while (true) {
        cin>>n>>k;
        memset(vis, 0, sizeof(vis));
        int te;
        AdjList.assign(n, vi());
        results.clear();
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin>>te;
                if (te) {
                    AdjList[i].push_back(j);
                }
            }
        }
        vis[0] = 1;
        vector<int> vv;
        backtrack(0,0,vv);
        auto it = results.begin();
        int i = 0;
        for (; it!=results.end();it++,i++) {
            vi res = *it;
            cout<<"(";
            cout<<1;
            for (int j=0; j<res.size(); j++) {
                cout<<","<<res[j]+1;
            }
            cout<<")\n";
        }
        if (!i) {
            cout<<"no walk of length "<<k<<endl;
        }
        if (cin>>te) {
            cout<<endl;
        }else{
            break;
        }
    }
    return 0;
}
