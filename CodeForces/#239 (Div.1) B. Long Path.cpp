#include <set>
#include <map>
#include <list>
#include <bitset>
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
#define pi acos(-1.0)
using namespace std;
int negInf = -10e9;

int main() {
    // freopen("crosses.in" , "r", stdin);
    // freopen("crosses.out", "w", stdout);
    int n;
    cin>>n;
    int arr[n+5];
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int dp[n+5];
    for (int i=0; i<n; i++) {
        dp[i]=0;
    }
    //dp[0]=2;
    for (int i=0; i<n; i++) {
        dp[i]+=2;
        for (int j=arr[i]-1; j<i; j++) {
            dp[i]=dp[i]%1000000007+dp[j]%1000000007;
        }
        //dp[i]+=dp[i-1];
    }
    int res = 0;
    for (int i=0; i<n; i++) {
        res=(res%1000000007) +(dp[i]%1000000007);
    }
    cout<<res%1000000007;
    return 0;
}
