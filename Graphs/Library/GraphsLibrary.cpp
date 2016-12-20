#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int, int> ii;      // In this chapter, we will frequently use these
typedef vector<ii> vii;      // three data type shortcuts. They may look cryptic
typedef vector<int> vi;   // but shortcuts are useful in competitive programming

#define DFS_WHITE -1 // normal DFS, do not change this with other values (other than 0),
// because we usually use memset with conjunction with DFS_WHITE
#define DFS_BLACK 1
#define DFS_GRAY 2




/* DFS */
vector<vii> AdjList;
vi dfs_num;
void dfs(int u){
  dfs_num[u] = DFS_BLACK;
  for (int i=0;  i < (int)AdjList[u].size(); i++) {
    ii child = AdjList[u][i];
    if (dfs_num[child.first]==DFS_WHITE)
      dfs(child.first);
  }
}






/* Flood Fill (Coloring) on implict graph */
int grid[R][C];
int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1}; //S,SE,E,NE,N,NW,W,SW
int floodFill(int r,int c,char c1,char c2){ //returns the size of the connected component
    if(r<0 || r>=R || c<0 || c>=C) return 0;
    if(grid[r][c]!=c1) return c1;
    int ans = 1;
    grid[r][c] = c2;
    for (int i = 0; i < 8; i++) {
      ans+=floodFill(r+dr[i],c+dc[i],c1,c2);
    }
    return ans;
}





/* Flood Fill on a usual graph */
void floodfill(int u, int color) {
  dfs_num[u] = color;                            // not just a generic DFS_BLACK
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE)
      floodfill(v.first, color);
    }
}





/* Topological Sort using DFS - ON DAGS*/
vi ts; /* IMPORTNANT NOTE */ //we should reverse ts when printing or dealling with the result
void dfs2(int u){
  dfs_num[u] = DFS_BLACK;
  for (int i=0;  i < (int)AdjList[u].size(); i++) {
    ii child = AdjList[u][i];
    if (dfs_num[child.first]==DFS_WHITE)
      dfs2(child.first);
  }
  ts.push_back(u);
}





/* Topological Sort using Kahn's algorithm (Modified BFS) - ON DAGS */
void khansAlgorithm(){ //NOTE: Main Method
  /* IDEA
  use a priority queue with your own CMP function to get the desired type of
  TopSort as if used an ordinary priorityQueue we will get the topSort
  in ascending order ...
  NOTE*
  Idea here is to enqueue the vertices with with indegree zero in the (priority queue)
  then print it and delete all outgoing edges from it if this causes any vertex to have
  and indegree of Zero then enqueue it and so on till the queue is empty */
  map<int,int> indegree;
  vector<vii> AdjList;
  // While getting the input      ** indegree[vertex]++;
  priority_queue<int> q;
  vi ts;
  for (int i = 0; i < V; i++) {
    if(indegree[i]==0) q.push(-i);
  }
  while (!q.empty) {
    int u = -q.front(); q.pop();
    ts.push_back(u);
    for(int i=0;i<AdjList[u].size()){
      ii child = AdjList[u][i];
      indegree[child.first]--;
      if(indegree[child.first]==0){
        q.push(-child.first);
      }
    }
  }
}








/* GraphCheck and the properties of Edges */
vi dfs_parent;      // to differentiate real back edge versus bidirectional edge
void graphCheck(int u) {               // DFS for checking graph edge properties
  dfs_num[u] = DFS_GRAY;   // color this as DFS_GRAY (temp) instead of DFS_BLACK
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE) {     // Tree Edge, DFS_GRAY to DFS_WHITE
      dfs_parent[v.first] = u;                  // parent of this children is me
      graphCheck(v.first);
    }
    else if (dfs_num[v.first] == DFS_GRAY) {             // DFS_GRAY to DFS_GRAY
      if (v.first == dfs_parent[u])          // to differentiate these two cases
        printf(" Bidirectional (%d, %d) - (%d, %d)\n", u, v.first, v.first, u);
      else  // the most frequent application: check if the given graph is cyclic
        printf(" Back Edge (%d, %d) (Cycle)\n", u, v.first);
    }
    else if (dfs_num[v.first] == DFS_BLACK)             // DFS_GRAY to DFS_BLACK
      printf(" Forward/Cross Edge (%d, %d)\n", u, v.first);
  }
  dfs_num[u] = DFS_BLACK;     // after recursion, color this as DFS_BLACK (DONE)
}








