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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int dp[50+5][50+5];
int INF = 2147483640;
vector<int> cuts;

int solve(int begin,int end){
    if (end-begin==1) {
        return 0;
    }

    if (dp[begin][end]!=-1) {
        return dp[begin][end];
    }
    int mi = INF;
    for (int i=begin+1; i<end; i++) {
        mi = min(mi,cuts[end]-cuts[begin]+solve(begin, i)+solve(i, end));
    }
    return dp[begin][end] = mi;
}
int main(){

    while (true) {
        memset(dp, -1, sizeof (dp));
        int l;
        cin>>l;
        if (l==0) {
            break;
        }
        int c;
        cin>>c;
        cuts.clear();
        cuts.push_back(0);
        for (int i=0; i<c; i++) {
            int t;
            cin>>t;
            cuts.push_back(t);
        }
        cuts.push_back(l);

        cout<<"The minimum cutting is "<<solve(0,c+1)<<".\n";
    }
    return 0;
}
