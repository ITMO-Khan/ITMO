package expression;

import expression.exceptions.*;
import expression.exceptions.EvaluatingExceptionsChecker;

public class CheckedAdd extends CheckedBinaryOperators {
    public CheckedAdd(TripleExpression left, TripleExpression right) {
        super(left, right);
    }

    @Override
    protected int applyInSubclass(int x, int y) throws OverflowException {
        EvaluatingExceptionsChecker.checkAdd(x, y);
        return x + y;
    }
}
