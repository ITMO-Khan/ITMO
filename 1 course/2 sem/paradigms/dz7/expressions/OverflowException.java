package expressions;

public class OverflowException extends EvalException {
    public OverflowException() {
        super("overflow");
    }
}
