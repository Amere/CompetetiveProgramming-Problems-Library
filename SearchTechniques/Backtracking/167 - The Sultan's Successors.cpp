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

int arr[10][10];
int vis[10];
int lD[20];
int rD[20];
int maxi = 0;

void backtrack(int r,int sum){
    if (r==8) {
        maxi = max(maxi,sum);
        return;
    }
    for (int i=0; i<8; i++) {
        if (!vis[i] && !lD[(r-i)+8] && !rD[r+i]) {
            vis[i] = 1;
            lD[r-i+8] = 1;
            rD[r+i] = 1;
            backtrack(r+1,sum+arr[r][i]);
            vis[i] = 0;
            lD[r-i+8] = 0;
            rD[r+i] = 0;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while (t--) {
        for (int i=0; i<8; i++) {
            for (int j=0; j<8; j++) {
                cin>>arr[i][j];
            }
        }
        memset(vis, 0 , sizeof(vis));
        memset(lD, 0, sizeof(lD));
        memset(rD, 0, sizeof(rD));
        maxi = 0;
        backtrack(0,0);
        cout<<setw(5);
        cout<<maxi<<endl;
    }
    return 0;

}
