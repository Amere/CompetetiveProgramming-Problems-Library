/*
	 * - Complexity O(n log n)
	 * - Stable sort algorithm
	 * - Can be used to compute inversion index
	 */
int a[];
 void mergeSort(int b, int e)
	{
		if(b < e)
		{
			int q = (b + e) / 2;
			mergeSort(b, q);
			mergeSort(q + 1, e);
			merge(b, q, e);
		}
	}

    static void merge(int b, int mid, int e)
    {
       int n1 = mid - b + 1;
       int n2 = e - mid;
       int[] L = new int[n1+1], R = new int[n2+1];

       for(int i = 0; i < n1; i++)  L[i] = a[b + i];
       for(int i = 0; i < n2; i++)  R[i] = a[mid + 1 + i];
       L[n1] = R[n2] = INF;

       for(int k = b, i = 0, j = 0; k <= e; k++)
    	   if(L[i] <= R[j])
    		   a[k] = L[i++];
    	   else
    		   a[k] = R[j++];
    }
