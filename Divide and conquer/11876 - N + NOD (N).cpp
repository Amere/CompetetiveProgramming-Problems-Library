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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef map<int, int>::iterator it_type;
#define INF 1e9
#define llINF 9223372036854775807
#define EPS 1e-9
#define sz(v)        static_cast<int>((v).size())
#define pb(...)      push_back(__VA_ARGS__)
#define mp(x, y)     make_pair((x), (y))
#define clr(x) memset(x, 0, sizeof(x))
#define dREP(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
ll mo = 1000000007;
long long _sieve_size;
bitset<10000010> bs;
vector<int> primes;
int count2 = 0;
void sieve(long long upperbound){
    _sieve_size = upperbound+1;
    bs.set();
    bs[0]=bs[1]=0;
    for(long long i=2;i<=_sieve_size;i++){
        if (bs[i]) {
            for (long long j=i*i; j<_sieve_size; j+=i) bs[j]=0;
            primes.push_back((int)i);

        }
    }
}
ll numDiv(ll N){
    ll PF_idx = 0, PF= primes[PF_idx], ans = 1;
    while (PF * PF <= N) {
        ll power = 0;
        while (N%PF==0) {
            N/=PF;power++;
        }
        ans*=(power+1);
        PF=primes[++PF_idx];
    }
    if (N!=1) {
        ans*=2;
    }
    return ans;
}
vector<ll> seq;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    sieve(1000100);
    seq.pb(1);
    for (int i=1; seq[i-1]<1000000; i++) {
        ll s = sz(seq);
        seq.pb(seq[s-1]+numDiv(seq[s-1]));
    }
    int t;
    cin>>t;
    int cc = 0;
    while (t--) {
        cc++;
        int A,B;
        cin>>A>>B;
        auto it = lower_bound(seq.begin(), seq.end(), A);
        auto it1 = upper_bound(seq.begin(), seq.end(), B);
        ll ans = 0;
        if(it!=seq.end()&&it1!=seq.end()){
            ans = it1-it;
        }
        cout<<"Case "<<cc<<": ";
        cout<<ans<<endl;
    }
    return 0;
}
