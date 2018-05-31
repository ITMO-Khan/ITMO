package expression;

import expression.exceptions.EvaluatingExceptions;
import expression.exceptions.EvaluatingExceptionsChecker;
import expression.exceptions.ParserException;
import expression.exceptions.OverflowException;

public class CheckedLog10 extends CheckedUnaryOperators {
    public CheckedLog10(TripleExpression expr) {
        super(expr);
    }

    @Override
    protected int applyInSubclass(int x) throws EvaluatingExceptions {
        EvaluatingExceptionsChecker.checkLog(x);
        int k = -1;
        int val = 1;
        while (val <= x) {
            k++;
            try {
                EvaluatingExceptionsChecker.checkMul(val, 10);
            } catch (OverflowException e) {
                return k;
            }
            val *= 10;
        }
        return k;
    }
}
