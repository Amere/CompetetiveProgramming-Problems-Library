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
#define amora cout<<"amora l fshee5 :D"<<endl;
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
#define NOT(x)    (1^(x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef map<int, int>::iterator it_type;
int mod  = 1000000007;
inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
inline ll toll(string s){ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }
void printV(vector<int> v){
    for (int i=0; i<v.size(); i++) {
        if (i) {
            cout<<" "<<v[i];
        }else cout<<v[i];
    }
}
int fixMod(int a){
    return (a % mod + mod) % mod;
}
#define MAX 1000006
ll _sieve_size;
bitset<10000> bs;
vi primes;
void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
        for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
        primes.push_back((int)i);
    }
}
bool isPrime(ll N) {
    return bs[N];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    sieve(10000);
    int n;
    cin>>n;
    while (n--) {
        string s1,s2;
        cin>>s1>>s2;
        int n1,n2;
        n1 = toInt(s1);
        n2 = toInt(s2);
        vi dist(10000,INF);
        dist[toInt(s1)] = 0;
        queue<int> q;
        q.push(n1);
        while (!q.empty()) {
            int cur = q.front();
            string curS = toString(cur);
            q.pop();
            for (int j=0; j<4; j++) {
                for (int i=0; i<10; i++) {
                    if ((curS[j]-'0') != i && (i||j)) {
                        string temp = curS;
                        temp[j] = (char)(i+'0');
                        int curr = toInt(temp);
                        if (!isPrime(curr) || dist[curr]!=INF ) {
                            continue;
                        }
                        if (curr==n2) {
                            dist[curr] = dist[cur]+1;
                            break;
                        }
                        dist[curr] = min(dist[cur]+1,dist[curr]);
                        q.push(curr);
                    }
                }
            }
        }
        if (dist[n2]==INF) {
            cout<<"Impossible\n";
        }else{
            cout<<dist[n2]<<endl;
        }
    }
    return 0;
}
