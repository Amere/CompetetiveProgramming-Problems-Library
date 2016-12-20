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

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    string s;
    int tC = 0;
    vector<int> v;
    while (t--) {
        cin>>s;
        tC++;
        v.assign(26, 0);
        for (int i=0; i<s.length(); i++) {
            v[s[i]-'a']++;
        }
        int mini = INF;
        for (int i=0; i<v.size(); i++) {
            mini = min(v[i],mini);
        }
        cout<<"Case "<<tC<<": ";
        cout<<mini<<endl;
    }


    return 0;
}
