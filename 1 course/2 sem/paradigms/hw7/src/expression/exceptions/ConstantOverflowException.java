package expression.exceptions;

public class ConstantOverflowException extends ParserException {
    public ConstantOverflowException(String s) {
        super("Constant overflow, value: " + s);
    }
}
