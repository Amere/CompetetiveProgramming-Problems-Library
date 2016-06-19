#include <map>
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
ll mo = 1000000007;


ll comb[1001][1001] ;			//may need BigInteger, if the numbers are large, use a treemap
ll fact[1000];
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

ll func[101][1001];
int main() {
    ios_base::sync_with_stdio(0);
    nCr2(1001);
    fact[0] = 1;
    for (int i=1; i<=1000; i++) {
        fact[i] = ((fact[i-1]%mo)*(i%mo))%mo;
    }
    ll power[1000+1][1000+1];
    for (int i=0; i<=1000; i++) {
        power[i][0] = 1;
    }
   // memset(func, 0, sizeof(func));
    func[0][0]=1;
    for (int i=1; i<=100; i++) {
        for (int j=1; j<=1000; j++) {
            for (int k=1; k<=i; k++) {
                func[i][j] += (comb[i][k]*func[i-k][j-1])%mo;
                func[i][j] %= mo;
            }
        }
    }
    for (int i=1; i<=1000; i++) {
        for (int j=1; j<=1000; j++) {
            power[i][j] = (power[i][j-1]*i)%mo;
        }
    }

    int t;
    cin>>t;
    int ccc = 0;
    while (t--) {
        ccc++;
    int x,y;
    cin>>x>>y;
    int m = min(x,y);
    ll sumBi = 0;
    for (int i=1; i<=m; i++) {
        sumBi += (comb[y][i]%mo * comb[x][i]%mo * fact[i]%mo)%mo;
        sumBi%=mo;
    }
    ll sumIn = 0;
    for (int j=1; j<=y; j++) {
        ll sumT = 0;
        for (int i=1; i<=j;i++) {
            sumT+=comb[x][i]*comb[j][i]%mo*fact[i]%mo;
            sumT%=mo;
        }
        sumIn += (comb[y][j]%mo * sumT%mo)%mo;
        sumIn%=mo;
    }
    ll sumAll = 0;
    for (int j=1; j<=y; j++) {
        for (int i=1; i<=x; i++) {
            sumAll+=((comb[x][i] * comb[y][j])%mo * power[j][i])%mo;
            sumAll%=mo;
        }
    }
    ll surje = 0;
        for (int i=1; i<=y; i++) {
            for (int j=1; j<=x; j++) {
                surje += ((comb[y][i]*comb[x][j])%mo)*func[j][i]%mo;
                surje %= mo;
            }
        }
        printf("Case %d: %d %d %d %d\n",(int)ccc,(int)sumIn,(int)surje,(int)sumBi,(int)sumAll);
    }
    return 0;
}
