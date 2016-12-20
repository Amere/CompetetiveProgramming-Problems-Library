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

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    ull res = 0;
    ull ones,zeros;
    ull one = 1;
    ull negOne = 0;

    while (t--) {
        cin>>ones>>zeros;
        if(ones==0){cout<<0<<endl; continue;}

        for (int i=0; i<ones+zeros; i++) {
            negOne|=(one<<i);
        }
        if (2*zeros>=ones) {
            res = 1;
            for (ull i=2,cur=1;cur<ones ;i+=3) {
                res|=(one<<i);
                cur++;
                if (cur<ones) {
                    res|=(one<<(i+1));
                    cur++;
                }
            }
            cout<<res<<endl;
        }else{
            res = 0;
            if (ones==1 && zeros==1) {
                cout<<1<<endl;
                continue;
            }
            for (ull i=0; i<ones+zeros; i++) {
                res|=(one<<i);
            }
            ull pos = ones+zeros-2;

            for (ll cur=0,j=pos;cur<zeros ;cur++,j-=3) {
                res&=((one<<j)^(negOne));
            }
            cout<<res<<endl;
        }
    }
    return 0;
}
