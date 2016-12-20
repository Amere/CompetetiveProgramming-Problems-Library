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
int arr[5];
bool backtrack(int idx,int res){
    if(idx==5){
        if(res==23) return true;
        else return false;
    }
    return backtrack(idx+1,res+arr[idx])||backtrack(idx+1,res-arr[idx])||backtrack(idx+1,res*arr[idx]);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt", "w", stdout);
    while (true) {
        bool f = true;
        for (int i=0; i<5; i++) {
            cin>>arr[i];
            f&=!arr[i];
        }
        if (f) {
            break;
        }
        sort(arr, arr+5);
        bool res = false;
        do {
            if(backtrack(1,arr[0])){
                res = true;
                break;
            }
        } while(next_permutation(arr,arr+5));
        if (res) {
            cout<<"Possible\n";
        }else{
            cout<<"Impossible\n";
        }
    }

    return 0;
}
