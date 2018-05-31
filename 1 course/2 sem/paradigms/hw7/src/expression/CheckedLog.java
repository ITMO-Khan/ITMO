package expression;

import expression.exceptions.EvaluatingExceptions;
import expression.exceptions.EvaluatingExceptionsChecker;
import expression.exceptions.OverflowException;

public class CheckedLog extends CheckedBinaryOperators {
    public CheckedLog(TripleExpression left, TripleExpression right) {
        super(left, right);
    }

    @Override
    protected int applyInSubclass(int y, int x) throws EvaluatingExceptions {
        EvaluatingExceptionsChecker.checkLog(x, y);
        int k = -1;
        int value = 1;
        while (value <= y) {
            k++;
            try {
                EvaluatingExceptionsChecker.checkMul(value, x);
            } catch (OverflowException e) {
                return k;
            }
            value *= x;
        }
        return k;
    }
}
