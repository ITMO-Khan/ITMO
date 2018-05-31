package operations.exceptions;

import expressions.EvaluateException;

public class OverflowException extends EvaluateException {
    public OverflowException(String operation) {
        super("Overflow", operation);
    }
}
