import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Reverse {
    public static void main(String args[]) {
        ArrayList<String> lines = new ArrayList<String>();
        MyScanner in = new MyScanner();

        String readedLine = in.nextLine();
        while (readedLine != null) {
            lines.add(readedLine);
            readedLine = in.nextLine();
        }

        Collections.reverse(lines);
        for (String line : lines) {
            String[] number = line.split("\\p{javaWhitespace}");

            for (int j = number.length - 1; j >= 0; j--) {
                System.out.print(number[j] + " ");
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