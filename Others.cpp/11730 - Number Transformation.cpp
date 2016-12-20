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

int s,t;
ll _sieve_size;
bitset<10001> bs;
vi primes;
vi factors;
void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
        for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
        primes.push_back((int)i);
    }
}
vi primeFactors(ll N) {
    vi factors;
    ll PF_idx = 0, PF = primes[PF_idx];
    while (N != 1 && (PF * PF <= N)) {
        if (N%PF==0) {
            factors.push_back((int)PF);
        }
        while (N % PF == 0) { N /= PF; }
        PF = primes[++PF_idx];
    }
    if (N != 1) factors.push_back((int)N);
    return factors;
}

bool opt[1000+50];
int bfs(){
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        factors = primeFactors(cur);
        for (int i=0; i<factors.size(); i++) {
            int next = cur+factors[i];
            if (opt[next] || next>t) {
                continue;
            }
            if (next == t) {
                return opt[cur]+1;
            }
            opt[next] = opt[cur]+1;
            q.push(next);
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt", "w", stdout);
    sieve(1000001);
    int tC = 0;
    while (true) {
        clr(opt);
        tC++;
        cin>>s>>t;
        if (!s && !t) {
            break;
        }
        int res = bfs();
        if (s==t) {
            cout<<"Case "<<tC<<": "<<0<<endl;
        }else
            cout<<"Case "<<tC<<": "<<res<<endl;
    }
    return 0;
}
