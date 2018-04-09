import java.util.*;
public class Reverse {
    public static void main(String args[]) {
    	Scanner in = new Scanner(System.in);
	ArrayList<String> line = new ArrayList();
	while (in.hasNextLine()) 
	{
	    String s = in.nextLine();
	    line.add(s);
	} 
	for (int i = line.size() - 1; i >= 0; i--)
	{
	    String[] number = line.get(i).split("\\p{javaWhitespace}");
	    for (int j = number.length - 1; j >= 0; j--) {
		System.out.print(number[j] + " ");
	    }
    	System.out.println();
	}
    }
}