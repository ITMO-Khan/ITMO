package expressions.binary;

import expressions.TripleExpression;
import expressions.EvaluateException;
import operations.Operations;

public class Divide<T> extends Binary<T> {
    public Divide(TripleExpression<T> first, TripleExpression<T> second, Operations<T> operations) {
        super(first, second, operations);
    }

    @Override
    protected T apply(T first, T second) throws EvaluateException {
        return operations.divide(first, second);
    }
}
