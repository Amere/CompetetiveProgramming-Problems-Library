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
int mini;
int col[9];
int diag1[30];
int diag2[30];

void backtrack(int idx,int cur){
    if (idx==8) {
        mini = min(cur,mini);
        return;
    }
    int pos = v[idx];
    for (int i=0; i<8; i++) {
        if(!col[i] && !diag1[idx+i] && !diag2[idx-i+20]){
            col[i] = 1;
            diag1[idx+i] = 1;
            diag2[idx-i+20] = 1;
            if(i==pos)backtrack(idx+1, cur);
            else backtrack(idx+1, cur+1);
            col[i] = 0;
            diag1[idx+i] = 0;
            diag2[idx-i+20] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt", "w", stdout);
    int s;
    int cc = 0;
    while (cin>>s) {
        cc++;
        v.clear();
        mini = INF;
        s--;
        v.push_back(s);
        for (int i=0; i<7; i++) {
            cin>>s;
            s--;
            v.push_back(s);
        }
        memset(col, 0, sizeof(col));
        memset(diag1, 0, sizeof(diag1));
        memset(diag2, 0, sizeof(diag2));
        backtrack(0,0);
        cout<<"Case "<<cc<<": "<<mini<<endl;
    }

    return 0;
}
