package expression;

public class Variable implements AllExpression {
    String var;

    public Variable(String v) {
        var = v;
    }

    public int evaluate(int x) {
        return x;
    }

    public double evaluate(double x) {
        return x;
    }
}
