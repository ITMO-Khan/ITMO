package expression;

import expression.exceptions.*;
import expression.exceptions.EvaluatingExceptionsChecker;

public class CheckedMultiply extends CheckedBinaryOperators {
    public CheckedMultiply(TripleExpression left, TripleExpression right) {
        super(left, right);
    }

    @Override
    protected int applyInSubclass(int x, int y) throws OverflowException {
        EvaluatingExceptionsChecker.checkMul(x, y);
        return x * y;
    }
}
