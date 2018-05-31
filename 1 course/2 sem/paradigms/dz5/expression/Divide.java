package expression;

public class Divide extends Binary {
    Divide(CommonExpression first, CommonExpression second) {
        super(first, second);
    }

    @Override
    protected int apply(int first, int second) {
        return first / second;
    }

    @Override
    protected double apply(double first, double second) {
        return first / second;
    }
}