/* Articulation points and Bridges */
vi dfs_low;       // additional information for articulation points/bridges/SCCs
vi articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;

void articulationPointAndBridge(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE) {                          // a tree edge
      dfs_parent[v.first] = u;
      if (u == dfsRoot) rootChildren++;  // special case, count children of root

      articulationPointAndBridge(v.first);

      if (dfs_low[v.first] >= dfs_num[u])              // for articulation point
        articulation_vertex[u] = true;           // store this information first
      if (dfs_low[v.first] > dfs_num[u])                           // for bridge
        printf(" Edge (%d, %d) is a bridge\n", u, v.first);
      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);       // update dfs_low[u]
    }
    else if (v.first != dfs_parent[u])       // a back edge and not direct cycle
      dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);       // update dfs_low[u]
} }








/* Strongly connected component on a Directed Graph */
vi S, visited;                                    // additional global variables
int numSCC;

void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
  S.push_back(u);           // stores u in a vector based on order of visitation
  visited[u] = 1;
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE)
      tarjanSCC(v.first);
    if (visited[v.first])                                // condition for update
      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
  }

  if (dfs_low[u] == dfs_num[u]) {         // if this is a root (start) of an SCC
    printf("SCC %d:", ++numSCC);            // this part is done after recursion
    while (1) {
      int v = S.back(); S.pop_back(); visited[v] = 0;
      printf(" %d", v);
      if (u == v) break;
    }
    printf("\n");
} }









/* Kruskal's Algorithm to find Minimum Spanning Tree */
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { numSets--;
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};
void kruskals(){ //inside main method
vector< pair<int, ii> > EdgeList;   // (weight, two vertices) of the edge
  for (int i = 0; i < E; i++) {
    scanf("%d %d %d", &u, &v, &w);            // read the triple: (u, v, w)
    EdgeList.push_back(make_pair(w, ii(u, v)));                // (w, u, v)
    AdjList[u].push_back(ii(v, w));
    AdjList[v].push_back(ii(u, w));
  }
  sort(EdgeList.begin(), EdgeList.end()); // sort by edge weight O(E log E)
                      // note: pair object has built-in comparison function
  int mst_cost = 0;
  UnionFind UF(V);                     // all V are disjoint sets initially
  for (int i = 0; i < E; i++) {                      // for each edge, O(E)
    pair<int, ii> front = EdgeList[i];
    if (!UF.isSameSet(front.second.first, front.second.second)) {  // check
      mst_cost += front.first;                // add the weight of e to MST
      UF.unionSet(front.second.first, front.second.second);    // link them
  } }                       // note: the runtime cost of UFDS is very light
  // note: the number of disjoint sets must eventually be 1 for a valid MST
  printf("MST cost = %d (Kruskal's)\n", mst_cost);
}








/* Prim's Algorithm to fin the Minimum Spanning Tree O(ElogV) */
vector<vii> AdjList;
vi taken;                                  // global boolean flag to avoid cycle
priority_queue<ii> pq;            // priority queue to help choose shorter edges

void process(int vtx) {    // so, we use -ve sign to reverse the sort order
  taken[vtx] = 1;
  for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
    ii v = AdjList[vtx][j];
    if (!taken[v.first]) pq.push(ii(-v.second, -v.first));
} }
void prims(){ //NOTE : MAIN METHOD
  AdjList.assign(V, vii());
  taken.assign(V, 0);                // no vertex is taken at the beginning
    process(0);   // take vertex 0 and process all edges incident to vertex 0
    mst_cost = 0;
    while (!pq.empty()) {  // repeat until V vertices (E=V-1 edges) are taken
      ii front = pq.top(); pq.pop();
      u = -front.second, w = -front.first;  // negate the id and weight again
      if (!taken[u])                 // we have not connected this vertex yet
        mst_cost += w, process(u); // take u, process all edges incident to u
    }                                        // each edge is in pq only once!
    printf("MST cost = %d (Prim's)\n", mst_cost);
}










