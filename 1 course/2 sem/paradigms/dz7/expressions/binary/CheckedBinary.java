package expressions.binary;

import expressions.TripleExpression;
import expressions.EvalException;

public abstract class CheckedBinary implements TripleExpression {
    private final TripleExpression first;
    private final TripleExpression second;

    CheckedBinary(TripleExpression first, TripleExpression second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public int evaluate(int x, int y, int z) throws EvalException {
        int firstRes = first.evaluate(x, y, z);
        int secondRes = second.evaluate(x, y, z);
        check(firstRes, secondRes);
        return apply(firstRes, secondRes);
    }

    protected abstract void check(int first, int second) throws EvalException;

    protected abstract int apply(int first, int second);
}
