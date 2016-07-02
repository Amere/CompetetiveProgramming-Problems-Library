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

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    map<int,vi> m;
    cin>>s;
    for (int i=0; i<s.length(); i++) {
        m[s[i]-'a'].pb(i);
    }
    int q;
    cin>>q;
    while (q--) {
        string bil;
        cin>>bil;
        int idx = m[bil[0]-'a'][0];
        int start = idx;
        bool f = true;
        int end;
        for (int i=1; i<bil.length(); i++) {
            vi v = m[bil[i]-'a'];
            auto it = upper_bound(v.begin(), v.end(), idx);
            if (it==v.end()) {
                f = false;
                break;
            }
            idx = *it;
        }
        end = idx;
        if (f) cout<<"Matched "<<start<<" "<<end<<endl;
        else cout<<"Not matched"<<endl;

    }
    return 0;
}
