package expression;

import expression.exceptions.*;

public abstract class CheckedBinaryOperators implements TripleExpression {
    TripleExpression left;
    TripleExpression right;

    public CheckedBinaryOperators(TripleExpression left, TripleExpression right) {
        this.left = left;
        this.right = right;
    }

    @Override
    public int evaluate(int x, int y, int z) throws EvaluatingExceptions {
        return applyInSubclass(left.evaluate(x, y, z), right.evaluate(x, y, z));
    }

    protected abstract int applyInSubclass(int x, int y) throws EvaluatingExceptions;
}
