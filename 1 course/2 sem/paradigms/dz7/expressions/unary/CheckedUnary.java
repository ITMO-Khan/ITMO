package expressions.unary;

import expressions.EvalException;
import expressions.TripleExpression;

public abstract class CheckedUnary implements TripleExpression {
    private final TripleExpression expression;

    CheckedUnary(TripleExpression expression) {
        this.expression = expression;
    }

    @Override
    public int evaluate(int x, int y, int z) throws EvalException {
        int result = expression.evaluate(x, y, z);
        check(result);
        return apply(result);
    }

    abstract void check(int value) throws EvalException;

    abstract int apply(int value);
}
