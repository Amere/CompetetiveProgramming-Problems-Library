
/*
nCr = n!/(k!(n-k)!)
nCr = nC(n-r)


Recurrence formula:
nCr = (n-1)C(r-1) + (n-1)Cr

Adding-imposition:
nCr = (n/r)* (n-1)C(r-1)

Summation over r = 2^n
Summation over n = (n+1)C(r+1)
Summation(r form0->m) (n+r)C(r)  = (n+m+1)C(m)
Summation of squares over r = (2n)Cn
*/


//	 * 1. Pascal's Rule: recursive | Top-down approach

ll [10000][10000] comb;			//may need BigInteger, if the numbers are large, use a treemap

	ll nCr1(int n , int k)
	{
		if(n < k)
			return 0;
		if(k == 0 || k == n)
			return 1;
		if(comb[n][k] != -1)
			return comb[n][k];
		if(n - k < k)
			return comb[n][k] = nCr1(n, n - k);
		return comb[n][k] = nCr1(n - 1, k - 1) + nCr1(n - 1, k);
	}


//  * 2. Pascal's Rule: iterative | Bottom-up approach

void nCr2(int N)		// O(N * N)
	{
		comb = new long[N][N];
		comb[0][0] = 1;
		for (int i = 1; i < N; i++)
		{
			comb[i][0] = 1;
			for (int j = 1; j <= i; j++)
				comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]);		//may use mod
		}
	}

// 	 * 3. Multiplicative formula: recursive | Top-down approach

static long nCr3(int n, int k)		// O(n * k)
	{
		if(n < k)
			return 0;
		if(k == 0 || k == n)		//may add k == 1 as a base case for fast calculations
			return 1;
		if(comb[n][k] != -1)
			return comb[n][k];
		if(n - k < k)
			return comb[n][k] = nCr3(n, n - k);		//reduce k to n - k
		return comb[n][k] = n * nCr3(n - 1, k - 1) / k;
	}

// 	 * 4. Multiplicative formula: iterative

int nCr4(int N, int K)		// O(K)
	{
		if(K > N)
			return 0;
		int res = 1;
		for(int i = 1; i <= K; ++i)
			res = (N - K + i) * res / i;
		return res;
	}
