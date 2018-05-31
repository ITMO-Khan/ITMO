package expressions.unary;

import expressions.TripleExpression;
import expressions.EvalException;
import expressions.IllegalOperationException;
import expressions.OverflowException;

public class CheckedPow10 extends CheckedUnary {
    public CheckedPow10(TripleExpression expression) {
        super(expression);
    }

    @Override
    void check(int value) throws EvalException {
        if (value >= 10) {
            throw new OverflowException();
        }
        if (value < 0) {
            throw new IllegalOperationException("Powering is negative");
        }
    }

    @Override
    int apply(int value) {
        return (int) Math.pow(10, value);
    }
}
