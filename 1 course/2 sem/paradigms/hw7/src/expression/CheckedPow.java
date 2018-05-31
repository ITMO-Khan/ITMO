package expression;
import expression.exceptions.*;

public class CheckedPow extends CheckedBinaryOperators {
    public CheckedPow(TripleExpression left, TripleExpression right) {
        super(left, right);
    }

    @Override
    protected int applyInSubclass(int x, int y) throws EvaluatingExceptions {
        EvaluatingExceptionsChecker.checkPow(x, y);
        int i = 0;
        int value = 1;

        while (i < y) {
            i++;
            EvaluatingExceptionsChecker.checkMul(value,  x);
            value *= x;
        }
        return value;
    }
}
