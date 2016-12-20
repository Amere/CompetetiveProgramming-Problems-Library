#define NOT(x)    (1^(x))

const int MAX = 30*2*2+9;
int adjMat[MAX][MAX];
int assigned_val[MAX];
int n, m;

// acceptable values: (0, 1), (1, 0), (1, 1)
void add_or(int a, int b)
{
	adjMat[NOT(a)][b] = 1;
	adjMat[NOT(b)][a] = 1;
}

// acceptable values: (0, 1), (1, 0)
void add_or_not_both(int a, int b)
{
	// CNF: (a v b) & (!a v !b)  ==> E.g. can't be true for (1, 1) / (0, 0)
	add_or(a, b);
	add_or(NOT(a), NOT(b));
}
void force_value(int i, bool b)
{
	if(b)
		adjMat[NOT(i)][i] = 1;
	else
		adjMat[i][NOT(i)] = 1;
}
// -1 (can't assign), 0 (false), 1 (true), 2 (assign later)
int get_value(int i)
{
	int is_off = adjMat[i][NOT(i)], is_on = adjMat[NOT(i)][i];

	if(is_off && is_on)	return -1;
	if(is_off) return 0;
	if(is_on) return 1;
	return 2;
}
bool is_solvable()
{
	for(int i = 0; i < n; i+=2)
		if (get_value(i) == -1)
			return false;
	return true;
}
void assign_on_dfs(int i)
{
	if (assigned_val[i] != -1)
		return;

	assigned_val[i] = 1, assigned_val[NOT(i)] = 0;

	lp(j, n) if(j != i && adjMat[i][j])
		assign_on_dfs(j);
}

void assign_values()
{
	lp(i, n) if (assigned_val[i] == -1)
	{
		if (get_value(i) == 0)
		{
			assigned_val[i] = 0, assigned_val[NOT(i)] = 1;
			continue;
		}
		assign_on_dfs(i);
	}
}
int main1() {
#ifndef ONLINE_JUDGE
	freopen("test.txt", "rt", stdin);
#endif

	while(cin>>n>>m && (n+m))
	{
		clr(adjMat, 0);
		clr(assigned_val, -1);
		lp(i, m)
		{
			cin>>a>>b;
			add_or(a, b);
		}
		lp(k, n) lp(i, n) lp(j, n)	// transitive closure
			adjMat[i][j] |= adjMat[i][k] & adjMat[k][j];

		if (!is_solvable())
		{
			cout<<"no solution\n";
			continue;
		}

		assign_values();	// solution now in assigned_val array
	}

	return 0;
}
