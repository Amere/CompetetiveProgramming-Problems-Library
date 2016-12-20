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
}
int fixMod(int a){
    return (a % mod + mod) % mod;
}
#define LSOne(S) (S & (-S))

class FenwickTree {
private:
    vi ft;

public:
    FenwickTree() {}
    // initialization: n + 1 zeroes, ignore index 0
    FenwickTree(int n) { ft.assign(n + 1, 0); }
    int rsq(int b) {                                     // returns RSQ(1, b)
        int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
        return sum; }
    int rsq(int a, int b) {                              // returns RSQ(a, b)
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }
    // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
    void adjust(int k, int v) {                    // note: n = ft.size() - 1
        for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};

ll _sieve_size;
bitset<999999+5> bs;
vector<ll> primes;
void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++){
        if (bs[i]) {
            for (ll j = i*i; j <= _sieve_size; j += i) {
                bs[j] = 0;
            }
            primes.push_back(i);
        }
    }
}
ll numPF(ll N) { //Count the number of prime factors
    ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
    while (N != 1 && (PF * PF <= N)) {
        while (N % PF == 0) { N /= PF; ans++; }
        PF = primes[++PF_idx];
    }
    if (N != 1) ans++;
    return ans;
}

map<int,int> mIdx;
map<int,int> mNum;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    sieve(999999);
    FenwickTree ftIdx(1000000);
    FenwickTree ft(1000000);
    vector<int> rev;
    for (int i=0; i<primes.size(); i++) {
        string s = toString(primes[i]);
        reverse(s.begin(), s.end());
        int cur = toInt(s);
        int add = 7-(int)s.length();
        int pfs = (int)numPF(cur);
        pfs += 2*(add);
        cur*=(ll)pow(10, add);
        mNum[cur] = pfs;
        rev.push_back(cur);
    }
    sort(rev.begin(), rev.end());
    for (int i=0; i<rev.size(); i++) {
        mIdx[rev[i]] = i+1;
        ft.adjust(i+1, mNum[rev[i]]);
        ftIdx.adjust(i+1, 1);
    }
    char c;
    int n;
    while (cin>>c>>n) {
        if (c=='q') {
            n++;
            int end = 1000006;
            int start = 1;
            int res = -1;
            while (end>=start) {
                int mid = start + (end-start)/2;
                if(ftIdx.rsq(mid)>n) end = mid-1;
                else
                    if(ftIdx.rsq(mid)<n) start = mid+1;
                    else  {
                        res = mid; break;
                    }
            }
            cout<<ft.rsq(res)<<endl;
        }else{
            ftIdx.adjust(mIdx[n], -1);
            ft.adjust(mIdx[n], -mNum[n]);
        }
    }
    return 0;
}
