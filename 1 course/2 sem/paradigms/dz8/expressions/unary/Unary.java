package expressions.unary;

import expressions.TripleExpression;
import expressions.EvaluateException;
import operations.Operations;

public abstract class Unary<T> implements TripleExpression<T> {
    private final TripleExpression<T> expression;
    final Operations<T> operations;

    Unary(TripleExpression<T> expression, Operations<T> operations) {
        this.expression = expression;
        this.operations = operations;
    }

    @Override
    public T evaluate(T x, T y, T z) throws EvaluateException {
        return apply(expression.evaluate(x, y, z));
    }

    abstract T apply(T value) throws EvaluateException;
}
