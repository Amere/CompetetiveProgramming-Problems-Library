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


char pic[32][32];
string tree;
int idx;
void color(int x, int y, int b2) {
    char c = tree[idx];
    if(c == 'p') {
        idx++;
        color(x, y+b2/2, b2/2);
        color(x, y, b2/2);
        color(x+b2/2, y, b2/2);
        color(x+b2/2, y+b2/2, b2/2);
    } else if(c == 'f') {
        int i, j;
        for(i = x; i < x+b2; i++) {
            for(j = y; j < y+b2; j++) {
                pic[i][j] = 1;
            }
        }
        idx++;
    } else
        idx++;
}

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--) {
        memset(pic, 0, sizeof(pic));
        cin>>tree;
        idx = 0;
        color(0, 0, 32);
        idx = 0;
        cin>>tree;
        color(0, 0, 32);
        int res = 0;
        for(int i = 0; i < 32; i++)
            for(int j = 0; j < 32; j++)
                res += pic[i][j];
        printf("There are %d black pixels.\n", res);
    }
        return 0;
}
