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
    int n;
    while (cin>>n) {
        int count = 0;
        for (int i=0; i<5; i++) {
            int t;
            cin>>t;
            if (t==n) {
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
