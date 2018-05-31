package operations.exceptions;

import expressions.EvaluateException;

public class IllegalOperationException extends EvaluateException {
    public IllegalOperationException(String message, String operands) {
        super(message, operands);
    }
}
