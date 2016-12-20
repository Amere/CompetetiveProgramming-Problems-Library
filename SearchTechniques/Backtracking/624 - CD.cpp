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
vector<int> v;
vector<int> results;
int maxi;
int n,k;
void backtrack(int idx,int sum,vector<int> cuRes){
    if (sum>n) {
        return;
    }
    if (sum>maxi) {
        maxi = sum;
        results = cuRes;
    }
    if (idx>=k) {
        return;
    }
    cuRes.push_back(v[idx]);
    backtrack(idx+1, sum+v[idx],cuRes);
    cuRes.pop_back();
    backtrack(idx+1, sum,cuRes);
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt", "w", stdout);
    while (cin>>n) {
        cin>>k;
        v.assign(n, 0);
        for (int i=0; i<k; i++) {
            cin>>v[i];
        }
        vector<int> vv;
        maxi = 0;
        backtrack(0, 0, vv);
        for (int i=0; i<results.size(); i++) {
            cout<<results[i]<<" ";
        }
        cout<<"sum:"<<maxi<<endl;
    }

    return 0;

}
