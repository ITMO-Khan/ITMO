package expressions.binary;

import expressions.TripleExpression;
import expressions.EvalException;
import expressions.OverflowException;

public class CheckedSubtract extends CheckedBinary {
    public CheckedSubtract(TripleExpression first, TripleExpression second) {
        super(first, second);
    }

    @Override
    protected void check(int first, int second) throws EvalException {
        if (first >= 0 && second < 0 && first - Integer.MAX_VALUE > second) {
            throw new OverflowException();
        }
        if (first <= 0 && second > 0 && Integer.MIN_VALUE - first > -second) {
            throw new OverflowException();
        }
    }

    @Override
    protected int apply(int first, int second) {
        return first - second;
    }
}
