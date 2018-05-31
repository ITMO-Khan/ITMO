package expression;

import expression.exceptions.EvaluatingExceptionsChecker;
import expression.exceptions.*;

public class CheckedDivide extends CheckedBinaryOperators {
    public CheckedDivide(TripleExpression left, TripleExpression right) {
        super(left, right);
    }

    @Override
    protected int applyInSubclass(int x, int y) throws DivisionByZeroException, OverflowException {
        EvaluatingExceptionsChecker.checkDivide(x, y);
        return x / y;
    }
}