package expressions.binary;

import expressions.TripleExpression;
import operations.Operations;
import expressions.EvaluateException;


public abstract class Binary<T> implements TripleExpression<T> {
    private final TripleExpression<T> first;
    private final TripleExpression<T> second;
    final Operations<T> operations;

    Binary(TripleExpression<T> first, TripleExpression<T> second, Operations<T> operations) {
        this.first = first;
        this.second = second;
        this.operations = operations;
    }

    @Override
    public T evaluate(T x, T y, T z) throws EvaluateException {
        return apply(first.evaluate(x, y, z), second.evaluate(x, y, z));
    }

    protected abstract T apply(T first, T second) throws EvaluateException;
}
