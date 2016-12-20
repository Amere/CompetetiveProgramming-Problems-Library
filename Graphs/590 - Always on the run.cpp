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
int n,k;

vi arr[10+2][10+2];

int memo[10+5][1000+5];
int solve(int curCity,int day){
    if (day==k && curCity!=n-1) {
        return INF;
    }
    if (day==k) {
        return 0;
    }
    if (memo[curCity][day]!=-1) {
        return memo[curCity][day];
    }
    int res = INF;
    for (int i=0; i<n; i++) {
        if (i==curCity || arr[curCity][i][day]==0) {
            continue;
        }
        res = min(res,arr[curCity][i][day]+solve(i, day+1));
    }
    return memo[curCity][day] = res;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tC = 0;
    while (cin>>n>>k) {
        tC++;
        if (!n && !k) {
            break;
        }
        memset(memo, -1, sizeof(memo));
        for (int i=0; i<12; i++) {
            for (int j=0; j<12; j++) {
                arr[i][j].clear();
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i==j) {
                    continue;
                }
                int d;
                cin>>d;
                vector<int> v(d);
                for (int a=0; a<d; a++) {
                    cin>>v[a];
                }
                int idx = 0;
                for (int a=0; a<k; a++) {
                    if (idx==d) {
                        idx=0;
                    }
                    arr[i][j].push_back(v[idx]);
                    idx++;
                }
            }
        }
        int res = solve(0, 0);
        cout<<"Scenario #"<<tC<<"\n";
        if (res == INF) {
            cout<<"No flight possible.\n";
        }else{
            cout<<"The best flight costs "<<solve(0, 0)<<"."<<endl;
        }
        cout<<"\n";
    }
    return 0;
}
