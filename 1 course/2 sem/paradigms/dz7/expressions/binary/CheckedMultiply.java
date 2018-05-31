package expressions.binary;

import expressions.TripleExpression;
import expressions.EvalException;
import expressions.OverflowException;

public class CheckedMultiply extends CheckedBinary {
    public CheckedMultiply(TripleExpression first, TripleExpression second) {
        super(first, second);
    }

    @Override
    protected void check(int first, int second) throws EvalException {
        if (first > 0 && second > 0 && Integer.MAX_VALUE / first < second) {
            throw new OverflowException();
        }
        if (first > 0 && second < 0 && Integer.MIN_VALUE / first > second) {
            throw new OverflowException();
        }
        if (first < 0 && second > 0 && Integer.MIN_VALUE / second > first) {
            throw new OverflowException();
        }
        if (first < 0 && second < 0 && Integer.MAX_VALUE / first > second) {
            throw new OverflowException();
        }
    }

    @Override
    protected int apply(int first, int second) {
        return first * second;
    }
}