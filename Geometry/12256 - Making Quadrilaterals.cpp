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
typedef std::pair<double, int> myPair_type;
struct mypair_comp{
    bool operator()(myPair_type const& lhs, myPair_type const& rhs){
        return lhs.first +EPS < rhs.first;
    }
};
double DEG_to_RAD(double d) { return d * PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }
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
    int n;
    ll dp[61+5];
    dp[0]=dp[1]=dp[2]=1;
    for (int i=3; i<61; i++) {
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    int i = 0;
    while (true) {
        cin>>n;
        if (n==0) {
            break;
        }
        i++;
        cout<<"Case "<<i<<": "<<dp[n-1]<<endl;
    }
    return 0;
}
