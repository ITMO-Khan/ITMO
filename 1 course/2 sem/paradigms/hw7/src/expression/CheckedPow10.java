package expression;
import expression.exceptions.*;

public class CheckedPow10 extends CheckedUnaryOperators {
    public CheckedPow10(TripleExpression expr) {
        super(expr);
    }

    @Override
    protected int applyInSubclass(int x) throws EvaluatingExceptions {
        EvaluatingExceptionsChecker.checkPow(x);
        int i = 0;
        int val = 1;

        while (i < x) {
            i++;
            EvaluatingExceptionsChecker.checkMul(val, 10);
            val *= 10;
        }
        return val;
    }
}
