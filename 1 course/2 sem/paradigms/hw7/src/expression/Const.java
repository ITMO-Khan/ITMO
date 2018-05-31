package expression;

public class Const implements CommonExpression {
    private final Number val;

    public Const(Number x) {
        val = x;
    }

    public double evaluate(double x) {
        return val.doubleValue();
    }

    public int evaluate(int x) {
        return val.intValue();
    }

    public int evaluate(int x, int y, int z) {
        return val.intValue();
    }
}