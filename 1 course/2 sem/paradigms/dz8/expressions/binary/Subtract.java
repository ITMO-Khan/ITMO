package expressions.binary;

import expressions.TripleExpression;
import operations.Operations;
import expressions.EvaluateException;

public class Subtract<T> extends Binary<T> {
    public Subtract(TripleExpression<T> first, TripleExpression<T> second, Operations<T> operations) {
        super(first, second, operations);
    }

    @Override
    protected T apply(T first, T second) throws EvaluateException {
        return operations.subtract(first, second);
    }
}
