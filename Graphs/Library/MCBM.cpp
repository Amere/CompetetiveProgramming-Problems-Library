
//	Maximum Cardinality Bipartite Matching
//		1.Augmenting Path Algorithm
//		2.Hopcroft Karp's Algorithm
//		3.Max Flow based Solution

#define MAX 1000000
vi match;
int n,m,V; //n(left) + m(right) = V
vi AdjList[MAX]
bool vis[MAX]

//	1.Augmenting Path Algorithm O(VE)

int aug(int u)	//returns 1 if an augment path is found
	{
		vis[u] = 1;
		for(int i = 0 l i<AdjList[i].size() ; i++){
      int v = AdjList[u][i];
			if(match[v] == -1 || !vis[match[v]] && aug(match[v]))
			{
				match[v] = u;
				return 1;
			}
    }
		return 0;
	}

  int main(){
    int matches = 0;
    match.assign();
    for (int i = 0; i < n; i++) {
      clr(vis);

    }
    return 0;
  }


//	2.Hopcroft Karp's Algorithm O(sqrt(V)E)
//	NOTE: vertices of left/right set start from 1 (u, v > 0)

vi pair_U,pair_V,dist,AdjList[MAX];
int n,m,V; //n(left) + m(right) = V
bool vis[MAX]
const int NIL = 0, INF = 1e9;

int hopcroftKarp(){
  pair_U.assign(n+1,NIL);
  pair_V.assign(m+1,NIL);
  dist.assign();

  int matching = 0;
  while (bfs()) {
    for (int u = 1; u <= n; u++) {
      if (!pair_U[u] && dfs(u)) {
        ++matching;
      }
    }
  }
  return matching;
}

int bfs(){
  queue<int> q;
  for (int u = 1; u <= n; u++) {
    if (pair_U[u] == NIL) {
      dist[u] = 0;
      q.add(u);
    }else{
      dist[u] = INF;
    }
  }
  dist[NIL] = INF;
  while(!q.isEmpty())
		{
			int u = q.remove();
			if(dist[u] < dist[NIL])
				for(int v : adjList[u])
					if(dist[pair_V[v]] == INF)
					{
						dist[pair_V[v]] = dist[u] + 1;
						q.add(pair_V[v]);
					}
		}
		return dist[NIL] != INF;
}

int dfs(int u)
	{
		if(u == NIL)
			return true;

		for(int i=0 ;i<adjList[u].size();i++){
      int v = AdjList[u][i];
			if(dist[pair_V[v]] == dist[u] + 1 && dfs(pair_V[v]))
			{
				pair_U[u] = v;
				pair_V[v] = u;
				return 1;
			}
    }
		dist[u] = INF;
		return 0;
	}

  //	3.Max Flow based Solution
  	/*
  	 * ->	add two virtual vertices s and t
  	 * ->	make the graph directed from left to right
  	 * ->	make the capacity of all edges = 1
  	 * ->	max flow = MCBM
  	 */
