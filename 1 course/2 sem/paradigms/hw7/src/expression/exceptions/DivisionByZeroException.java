package expression.exceptions;

public class DivisionByZeroException extends EvaluatingExceptions {
    public DivisionByZeroException() {
        super("division by zero");
    }
}
