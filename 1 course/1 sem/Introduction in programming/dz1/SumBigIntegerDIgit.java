import java.util.*;
import java.math.*;
import java.io.*;
class SumBigInteger {
    public static void main(String[] args) {
	BigInteger ans = BigInteger.ZERO;
	for ( String arg : args) {
	    String numbers[]  = arg.split("\\p{javaWhitespace}");
	    for (String number : numbers) {
		if (!number.isEmpty()) {
		    ans = ans.add(new BigInteger(number));
		}
	    }
	}
    System.out.println(ans);
    }
}