package expression.parser;

import expression.exceptions.*;
import expression.TripleExpression;

public class MyTest {
    public static void main(String[] args) throws EvaluatingExceptions, ParserException {
        ExpressionParser exp = new ExpressionParser();
        //TripleExpression t = exp.parse("-(-(-          -5 + 16   *x*y) + 1 * z)");
        TripleExpression t = exp.parse("x+5");
        System.out.println(t.evaluate(0, 0, 0));
        //System.out.println("_________\n" + tr.evaluate(0,0,0));
    }
}
