package expressions;

public abstract class EvaluateException extends Exception {
    protected EvaluateException(String message, String operation) {
        super(String.format("%s for operation '%s'", message, operation));
    }
}
