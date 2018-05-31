package expressions.unary;

import expressions.TripleExpression;
import expressions.EvaluateException;
import operations.Operations;

public class Negate<T> extends Unary<T> {
    public Negate(TripleExpression<T> expression, Operations<T> operations) {
        super(expression, operations);
    }

    @Override
    T apply(T value) throws EvaluateException {
        return operations.negate(value);
    }
}
