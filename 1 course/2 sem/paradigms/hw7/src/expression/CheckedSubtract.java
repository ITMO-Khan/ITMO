package expression;

import expression.exceptions.*;
import expression.exceptions.EvaluatingExceptionsChecker;

public class CheckedSubtract extends CheckedBinaryOperators {
    public CheckedSubtract(TripleExpression left, TripleExpression right) {
        super(left, right);
    }

    @Override
    protected int applyInSubclass(int x, int y) throws OverflowException {
        EvaluatingExceptionsChecker.checkSub(x, y);
        return x - y;
    }
}