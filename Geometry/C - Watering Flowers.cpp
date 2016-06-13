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
#define llINF 9223372036854775807
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
struct point { int x, y;
    point() { x = y = 0.0; }
    point(int _x, int _y) : x(_x), y(_y) {}     //Point p(0,6);
    bool operator < (point other) const {
        if (fabs(y - other.y) > EPS)
            return y < other.y;
        return x < other.x; }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };

ll dist(point p1, point p2) { // hypot(xx, yy) returns sqrt(xx * xx + yy * yy)
    ll res=(p1.x - p2.x)*(ll)(p1.x - p2.x) + (ll)(p1.y - p2.y)*(p1.y - p2.y); ;
    return res;
}




int main() {
    int n,x,y,x1,y1;
    cin>>n>>x>>y>>x1>>y1;
    point center1(x,y);
    point center2(x1,y1);
    vector<point> v;

    for (int i = 0; i<n; i++) {
        int xx,yy;
        cin>>xx>>yy;
        v.push_back(point(xx,yy));
    }
    ll result = llINF;
    for (int i=0; i<n+1; i++) {
        ll r1;
        if (i==0) {
            r1 = 0;
        }else{
            r1 = dist(center1, v[i-1]);
        }
        ll maxOutR2 = 0;
        int idx = -1;
        for (int j=0; j<n; j++) {
            if (dist(v[j],center1)>r1) {
                if (maxOutR2<dist(v[j],center2)) {
                    maxOutR2 = dist(v[j],center2);
                    idx = j;
                }
            }
        }
        //cout<<v[idx].x<<" "<<v[idx].y<<"**"<<v[i-1].x<<" "<<v[i-1].y<<endl;
        ll com = 0;
        if(idx==-1){
            if(i!=0){
            com = (center1.x-v[i-1].x)*(ll)(center1.x-v[i-1].x)+(ll)(center1.y-v[i-1].y)*(center1.y-v[i-1].y);
                //cout<<"*"<<v[i-1].x<<" "<<v[i-1].y<<"***"<<com<<endl;
            }
        }else{
            if(i!=0){
            com = (center1.x-v[i-1].x)*(ll)(center1.x-v[i-1].x)+(center1.y-v[i-1].y)*(ll)(center1.y-v[i-1].y);
              //  cout<<v[idx].x<<" "<<v[idx].y<<"**"<<v[i-1].x<<" "<<v[i-1].y<<"***"<<com<<endl;
            }
            com += (center2.x-v[idx].x)*(ll)(center2.x-v[idx].x)+(center2.y-v[idx].y)*(ll)(center2.y-v[idx].y);
        }
        if (com<result) {
           // cout<<"here"<<com<<endl;;
            result = com;
        }
    }

    cout<<result;
    return 0;
}
