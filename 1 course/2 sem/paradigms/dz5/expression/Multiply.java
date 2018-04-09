package expression;

public class Multiply extends Operation {
    public Multiply(AllExpression first, AllExpression second) {
        super(first, second);
    }

    protected int makeOperation(int x, int y) {
        return x * y;
    }

    protected double makeOperation(double x, double y) {
        return x * y;
    }
}
