import expressions.TripleExpression;
import parser.ExpressionParser;

public class Main {
    public static void main(String[] args) {
        ExpressionParser parser = new ExpressionParser();
        try {
            String testStr = "log10";

            TripleExpression expression = parser.parse(testStr);
            System.err.println(expression.evaluate(10, 0, 0));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
