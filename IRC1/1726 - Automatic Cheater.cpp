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
int INF = 2000000000;
int solved[14][4];
int notSolved[14][4];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while (t--) {
        memset(solved, 0, sizeof(solved));
        memset(notSolved, 0, sizeof(notSolved));
        int q;
        cin>>q;
        while (q--) {
            int dif,l;
            char s;
            cin>>dif>>l>>s;
            dif--;
            if (s=='c') {
                solved[dif][l]++;
            }else{
                notSolved[dif][l]++;
            }
        }
        long long count=0;
        for (int i=0;i<10;i++) {
            long long cur = notSolved[i][0];
            long long co = 0;
            for (int j=i+1; j<10; j++) {
                co += cur*solved[j][1];
            }
            count+=co;
        }
        cout<<count<<endl;
    }
    return 0;
}
