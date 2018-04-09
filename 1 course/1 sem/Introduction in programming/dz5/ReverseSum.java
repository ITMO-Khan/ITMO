import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class ReverseSum {
    public static void main(String[] args) {
        ArrayList<ArrayList<Integer>> lines = new ArrayList<>();
        MyScanner in = new MyScanner();

        Integer width = 0;
        String readedLine = in.nextLine();
        while (readedLine != null) {
            ArrayList<Integer> intLine = new ArrayList<>();
            if (!readedLine.isEmpty()) {
                String[] ints = readedLine.split("[^-\\p{Digit}]+");
                for (String curInt : ints) {
                    intLine.add(Integer.parseInt(curInt));
                }
            }
            lines.add(intLine);
            width = Math.max(width, intLine.size());
            readedLine = in.nextLine();
        }

        Integer[] sum_i = new Integer[lines.size()];
        for (Integer i = 0; i < lines.size(); ++i) {
            sum_i[i] = 0;
        }
        Integer[] sum_j = new Integer[width];
        for (Integer j = 0; j < width; ++j) {
            sum_j[j] = 0;
        }

        for (int i = 0; i < lines.size(); ++i) {
            for (int j = 0; j < lines.get(i).size(); ++j) {
                sum_i[i] += lines.get(i).get(j);
                sum_j[j] += lines.get(i).get(j);
            }
        }

        for (int i = 0; i < lines.size(); ++i) {
            for (int j = 0; j < lines.get(i).size(); ++j) {
                System.out.print(sum_i[i] + sum_j[j] - lines.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }

    static class MyScanner {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

        String nextLine() {
            try {
                return input.readLine();
            } catch (IOException e) {
                return null;
            }
        }
    }
}