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
            cout<<"+"<<v[i];
        }else cout<<v[i];
    }
}

int t,n;
vector<int> nums;
vector<vi> results;
set<vi> s;

void backtrack(int idx,int curSum,vi r){
    if (curSum==t) {
        sort(r.rbegin(), r.rend());
        if (!s.count(r)) {
            s.insert(r);
            results.push_back(r);
        }
        return;
    }
    if (curSum>t) {
        return;
    }
    if (idx==n) {
        return;
    }
    REP(i,idx,n){
            r.push_back(nums[i]);
            backtrack(i+1,curSum+nums[i], r);
            r.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt", "w", stdout);
    while (true) {
        cin>>t>>n;
        if (!t&&!n) {
            break;
        }
        s.clear();
        results.clear();
        nums.clear();
        nums.assign(n, 0);
        for (int i=0; i<n; i++) {
            cin>>nums[i];
        }
        vector<int> v;

        backtrack(0,0,v);
        cout<<"Sums of "<<t<<":\n";
        if (results.size()==0) {
            cout<<"NONE\n";
        }
        for (int i=0; i<results.size(); i++) {
            printV(results[i]);
            cout<<endl;
        }
    }
    return 0;
}
