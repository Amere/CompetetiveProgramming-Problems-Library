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
void printV(vector<int> v){
    for (int i=0; i<v.size(); i++) {
        if (i) {
            cout<<" "<<v[i];
        }else cout<<v[i];
    }
}


bool isPrime(int n){
    for (int i=2; i<n; i++) {
        if (n%i==0) {
            return false;
        }
    }
    return true;
}

int n;
int vis[17];
vector<vi> results;
void backtrack(int idx,vi t){
    if (idx==n-1) {
        for (int i=1; i<=n; i++) {
            if (isPrime(i+t[t.size()-1])&&isPrime(i+1)&&!vis[i]) {
                t.push_back(i);
                results.push_back(t);
                t.pop_back();
            }
        }
        return;
    }
    for (int i=1; i<=n; i++) {
        if (isPrime(i+t[t.size()-1]) && !vis[i]) {
            t.push_back(i);
            vis[i] = 1;
            backtrack(idx+1,t);
            t.pop_back();
            vis[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tC = 0;
    while (cin>>n) {
        if (tC) {
            cout<<endl;
        }
        tC++;
        results.clear();
        vector<int> t;
        memset(vis, 0, sizeof(vis));
        t.push_back(1);
        vis[1] = 1;
        backtrack(1,t);
        cout<<"Case "<<tC<<":\n";
        for (int i=0; i<results.size(); i++) {
            printV(results[i]);
            cout<<endl;
        }
    }
    return 0;
}
