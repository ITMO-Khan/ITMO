package operations;

import operations.exceptions.IllegalOperationException;
import operations.exceptions.OverflowException;

public interface Operations<T> {
    T parseNumber(String str) throws NumberFormatException;

    T add(T first, T second) throws OverflowException;

    T subtract(T first, T second) throws OverflowException;

    T multiply(T first, T second) throws OverflowException;

    T divide(T first, T second) throws OverflowException, IllegalOperationException;

    T negate(T value) throws OverflowException;
}
