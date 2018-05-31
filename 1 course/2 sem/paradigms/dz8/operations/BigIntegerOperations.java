package operations;

import operations.exceptions.IllegalOperationException;

import java.math.BigInteger;

public class BigIntegerOperations implements Operations<BigInteger> {
    @Override
    public BigInteger parseNumber(String str) throws NumberFormatException {
        return new BigInteger(str);
    }

    @Override
    public BigInteger add(BigInteger first, BigInteger second) {
        return first.add(second);
    }

    @Override
    public BigInteger subtract(BigInteger first, BigInteger second) {
        return first.subtract(second);
    }

    @Override
    public BigInteger multiply(BigInteger first, BigInteger second) {
        return first.multiply(second);
    }

    @Override
    public BigInteger divide(BigInteger first, BigInteger second) throws IllegalOperationException {
        if (second.equals(BigInteger.ZERO)) {
            throw new IllegalOperationException("Divide by zero", String.format("%s / %s", first.toString(), second.toString()));
        }
        return first.divide(second);
    }

    @Override
    public BigInteger negate(BigInteger value) {
        return value.negate();
    }
}
