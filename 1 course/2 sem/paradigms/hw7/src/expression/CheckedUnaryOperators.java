package expression;

import expression.exceptions.*;

public abstract class CheckedUnaryOperators implements TripleExpression {
    TripleExpression expr;

    public CheckedUnaryOperators(TripleExpression expr) {
        this.expr = expr;
    }

    @Override
    public int evaluate(int x, int y, int z) throws EvaluatingExceptions {
        return applyInSubclass(expr.evaluate(x, y, z));
    }

    protected abstract int applyInSubclass(int x) throws EvaluatingExceptions;
}
