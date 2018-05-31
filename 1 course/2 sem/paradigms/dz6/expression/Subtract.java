package expression;

public class Subtract extends Binary {
    public Subtract(TripleExpression first, TripleExpression second) {
        super(first, second);
    }

    @Override
    protected int apply(int first, int second) {
        return first - second;
    }
}
