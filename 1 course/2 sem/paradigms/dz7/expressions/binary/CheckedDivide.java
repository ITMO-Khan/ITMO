package expressions.binary;

import expressions.TripleExpression;
import expressions.EvalException;
import expressions.IllegalOperationException;
import expressions.OverflowException;

public class CheckedDivide extends CheckedBinary {
    public CheckedDivide(TripleExpression first, TripleExpression second) {
        super(first, second);
    }

    @Override
    protected void check(int first, int second) throws EvalException {
        if (second == 0) {
            throw new IllegalOperationException("Division by zero");
        }
        if (first == Integer.MIN_VALUE && second == -1) {
            throw new OverflowException();
        }
    }

    @Override
    protected int apply(int first, int second) {
        return first / second;
    }
}
