package expressions.unary;

import expressions.EvalException;
import expressions.OverflowException;
import expressions.TripleExpression;

public class CheckedNegate extends CheckedUnary {
    public CheckedNegate(TripleExpression expression) {
        super(expression);
    }

    @Override
    void check(int value) throws EvalException {
        if (value == Integer.MIN_VALUE) {
            throw new OverflowException();
        }
    }

    @Override
    int apply(int value) {
        return -value;
    }
}
