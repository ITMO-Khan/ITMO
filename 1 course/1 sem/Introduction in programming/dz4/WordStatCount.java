import java.io.*;
import java.util.*;

public class WordStatCount {
    public static void main(String[] args)
    {
	Map<String, Integer> ans = new LinkedHashMap<>();
	try{
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
	} catch (OutOfMemoryError mem) {
            System.out.println("Memory problems");
        } catch (IOException | ArrayIndexOutOfBoundsException e) {
            System.out.println("Something went wrong");
        } 
 	    ArrayList<Pair> sortStat = new ArrayList<>();
            for (Map.Entry<String, Integer> word : ans.entrySet()) {
                sortStat.add(new Pair(word.getKey(), word.getValue()));
            }

            for (int i = 0; i < sortStat.size(); ++i) {
                for (int j = sortStat.size() - 1; j > 0; --j) {
                    if (sortStat.get(j - 1).val > sortStat.get(j).val) {
                        Pair tmp = sortStat.get(j);
                        sortStat.set(j, new Pair(sortStat.get(j - 1).key, sortStat.get(j - 1).val));
                        sortStat.set(j - 1, new Pair(tmp.key, tmp.val));
                    }
                }
            }
	try{
            PrintWriter output = new PrintWriter(new File (args[1]), "UTF-8");
            for (Pair word : sortStat) {
                output.println(word.key + " " + word.val);
            }
            output.close();
        } catch (OutOfMemoryError mem) {
            System.out.println("Memory problems");
        } catch (IOException | ArrayIndexOutOfBoundsException e) {
            System.out.println("Something went wrong");
        } 
    }
    static class Pair {
        String key;
        Integer val;
        public Pair() {
            key = "";
            val = 0;
        }
        public Pair(String key, Integer val) {
            this.key = key;
            this.val = val;
        }
    }
}
