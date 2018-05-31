package operations;

import operations.exceptions.IllegalOperationException;
import operations.exceptions.OverflowException;

public class IntegerOperations implements Operations<Integer> {
    private final boolean checkable;

    public IntegerOperations(boolean checkable) {
        this.checkable = checkable;
    }

    @Override
    public Integer parseNumber(String str) throws NumberFormatException {
        return Integer.parseInt(str);
    }

    @Override
    public Integer add(Integer first, Integer second) throws OverflowException {
        if (checkable) {
            if (first > 0 && Integer.MAX_VALUE - first < second) {
                throw new OverflowException(String.format("%d + %d", first, second));
            }
            if (first < 0 && Integer.MIN_VALUE - first > second) {
                throw new OverflowException(String.format("%d + %d", first, second));
            }
        }
        return first + second;
    }

    @Override
    public Integer subtract(Integer first, Integer second) throws OverflowException {
        if (checkable) {
            if (first >= 0 && second < 0 && first - Integer.MAX_VALUE > second) {
                throw new OverflowException(String.format("%d - %d", first, second));
            }
            if (first <= 0 && second > 0 && Integer.MIN_VALUE - first > -second) {
                throw new OverflowException(String.format("%d - %d", first, second));
            }
        }
        return first - second;
    }

    @Override
    public Integer multiply(Integer first, Integer second) throws OverflowException {
        if (checkable) {
            if (first > 0 && second > 0 && Integer.MAX_VALUE / first < second) {
                throw new OverflowException(String.format("%d * %d", first, second));
            }
            if (first > 0 && second < 0 && Integer.MIN_VALUE / first > second) {
                throw new OverflowException(String.format("%d * %d", first, second));
            }
            if (first < 0 && second > 0 && Integer.MIN_VALUE / second > first) {
                throw new OverflowException(String.format("%d * %d", first, second));
            }
            if (first < 0 && second < 0 && Integer.MAX_VALUE / first > second) {
                throw new OverflowException(String.format("%d * %d", first, second));
            }
        }
        return first * second;
    }

    @Override
    public Integer divide(Integer first, Integer second) throws OverflowException, IllegalOperationException {
        if (second == 0) {
            throw new IllegalOperationException("Division by zero", String.format("%d / %d", first, second));
        }
        if (checkable) {
            if (first == Integer.MIN_VALUE && second == -1) {
                throw new OverflowException(String.format("%d / %d", first, second));
            }
        }
        return first / second;
    }

    @Override
    public Integer negate(Integer value) throws OverflowException {
        if (checkable) {
            if (value == Integer.MIN_VALUE) {
                throw new OverflowException(String.format("-%d", value));
            }
        }
        return -value;
    }
}