/* Printing the path associated with BFS */
vi p;                                 // addition: the predecessor/parent vector
void printPath(int u) {    // simple function to extract information from `vi p'
  if (u == s) { printf("%d", u); return; }
  printPath(p[u]);   // recursive call: to make the output format: s -> ... -> t
  printf(" %d", u); }

int main(){
  /* BFS */
  vector<vii> AdjList;
  queue<int> q;
  vi d(AdjList.size(),INF);
  int source = 0;
  int color[V];
  color[source] = 0;
  bool isBiparitite = true;
  d[source] = 0; /*distance from the source to the source is 0 */ q.push(s);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = 0; i < AdjList[u].size(); i++) {
      ii child = AdjList[u][i];
      if (d[child.first]==INF) {
        d[child.first] = d[u] + 1;
        p[child.first] = u;
        q.push(child.first);
        color[child.first]=1-color[u];
      }else
        if(color[u]==color[child.first]) isBiparitite=false;
    }
  }



  /* Connected Components on undirected graph */
  int numCC = 0;
  for (int i = 0; i < AdjList.size(); i+) {
    if (dfs_num[i]==DFS_WHITE) {
    numCC++;
    dfs(i);
    }
  }




  /* SSSP on weighted graph Dijkestras*/
  vi dist(V, INF); dist[s] = 0;                    // INF = 1B to avoid overflow
    priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
                               // ^to sort the pairs by increasing distance from s
    while (!pq.empty()) {                                             // main loop
      ii front = pq.top(); pq.pop();     // greedy: pick shortest unvisited vertex
      int d = front.first, u = front.second;
      if (d > dist[u]) continue;   // this check is important, see the explanation
      for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];                       // all outgoing edges from u
        if (dist[u] + v.second < dist[v.first]) {
          dist[v.first] = dist[u] + v.second;                 // relax operation
          pq.push(ii(dist[v.first], v.first));
    } } }  // note: this variant can cause duplicate items in the priority queue

    for (int i = 0; i < V; i++) // index + 1 for final answer
      printf("SSSP(%d, %d) = %d\n", s, i, dist[i]);




  /* SSSP IF THERE is a Negative Cycle */
      // Bellman Ford routine
  vi dist(V, INF); dist[s] = 0;
  for (int i = 0; i < V - 1; i++)  // relax all E edges V-1 times, overall O(VE)
    for (int u = 0; u < V; u++)                        // these two loops = O(E)
      for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];        // we can record SP spanning here if needed
        dist[v.first] = min(dist[v.first], dist[u] + v.second);         // relax
      }

  bool hasNegativeCycle = false;
  for (int u = 0; u < V; u++)                          // one more pass to check
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
      ii v = AdjList[u][j];
      if (dist[v.first] > dist[u] + v.second)                 // should be false
        hasNegativeCycle = true;     // but if true, then negative cycle exists!
    }
  printf("Negative Cycle Exist? %s\n", hasNegativeCycle ? "Yes" : "No");

  if (!hasNegativeCycle)
    for (int i = 0; i < V; i++)
      printf("SSSP(%d, %d) = %d\n", s, i, dist[i]);





      /* All pairs shortest path using FloyWarshell DP solution */

  int AdjMatrix[200][200];
  int p[200][200];
  for(int i=0 ; i<V ; i++)
    for(int j=0 ; j<V ;j++)
      p[i][j] = i;
  for (int k = 0; k < V; k++) // common error: remember that loop order is k->i->j
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++){
                 if(AdjMatrix[i][k] + AdjMatrix[k][j]<AdjMatrix[i][j]){
                     AdjMatrix[i][j] =  AdjMatrix[i][k] + AdjMatrix[k][j];
                     p[i][j] = p[k][j];
                   }
             }
  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      printf("APSP(%d, %d) = %d\n", i, j, AdjMatrix[i][j]);

/*


void printPath(int i,int j){
    if (i!=j) {
        printPath(i,p[i][j]);
    }
    cout<<j+1<<" ";
}

*/


  return 0;
}
