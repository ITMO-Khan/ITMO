package expressions.unary;

import expressions.TripleExpression;
import expressions.EvalException;
import expressions.IllegalOperationException;

public class CheckedLog10 extends CheckedUnary {
    public CheckedLog10(TripleExpression expression) {
        super(expression);
    }

    @Override
    void check(int value) throws EvalException {
        if (value <= 0) {
            throw new IllegalOperationException("Log form negative");
        }
    }

    @Override
    int apply(int value) {
        return (int) Math.log10(value);
    }
}
