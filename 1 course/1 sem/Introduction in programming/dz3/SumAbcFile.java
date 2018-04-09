import java.util.*;
import java.nio.charset.*;
import java.math.*;
import java.io.*;
public class SumAbcFile {
    public static void main(String[] args) {
	Scanner reader;
	int ans = 0;
	try{	
	    reader = new Scanner(new File(args[0]), "UTF-8");
	    ArrayList<String> lines = new ArrayList();
	    	while (reader.hasNextLine()){
		    String s = reader.nextLine();
		    lines.add(s);
	    	}
            	for (String str : lines) {
                    String words[] = str.split("\\p{javaWhitespace}");
	            for (String word : words) {
       	            	if (!word.isEmpty()){
			    int d = 0;
			    int z = 0;
			    word = word.toLowerCase();
			    for (int i = 0; i < word.length(); i++){
			    	if ((word.charAt(i) != '-') && (word.charAt(i) != '+')){
			    	d = d * 10;
			    	d += (int)word.charAt(i) - (int)'a';
			    } 
			    if (word.charAt(i) == '-') { 
				z++; 
			    } 
			}
			if (z != 0) {
			    d *= - 1; 
			}
                        ans += d;
			z = 0;
                    }
	        }
            }
	    reader.close();
	} catch (IOException | ArrayIndexOutOfBoundsException e) {
            System.out.println("Something went wrong");
    	}
	PrintWriter writer;
	try{
	    writer = new PrintWriter(new File (args[1]), "UTF-8");
            writer.println(ans);
	    writer.close();
	} catch (IOException | ArrayIndexOutOfBoundsException e) {
            System.out.println("Something went wrong");
        } 
    }
}