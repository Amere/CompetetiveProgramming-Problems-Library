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
int main(){
    ios_base::sync_with_stdio(0);

    char s[50];
    string result = "";
    while (gets(s)) {
        if (s[0]!='|') {
            continue;
        }
        char c = 0;
        for (int i=0; s[i]; i++) {
            if (s[i]=='o') {
                c<<=1;
                c++;
            }
            if (s[i]==' ') {
                c<<=1;
            }
        }
        cout<<c;
    }
    return 0;
}
