package expression;

public class Divide extends Binary {
    public Divide(TripleExpression first, TripleExpression second) {
        super(first, second);
    }

    @Override
    protected int apply(int first, int second) {
        return first / second;
    }
}
