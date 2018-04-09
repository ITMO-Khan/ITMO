import java.util.*;
import java.math.*;
import java.io.*;

public class SumBigInteger {
    public static void main(String[] args) {
	String s = "";
	int k = 0;
	int j = 0;
	BigInteger ans = BigInteger.ZERO;
	while ( k < args.length ) {
	    args[k] = " " + args[k];
	    int i = args[k].length() - 1;
	    while (i >= 0) {
		if (Character.isDigit(args[k].charAt(i)) && !Character.isSpaceChar(args[k].charAt(i))) {
		    s = args[k].charAt(i) + s;
		} else {
		    if ((!s.isEmpty()) && (args[k].charAt(i) == '-')) s = args[k].charAt(i) + s;
		    if (!s.isEmpty()) {
			ans = ans.add(new BigInteger(s));
			s = "";
		    }
		} 
		i--;
	    }
	    k++;
	}
    System.out.println(ans);
    }
}