import java.util.*;
import java.math.*;
import java.io.*;
public class test {
    public static void main(String[] args) {
	char word;
	int ans = 0;
	for (String str : args) {
            String numbers[] = str.split("\\p{javaWhitespace}");
	    for (String number : numbers) {
       	        if (!number.isEmpty())
       	        {//number = number.toLowerCase();
		    for (int i = 0; i < number.length(); i++){
		    ans+=(int)number.charAt(i) - (int)'a' + 1;
		    }
                }
	    }
        }
	
	System.out.print(ans);
    }
}