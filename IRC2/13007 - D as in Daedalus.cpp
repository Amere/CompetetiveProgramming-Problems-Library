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
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(10);
    arr.push_back(100);
    arr.push_back(1000);
    arr.push_back(10000);
    while (cin>>n>>m) {
        int all = 0;
        while(m--){
            int B;
            cin>>B;
            vector<int> pls;
            int sum = 0;
            for (int i=0; i<n; i++) {
                int t;
                cin>>t;
                sum+=t;
                pls.push_back(t);
            }
            int profit = 0;
            if (sum<=B) {
                profit = pls[0];
            }
            sum-=pls[0];
            int extra = 0;
            for (int i=0; i<arr.size(); i++) {
                if (arr[i]==pls[0]) {
                    continue;
                }
                if (sum+arr[i]<=B) {
                    extra = max(extra,arr[i]-profit);
                }
            }
            all+=extra;
        }
        cout<<all<<endl;
    }
    return 0;
}
