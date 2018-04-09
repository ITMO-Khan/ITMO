package expression;

public class Divide extends Operation {
    public Divide(AllExpression first, AllExpression second) {
        super(first, second);
    }

    protected int makeOperation(int x, int y) {
        return x / y;
    }

    protected double makeOperation(double x, double y) {
        return x / y;
    }
}
