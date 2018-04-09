import java.util.*;
import java.math.*;
import java.io.*;
public class Sum {
    public static void main(String[] args) {
        int ans = 0;
        for (String str : args) {
            String numbers[] = str.split("\\p{javaWhitespace}");
	    for (String number : numbers) {
       	        if (!number.isEmpty())
       	        {
                    ans+=Integer.parseInt(number);
                }
	    }
        }
    System.out.println(ans);
    }
}