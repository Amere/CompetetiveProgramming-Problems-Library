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
#define MAX 10
int grid[MAX][MAX];
int res;
bool valid(int x,int y){
    if (x>=0 && x<MAX && y>=0 && y<MAX) return true;
    return false;
}
void switchOn(int x,int y){
    grid[x][y] = !grid[x][y];
    if (valid(x+1, y)) {
        grid[x+1][y] = !grid[x+1][y];
    }
    if (valid(x-1, y)) {
        grid[x-1][y] = !grid[x-1][y];
    }
    if (valid(x, y+1)) {
        grid[x][y+1] = !grid[x][y+1];
    }
    if (valid(x, y-1)) {
        grid[x][y-1] = !grid[x][y-1];
    }
}
void backtrack(int x,int y,int count){
    if (y==10) {
        x++;
        y=0;
    }
    if (x==0) {
        backtrack(x, y+1, count);
        switchOn(x,y);
        backtrack(x, y+1, count+1);
        switchOn(x, y); //switching off after backtracking
        return;
    }
    if (x<10) {
        if (grid[x-1][y]) {
            switchOn(x, y);
            backtrack(x, y+1, count+1);
            switchOn(x, y);
        }else{
            backtrack(x, y+1, count);
        }
    }else{
        REP(i, 0, MAX){
            if (grid[x-1][i]) {
                return;
            }
        }
        res = min(count,res);
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt", "w", stdout);
    string st;
    while (cin>>st) {
        if (st=="end")
            break;
        res = INF;
        REP(i, 0, MAX){
            string s;
            cin>>s;
            REP(j, 0, MAX){
                if (s[j]=='#') {
                    grid[i][j]=0;
                }else{
                    grid[i][j]=1;
                }
            }
        }
        backtrack(0, 0, 0);
        if (res==INF) {
            cout<<st<<" "<<-1<<endl;
        }else{
            cout<<st<<" "<<res<<endl;

        }
    }
    return 0;
}
