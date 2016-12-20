/* Inferenced variables are variables that could be extracted from the variables of the states
and they don't identify the state */

/* Consecutive Ranges Problem */  // O(n^2)
// we could use prevSum in parameters and will be Inferenced variable
int best(int curIdx, int lastIdx)
{
	if(curIdx == n)
		return 0;
	int sum = 10;
	for (int i = lastIdx; i <= curIdx; ++i)	// we could use array accumulation to make this in O(1)
		sum += cnt[i];
	ret = best(curIdx+1, curIdx+1) + sum * pr[curIdx];
	if(curIdx != n-1)	// as long as bigger interval is possible
		ret = min(ret, best(curIdx+1, lastIdx) );
	return ret;
}
int best(int i)	// push parameter J to loop. O(NM) time, O(N) memory
{
	if(i == n)
		return 0;
	int sum = 0;
	for (int j = i; j < n; ++j) {	// what if i allowed only maximum to match i+5?
		sum += cnt[j];
		ret = min(ret, (sum+10)*pr[j] + best(j+1));
	}
	return ret;
}


/* Nested Ranges Problem */
// **ExPlOsIvEs
int NesR(int i,int j){ //Always O(n^3)
  if (i == j || j-i == 1) {
    return 0;
  }
  if (j-i == 2) {
    return arr[i]*arr[j];
  }
  int maxi = 0;
  for (int k = i+1; k < j; k++) {
    maxi = max(maxi,NesR(i,k)+NesR(k,j)+arr[i]*arr[j]);
  }
  return maxi;
}



/* LIS using segments TREE */
/* sort the array according to the values remembering the index , let All tree node be zeros
loop through the sorted array find RMAXQ up to the index of the current element and plus one */
