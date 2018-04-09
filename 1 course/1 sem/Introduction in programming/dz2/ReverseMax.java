import java.util.*;
public class ReverseMax {
    public static void main(String args[]) {
    	Scanner in = new Scanner(System.in);
	ArrayList<String> lines = new ArrayList();
	while (in.hasNextLine()) 
	{
	    String s = in.nextLine();
	    lines.add(s);
	}
	int width = 0;
	ArrayList<ArrayList<Integer>> numLines = new ArrayList(); 
	for (String line : lines) 
	{
	    ArrayList<Integer> numLine = new ArrayList();
	    if (line.isEmpty()) 
	    {
		numLines.add(numLine);
		continue;
	    }
	    String numbers[] = line.split("\\p{javaWhitespace}+");
	    for (String number: numbers) 
	    {
		numLine.add(Integer.parseInt(number));
	    }
	    numLines.add(numLine);
	    width = Math.max(width, numbers.length);
	}
	int iMax[] = new int[lines.size()];
	for (int i = 0; i < iMax.length; i++) 
	{
	    iMax[i] = Integer.MIN_VALUE;
	}
	int jMax[] = new int[width];
	for (int j = 0; j < jMax.length; j++) 
	{
	    jMax[j] = Integer.MIN_VALUE;
	}
	for (int i = 0; i < lines.size(); i++)
	{
	    ArrayList<Integer> numbers = numLines.get(i);
	    for (int j = 0; j < numbers.size(); j++)
	    {
		iMax[i] = Math.max(iMax[i], numbers.get(j));
		jMax[j] = Math.max(jMax[j], numbers.get(j));
	    }
	}
	for (int i = 0; i < lines.size(); i++, System.out.println()) 
	{
	    ArrayList<Integer> numbers = numLines.get(i);
	    for (int j = 0; j < numbers.size(); j++)
	    {
		System.out.print(Math.max(iMax[i], jMax[j]) + " ");
	    }
	}
    }
}