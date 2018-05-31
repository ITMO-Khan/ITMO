package operations;

import operations.exceptions.IllegalOperationException;

public class LongOperations implements Operations<Long> {

    @Override
    public Long parseNumber(String str) throws NumberFormatException {
        return Long.parseLong(str);
    }

    @Override
    public Long add(Long first, Long second) {
        return first + second;
    }

    @Override
    public Long subtract(Long first, Long second) {
        return first - second;
    }

    @Override
    public Long multiply(Long first, Long second) {
        return first * second;
    }

    @Override
    public Long divide(Long first, Long second) throws IllegalOperationException {
        if (second == 0) {
            throw new IllegalOperationException("Division by zero", String.format("%d / %d", first, second));
        }
        return first / second;
    }

    @Override
    public Long negate(Long value) {
        return -value;
    }
}
