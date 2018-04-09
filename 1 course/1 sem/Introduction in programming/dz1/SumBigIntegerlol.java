import java.util.*;
import java.math.*;
import java.io.*;
public class SumBigInteger {
    public static void main(String[] args) {
	BigInteger ans = BigInteger.ZERO;
	for (String arg : args) {
	    for (int i = 0; i < arg.length(); i++) {
		char c = '\0';
	        if ((!Character.isDigit(arg.charAt(i))) && (arg.charAt(i)!= '-')) arg = arg.replace(arg.charAt(i),c); 
	    }
	}
	for ( String arg : args) {
	    String numbers[]  = arg.split("\\p{javaSpaceChar}");
	    for (String number : numbers) {
		if (!number.isEmpty()) {
		    ans = ans.add(new BigInteger(number));
		}
	    }
	}
    System.out.println(ans);
    }
}