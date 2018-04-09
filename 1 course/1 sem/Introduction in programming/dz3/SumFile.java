import java.util.*;
import java.math.*;
import java.io.*;
public class SumFile {
    public static void main(String[] args) {
        try
	{	
	    Scanner reader = new Scanner(new File(args[0]), "UTF-8");
	    int ans = 0;
	    ArrayList<String> lines = new ArrayList();
	    while (reader.hasNextLine())
	    {
		String s = reader.nextLine();
		lines.add(s);
	    }
            for (String str : lines) {
                String numbers[] = str.split("\\p{javaWhitespace}");
	        for (String number : numbers) {
       	            if (!number.isEmpty())
       	            {
                        ans+=Integer.parseInt(number);
                    }
	        }
            }
	    reader.close();
	    PrintWriter writer = new PrintWriter(new File (args[1]), "UTF-8");
            writer.println(ans);
	    writer.close(); 
	}
	catch (IOException e)
	{
	    e.printStackTrace();
	}
    }
}