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
    cout<<endl;
}
int fixMod(int a){
    return (a % mod + mod) % mod;
}


ll gcd(ll a,ll b) {
    if (b==0) {
        return a;
    }
    return gcd(b,a%b);
}
ll pow(ll x){
    if (x==0) {
        return 1;
    }else{
        return 10*pow(x-1);
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt", "w", stdout);
    int i,j,dig;
    string X;
    int tC = 0;
    while (true) {
        cin>>j;
        tC++;
        if (j==-1) {
            break;
        }
        cin>>X;
        ll le = X.length();
        le-=2;
        i=(int)le-j;
        ll x = 0;
        for (int i=(int)X.length()-1, p=1; i>1; i--,p*=10) {
            x+=(X[i]-'0')*p;
        }
        dig=9;
        ll numer = x - x/pow(j);
        ll domi = pow(i+j) - pow(i);
        ll gc = gcd(numer,domi);
        cout<<"Case "<<tC<<": ";
        if(numer==0 && domi==0){
            gc = gcd(pow(le),x);
            cout<<x/gc<<"/"<<pow(le)/gc<<endl;
        }else
            cout<<numer/gc<<"/"<<domi/gc<<endl;
    }
    return 0;
}
