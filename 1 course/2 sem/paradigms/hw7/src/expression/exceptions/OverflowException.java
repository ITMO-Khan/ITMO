package expression.exceptions;

public class OverflowException extends EvaluatingExceptions {
    public OverflowException() {
        super("overflow");
    }
}
