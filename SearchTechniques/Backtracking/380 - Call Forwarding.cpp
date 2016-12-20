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

struct info{
    int start,end,dest;
    info(){start = 0, end = 0, dest = 0;}
    info(int start,int end,int dest):start(start),end(end),dest(dest){}
};
int res;
vector<info> arr[9999];
int vis[9999];
void backtrack(int cur,int time){
    for (int i=0; i<arr[cur].size(); i++) {
        if(vis[arr[cur][i].dest]){
            res = 9999;
            return;
        }
        if(time >= arr[cur][i].start && time<=arr[cur][i].end){
            vis[arr[cur][i].dest] = 1;
            res = arr[cur][i].dest;
            backtrack(arr[cur][i].dest,time);
            vis[arr[cur][i].dest] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    int cc = 0;
    cout<<"CALL FORWARDING OUTPUT\n";
    while (t--) {
        cc++;
        cout<<"SYSTEM "<<cc<<endl;;
        for (int i=0; i<9999; i++)
            arr[i].clear();
        clr(vis);
        string src,start,end,dest,time;
        while (true) {
            cin>>src;
            if (src=="0000")
                break;
            cin>>start>>end>>dest;
            int st,to,sc,p;
            sc = toInt(src);
            st = toInt(start);
            p = toInt(end);
            to = toInt(dest);
            arr[sc].push_back(info(st, st+p, to));
        }
        while (true) {
            cin>>time;
            if(time=="9000") break;
            cin>>src;
            res = toInt(src);
            backtrack(res,toInt(time));
            cout<<"AT "<<time<<" CALL TO "<<src<<" RINGS ";
            string ss = toString(res);
            for (int i=0; i<4-ss.length(); i++) {
                cout<<"0";
            }
            cout<<res<<endl;
        }

    }
    cout<<"END OF OUTPUT\n";
    return 0;

}
