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
#include <iomanip>
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))
using namespace std;
#define DFS_WHITE -1
#define DFS_BLACK 1
#define DFS_GRAY 2
#define REP(i, a, b) \
for (int i = int(a); i < int(b); i++)


typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef map<int, int>::iterator it_type;
typedef long long ll;
typedef map<int, int> mii;

struct point { double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}     //Point p(0,6);
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y; }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };


int main() {
    int count = 0;
    while (true) {
        count++;
        point P(0.0,0.0);
        string s;
        getline(cin, s);
        if (s=="END") {
            break;
        }
        int num = 0;
        for (int i=0; i<s.length()-1; i++) {
            if (s[i] >= '0' && s[i]<='9') {
                num = num*10+(s[i]-'0');
            }else{
                if (s[i]=='.'||s[i]==',') {
                    continue;
                }else{
                    if (s[i+1]==','||s[i+1]=='.') {
                        switch (s[i]) {
                            case 'N':
                                P.y+=num;
                                break;
                            case 'E':
                                P.x+=num;
                                break;
                            case 'W':
                                P.x-=num;
                                break;
                            case 'S':
                                P.y-=num;
                                break;
                        }
                    }else{
                        switch (s[i]) {
                            case 'N':
                                P.y+=num*sqrt(2)/2;
                                break;
                            case 'E':
                                P.x+=num*sqrt(2)/2;
                                break;
                            case 'W':
                                P.x-=num*sqrt(2)/2;
                                break;
                            case 'S':
                                P.y-=num*sqrt(2)/2;
                                break;
                        }
                        switch (s[i+1]) {
                            case 'N':
                                P.y+=num*sqrt(2)/2;
                                break;
                            case 'E':
                                P.x+=num*sqrt(2)/2;
                                break;
                            case 'W':
                                P.x-=num*sqrt(2)/2;
                                break;
                            case 'S':
                                P.y-=num*sqrt(2)/2;
                                break;
                        }
                        i++;
                    }
                }
                num=0;
            }
        }
        cout<<"Map #"<<count<<endl;
        printf("The treasure is located at (%.3f,%.3f).\n",P.x,P.y);
        printf("The distance to the treasure is %.3f.\n",hypot(P.x, P.y));
        cout<<endl;
    }

    return 0;
}
