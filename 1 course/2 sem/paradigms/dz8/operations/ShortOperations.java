package operations;

import operations.exceptions.IllegalOperationException;

public class ShortOperations implements Operations<Short> {
    @Override
    public Short parseNumber(String str) throws NumberFormatException {
        int x = Integer.parseInt(str);
        return (short) x;
    }

    @Override
    public Short add(Short first, Short second) {
        return (short) (first + second);
    }

    @Override
    public Short subtract(Short first, Short second) {
        return (short) (first - second);
    }

    @Override
    public Short multiply(Short first, Short second) {
        return (short) (first * second);
    }

    @Override
    public Short divide(Short first, Short second) throws IllegalOperationException {
        if (second == 0) {
            throw new IllegalOperationException("Division by zero", String.format("%d / %d", first, second));
        }
        return (short) (first / second);
    }

    @Override
    public Short negate(Short value) {
        return (short) -value;
    }
}
