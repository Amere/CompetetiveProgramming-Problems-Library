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
ll numDiv[100000+5];
ll sumDiv[100000+5];

void modifiedSieve(int N)
{
    for(int i = 2; i < N; ++i)
        if(numDiv[i] == 1){
            for(int j = i; j < N; j += i)
            {
                int e = 0, k = j;
                while(k % i == 0) { k /= i; ++e; }
                numDiv[j] *= (e+1);
                sumDiv[j] *= (((ll)(long double)pow(i, e + 1) - 1)/(i-1));
            }
        }
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    for (int i=0; i<100002; i++) {
        numDiv[i] = 1;
        sumDiv[i] = 1;
    }
//    clr1(numDiv);
//    clr1(sumDiv);
    modifiedSieve(100000+2);
    while (n--) {
        int a,b,k;
        cin>>a>>b>>k;
        ll res1 = 0;
        ll res2 = 0;

        for (int i=a; i<=b; i++) {
            if (i%k==0) {
                res1+=numDiv[i];
                res2+=sumDiv[i];
            }
        }
        cout<<res1<<" "<<res2<<endl;
    }
    return 0;
}
