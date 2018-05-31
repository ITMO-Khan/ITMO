package expression;

public abstract class Binary implements CommonExpression {
    private CommonExpression first;
    private CommonExpression second;

    Binary(CommonExpression first, CommonExpression second) {
        assert (first != null) && (second != null);
        this.first = first;
        this.second = second;
    }

    @Override
    public int evaluate(int x) {
        return apply(first.evaluate(x), second.evaluate(x));
    }

    @Override
    public double evaluate(double x) {
        return apply(first.evaluate(x), second.evaluate(x));
    }

    @Override
    public int evaluate(int x, int y, int z) {
        return apply(first.evaluate(x, y, z), second.evaluate(x, y, z));
    }

    protected abstract int apply(int first, int second);

    protected abstract double apply(double first, double second);
}
