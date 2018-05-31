package expression.exceptions;

public class EvaluatingExceptionsChecker {
    public static void checkAdd(int x, int y) throws OverflowException {
        if (x > 0 && Integer.MAX_VALUE - x < y
                || x < 0 && Integer.MIN_VALUE - x > y) {
            throw new OverflowException();
        }
    }

    public static void checkSub(int x, int y) throws OverflowException {
        if (x >= 0 && y < 0 && x - Integer.MAX_VALUE > y) {
            throw new OverflowException();
        }
        if (x <= 0 && y > 0 && Integer.MIN_VALUE - x > -y) {
            throw new OverflowException();
        }
    }

    public static void checkZero(int x) throws DivisionByZeroException {
        if (x == 0) {
            throw new DivisionByZeroException();
        }
    }

    public static void checkMul(int x, int y) throws OverflowException {
        if (x > 0 && y > 0 && Integer.MAX_VALUE / x < y) {
            throw new OverflowException();
        }

        if (x > 0 && y < 0 && Integer.MIN_VALUE / x > y) {
            throw new OverflowException();
        }

        if (x < 0 && y > 0 && Integer.MIN_VALUE / y > x) {
            throw new OverflowException();
        }

        if (x < 0 && y < 0 && Integer.MAX_VALUE / x > y) {
            throw new OverflowException();
        }
    }

    public static void checkDivide(int x, int y) throws OverflowException, DivisionByZeroException {
        EvaluatingExceptionsChecker.checkZero(y);
        if (x == Integer.MIN_VALUE && y == -1) {
            throw new OverflowException();
        }
    }

    public static void checkNegate(int x) throws OverflowException {
        if (x == Integer.MIN_VALUE) {
            throw new OverflowException();
        }
    }

    public static void checkLog(int x, int y) throws IllegalLogArgumentException {
        if (y <= 0 || x <= 1) {
            throw new IllegalLogArgumentException(x, y);
        }
    }

    public static void checkPow(int x, int y) throws IllegalPowArgumentException {
        if (y == 0 && x == 0 || y < 0) {
            throw new IllegalPowArgumentException(x, y);
        }

    }
}
