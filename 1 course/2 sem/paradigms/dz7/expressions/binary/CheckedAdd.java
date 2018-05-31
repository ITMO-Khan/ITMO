package expressions.binary;

import expressions.TripleExpression;
import expressions.OverflowException;

public class CheckedAdd extends CheckedBinary {
    public CheckedAdd(TripleExpression first, TripleExpression second) {
        super(first, second);
    }

    @Override
    protected void check(int first, int second) throws OverflowException {
        if (first > 0 && Integer.MAX_VALUE - first < second) {
            throw new OverflowException();
        }
        if (first < 0 && Integer.MIN_VALUE - first > second) {
            throw new OverflowException();
        }
    }

    @Override
    protected int apply(int first, int second) {
        return first + second;
    }
}
