import java.io.*;
import java.util.*;
public class WordStatInput {
    public static void main(String[] args)
    {
	try
	{
	    LinkedHashMap<String, Integer> ans = new LinkedHashMap<>();
	    Scanner reader = new Scanner(new File(args[0]), "UTF-8");
	    while (reader.hasNextLine())
	    {
		String line = reader.nextLine();
		String[] words = line.split("[^\\p{L}\\p{Pd}']+");
		for (String word: words)
		{
		    if (!word.isEmpty())
		    {
			word = word.toLowerCase();
			ans.put(word, ans.getOrDefault(word, 0) +1);
		    }
		}
	    }
	    reader.close();
	    PrintWriter writer = new PrintWriter(new File ( args[1]), "UTF-8");
	    for (Map.Entry<String, Integer> word:ans.entrySet())
	    {
	        writer.println(word.getKey() + " " + word.getValue());
	    }
	    writer.close();
	} catch (OutOfMemoryError mem) {
            System.out.println("Memory problems");
        } catch (IOException | ArrayIndexOutOfBoundsException e) {
            System.out.println("Something went wrong");
        }
    }
}