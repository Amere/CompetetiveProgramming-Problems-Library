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
#define PI acos(-1.0);
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
int mo = 1000000007;
ll male[100000000];
ll female[100000000];

int n;

int main() {
    ios_base::sync_with_stdio(0);

    while (true) {
        cin>>n;
        if (n==-1) {
            break;
        }
        male[0] = 0;
        female[0] = 1;
        for (int i=1; i<=n; i++) {
            male[i] = male[i-1]+female[i-1];
            female[i] = male[i-1]+1;
        }
        cout<<male[n]<<" "<<female[n]+male[n]<<endl;

    }
    return 0;
}
