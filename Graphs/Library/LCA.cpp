
vector< vector<int> > children;
#define MAX_N 1000                           // adjust this value as needed
#define LOG_TWO_N 11           // 2^10 > 2000, adjust this value as needed
class RMQ {                                          // Range Minimum Query
private:
  int _A[2*MAX_N], SpT[2*MAX_N][LOG_TWO_N];
public:
  RMQ(int n, int A[]) {    // constructor as well as pre-processing routine
    for (int i = 0; i < n; i++) {
      _A[i] = A[i];
      SpT[i][0] = i; // RMQ of sub array starting at index i + length 2^0=1
    }
    // the two nested loops below have overall time complexity = O(n log n)
    for (int j = 1; (1<<j) <= n; j++) // for each j s.t. 2^j <= n, O(log n)
      for (int i = 0; i + (1<<j) - 1 < n; i++)    // for each valid i, O(n)
        if (_A[SpT[i][j-1]] < _A[SpT[i+(1<<(j-1))][j-1]])            // RMQ
          SpT[i][j] = SpT[i][j-1];    // start at index i of length 2^(j-1)
        else                  // start at index i+2^(j-1) of length 2^(j-1)
          SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
  }
  int query(int i, int j) {
    int k = (int)floor(log((double)j-i+1) / log(2.0));    // 2^k <= (j-i+1)
    if (_A[SpT[i][k]] <= _A[SpT[j-(1<<k)+1][k]]) return SpT[i][k];
    else                                         return SpT[j-(1<<k)+1][k];
} };
int L[2*MAX_N], E[2*MAX_N], H[MAX_N], idx;

void dfs(int cur, int depth) {
  H[cur] = idx;
  E[idx] = cur;
  L[idx++] = depth;
  for (int i = 0; i < children[cur].size(); i++) {
    dfs(children[cur][i], depth+1);
    E[idx] = cur;                              // backtrack to current node
    L[idx++] = depth;
  }
}
void buildRMQ() {
  idx = 0;
  memset(H, -1, sizeof H);
  dfs(0, 0);                       // we assume that the root is at index 0
}
int main(){
  buildRMQ(); //O(n)
  RMQ rmq(2*MAX_N, L); //O(nlogn)
  REP(i,0,q){
    cin>>node1>>node2;
    if(H[node1]>H[node2]) swap(node1,node2);
    cout<<E[rmq.query(H[node1],H[node2])]<<endl; //O(log(n))
   }
}
