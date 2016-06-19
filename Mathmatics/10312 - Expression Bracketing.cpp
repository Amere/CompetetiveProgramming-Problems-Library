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
typedef pair<int, int> pii;
//const int inf = ~0U >> 1;
//const ll INF = ~0ULL >> 1;
#define sz(v)        static_cast<int>((v).size())
#define pb(...)      push_back(__VA_ARGS__)
#define mp(x, y)     make_pair((x), (y))
#define clr(x) memset(x, 0, sizeof(x))
#define dREP(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
ll mo = 1000000007;

ll comb[27][27];
void nCr2(int N)		// O(N * N)
{
    comb[0][0] = 1;
    for (int i = 1; i < N; i++)
    {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++)
            comb[i][j] = (comb[i-1][j]%mo + comb[i-1][j-1]%mo)%mo;		//may use mod
    }
}

ll dp[27][27];
ll solve(int start,int end){
    if (start==end||end-start==1||end<=2) {
        return 1;
    }
    if (dp[start][end]!=-1) {
        return dp[start][end];
    }
    ll sum = 0;
    for (int i=1; i+start<end ;i++) {
        sum+=solve(0, i)*solve(i+start, end);
    }
    if(start != 0)
        sum += solve(0, end - start);
    return dp[start][end] = sum;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    nCr2(27);
    int n;
    ll cat[27];
    cat[0] = 1;
    for(int i = 1; i <= 26; ++i)
        cat[i] = cat[i-1] * (i<<1) * ((i<<1) - 1) / (i * (i + 1));
    while (cin>>n) {
        memset(dp, -1, sizeof(dp));
        n--;
        cout<<solve(0, n+1)-(cat[n])<<endl;
    }



    return 0;
}
