package expression;

public class And extends Binary {
    public And(TripleExpression first, TripleExpression second) {
        super(first, second);
    }

    @Override
    protected int apply(int first, int second) {
        return first & second;
    }
}
