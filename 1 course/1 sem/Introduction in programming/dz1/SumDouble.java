import java.util.*;
import java.math.*;
import java.io.*;
public class SumDouble {
    public static void main(String[] args) {
	int k = 0,j = 0; 
        Double ans = 0.0;
        for (String str : args) {
            String numbers[] = str.split("\\p{javaWhitespace}");
	    for (String number : numbers) {
       	        if (!number.isEmpty())
       	        {
                    ans+=Double.parseDouble(number);
                }
	    }
        }
    System.out.println(ans);
    }
}