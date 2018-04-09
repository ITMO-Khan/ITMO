package expression;

public class Add extends Operation {
    public Add(AllExpression first, AllExpression second) {
        super(first, second);
    }

    protected double makeOperation(double x, double y) {
        return x + y;
    }

    protected int makeOperation(int x, int y) {
        return x + y;
    }
}
