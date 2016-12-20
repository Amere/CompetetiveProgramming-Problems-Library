
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;


public class Main {



public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int t = Integer.parseInt(br.readLine());
	BigInteger mod = new BigInteger("1000000007");
	int tC = 0;
	while(t-->0){
		++tC;
		String s = br.readLine();
		BigInteger three = new BigInteger("3");
		BigInteger two = new BigInteger("2");
		BigInteger b = new BigInteger(s);
		BigInteger res = three.modPow(b, mod);
		res = res.add(BigInteger.ONE);
		two = two.modPow(mod.subtract(two),mod);
		res = res.multiply(two);
		res = res.mod(mod);
		System.out.println("Case " +tC+": "+res);

		}
}

}
