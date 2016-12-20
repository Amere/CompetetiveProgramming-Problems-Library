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


int mon(string m){
    if (m=="JAN") {
        return 31;
    }
    if (m=="FEB") {
        return 28;
    }
    if (m=="MAR") {
        return 31;
    }
    if (m=="APR") {
        return 30;
    }
    if (m=="MAY") {
        return 31;
    }
    if (m=="JUN") {
        return 30;
    }
    if (m=="JUL") {
        return 31;
    }
    if (m=="AUG") {
        return 31;
    }
    if (m=="SEP") {
        return 30;
    }
    if (m=="OCT") {
        return 31;
    }
    if (m=="NOV") {
        return 30;
    }
    if (m=="DEC") {
        return 31;
    }
    return 0;
}

int day(string d){

    if (d=="MON") {
        return 1;
    }
    if (d=="TUE") {
        return 2;
    }
    if (d=="WED") {
        return 3;
    }
    if (d=="THU") {
        return 4;
    }
    if (d=="FRI") {
        return 5;
    }
    if (d=="SAT") {
        return 6;
    }
    if (d=="SUN") {
        return 7;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while (t--) {
        string d,m;
        cin>>m>>d;
        int mo = mon(m);
        int da = day(d);
        int count = 0;
        for (int i=0,j=da; i<mo; i++) {
            if (j==8) {
                j=1;
            }
            if (j==5 || j== 6) {
                count++;
            }
            j++;
        }
        cout<<count<<endl;
    }
    return 0;
}
