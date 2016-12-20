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
#define clr1(x) memset(x, 1, sizeof(x))
#define dREP(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define DFS_WHITE -1
#define DFS_BLACK 1
#define DFS_GRAY 2
int mod;
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
    cout<<endl;
}
int fixMod(int a){
    return (a % mod + mod) % mod;
}
vector<vi> depen;
int lef[105];
int righ[105];
int node[105];
int res[105];
int root;
void read(int cur,int lev){
    if (cur==-1) {
        return;
    }
    res[lev]+=cur;
    cin>>lef[cur];
    read(lef[cur],lev-1);
    cin>>righ[cur];
    read(righ[cur],lev+1);
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tC = 0;
    while (true) {
        tC++;
        cin>>root;
        if (root==-1) {
            break;
        }
        memset(lef, -1, sizeof(lef));
        memset(righ, -1, sizeof(righ));
        clr(res);
        read(root,50);
        bool f = 1;
        cout<<"Case "<<tC<<":\n";
        for (int i=0; i<105; i++) {
            if (res[i] && f) {
                cout<<res[i];
                f = 0;
            }else{
                if (res[i]) {
                    cout<<" "<<res[i];
                }
            }
        }
        cout<<endl<<endl;
    }
    return 0;
}
