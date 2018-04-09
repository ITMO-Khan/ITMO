import java.util.*;
import java.math.*;
import java.io.*;
public class SumBigInteger {
    public static void main(String[] args) {
	int k = 0,j = 0; 
        BigInteger ans = BigInteger.ZERO;
        for (String str : args) {
            String numbers[] = str.split("\\p{javaWhitespace}");
	    for (String number : numbers) {
       	        if (!number.isEmpty())
       	        {
                    ans = ans.add(new BigInteger(number));
                }
	    }
        }
    System.out.println(ans);
    }
}