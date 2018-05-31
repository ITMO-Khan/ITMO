package expressions.binary;

import expressions.TripleExpression;
import expressions.EvaluateException;
import operations.Operations;

public class Add<T> extends Binary<T> {
    public Add(TripleExpression<T> first, TripleExpression<T> second, Operations<T> operations) {
        super(first, second, operations);
    }

    @Override
    protected T apply(T first, T second) throws EvaluateException {
        return operations.add(first, second);
    }
}
