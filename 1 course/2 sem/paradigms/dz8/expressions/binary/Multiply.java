package expressions.binary;

import operations.exceptions.OverflowException;
import expressions.TripleExpression;
import operations.Operations;

public class Multiply<T> extends Binary<T> {
    public Multiply(TripleExpression<T> first, TripleExpression<T> second, Operations<T> operations) {
        super(first, second, operations);
    }

    @Override
    protected T apply(T first, T second) throws OverflowException {
        return operations.multiply(first, second);
    }
}