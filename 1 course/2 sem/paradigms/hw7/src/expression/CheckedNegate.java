package expression;

import expression.exceptions.*;

public class CheckedNegate extends CheckedUnaryOperators {
    public CheckedNegate(TripleExpression expr) {
        super(expr);
    }

    @Override
    protected int applyInSubclass(int x) throws OverflowException {
        EvaluatingExceptionsChecker.checkNegate(x);
        return -x;
    }
}
