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
int arr[180+5];
vector<pair<pair<int,int>,int>> cubes;
int main() {
    // freopen("crosses.in" , "r", stdin);
    // freopen("crosses.out", "w", stdout);

        int n,N,a,b,c,x[90],y[90],z[90],dp[90];

        while(true){
            cin>>n;
            if(n==0) break;

            N = 3*n;

            for(int i = 0;i<n;++i){
                cin>>a>>b>>c;
                x[3*i] = a; y[3*i] = b; z[3*i] = c;
                x[3*i+1] = b; y[3*i+1] = c; z[3*i+1] = a;
                x[3*i+2] = c; y[3*i+2] = a; z[3*i+2] = b;
            }

            for(int i = 0;i<N;++i) for(int j = i+1;j<N;++j){
                if((x[j]<x[i] && y[j]<y[i]) || (y[j]<x[i] && x[j]<y[i])){
                    swap(x[i],x[j]);
                    swap(y[i],y[j]);
                    swap(z[i],z[j]);
                }
            }

            int ans = -1;

            for(int i = 0;i<N;++i){
                dp[i] = z[i];
                for(int j = 0;j<i;++j)
                    if((x[j]<x[i] && y[j]<y[i]) || (y[j]<x[i] && x[j]<y[i]))
                        dp[i] = max(dp[i],dp[j]+z[i]);

                ans = max(ans,dp[i]);
            }

            cout<<ans<<endl;
        }
    return 0;
}
