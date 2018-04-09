package expression;

public class Const implements AllExpression {
    Number value;

    public Const(Number val) {
        value = val;
    }

    public int evaluate(int x) {
        return value.intValue();
    }

    public double evaluate(double x) {
        return value.doubleValue();
    }
}
