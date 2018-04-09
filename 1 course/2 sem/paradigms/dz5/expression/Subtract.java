package expression;

public class Subtract extends Operation {
    public Subtract(AllExpression first, AllExpression second) {
        super(first, second);
    }

    protected double makeOperation(double x, double y) {
        return x - y;
    }

    protected int makeOperation(int x, int y) {
        return x - y;
    }
}
