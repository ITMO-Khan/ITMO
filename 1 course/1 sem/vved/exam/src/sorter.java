import java.io.*;
import java.util.ArrayList;
import java.util.Map;
import java.util.TreeMap;

public class sorter {
    private static Map<Integer, List<String>> map = new TreeMap<>();

    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new FileReader(new File(args[0])));
            String line = reader.readLine();
            while (line != null) {
                parse(line);
                line = reader.readLine();
            }

            reader.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

}
    private static void parse(String line) {
        switch (line.charAt(0)) {
            case 'a':
                add(line.substring(4));
                break;
            case 'r':
                remove(line.substring(7));
                break;
            case 'p':
                print(line.substring(6));
                break;
        }
    }

    private static void add(String s) {
        int spaceIndex = s.indexOf(" ");
        int index = Integer.parseInt(s.substring(0, spaceIndex));
        s = s.substring(spaceIndex + 1);

        List<String> stringList = map.get(index);
        if (stringList == null) {
            stringList = new ArrayList<>();
            map.put(index, stringList);
        }

        stringList.add(s);
    }

    private static void remove(String substring) {
        map.remove(Integer.parseInt(substring));
    }

    private static void print(String fileName) {
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter(new File(fileName)));

            for (Map.Entry<Integer, List<String>> pair : map.entrySet()) {
                writer.write(pair.getKey() + " ");
                for (String str : pair.getValue()){
                    writer.write(str);
                }
                writer.newLine();
            }

            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
