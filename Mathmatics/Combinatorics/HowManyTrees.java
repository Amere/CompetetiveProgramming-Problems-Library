
import java.math.BigInteger;
import java.util.Scanner;


public class Main {


static BigInteger nCr4(int N, int K)		// O(K)
{
	if(K>N)
		return BigInteger.ZERO;
	BigInteger res = BigInteger.ONE;
	for(int i = 1; i <= K; ++i)
		res = res.multiply(BigInteger.valueOf(N - K + i)).divide(BigInteger.valueOf(i));
	return res;
}

public static void main(String[] args) {
	 Scanner in = new Scanner(System.in);
	  while(in.hasNext())
	  {
	   int n = in.nextInt();
	   System.out.println(nCr4(2*n,n).divide(BigInteger.valueOf(n+1)));
	  }
}
}
