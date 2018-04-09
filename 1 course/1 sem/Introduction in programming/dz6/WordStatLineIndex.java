import java.io.*;
import java.util.*;

public class WordStatLineIndex {
    public static void main(String[] args) {
        Scanner reader = null;
        PrintWriter writer = null;
        TreeMap<String, ArrayList<Pair>> ans = new TreeMap<>();
	try {
            Integer wordCount, lineCount = 0;

            reader = new Scanner(new File(args[0]), "UTF-8");
            while (reader.hasNextLine()) {
                String line = reader.nextLine();
                String[] words = line.split("[^\\p{L}\\p{Pd}']+");

                ++lineCount;
                wordCount = 0;
                for (String word : words) {
                    word = word.toLowerCase();
                    if (word.isEmpty()) {
                        continue;
                    }
                    if (ans.get(word) == null) {
                        ArrayList<Pair> toPut = new ArrayList<>();
                        toPut.add(new Pair(lineCount, ++wordCount));
                        ans.put(word, toPut);
                    }
                    else {
                        ans.get(word).add(new Pair(lineCount, ++wordCount));
                    }
                }
            }
	}catch (IOException | ArrayIndexOutOfBoundsException e) {
            e.printStackTrace();
        } finally {
            reader.close();
        }
	try{
            writer = new PrintWriter(new File (args[1]), "UTF-8");
            for (Map.Entry<String, ArrayList<Pair>> word : ans.entrySet()) {
                writer.print(word.getKey() + " " + word.getValue().size());
                for (Pair i : word.getValue()) {
                    writer.print(" " + i.x + ":" + i.y);
                }
                writer.println();
            }
        }
        catch (IOException | ArrayIndexOutOfBoundsException e) {
            e.printStackTrace();
        } finally {
            writer.close();
        }
    }

    static class Pair {
        Integer x;
        Integer y;
        public Pair() {
            this.x = this.y = 0;
        }
        public Pair(Integer x, Integer y) {
            this.x = x;
            this.y = y;
        }
    }
}
