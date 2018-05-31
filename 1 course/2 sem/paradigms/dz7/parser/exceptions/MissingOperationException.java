package parser.exceptions;

public class MissingOperationException extends ParseException {
    public MissingOperationException(String expression, int index) {
        super("Missing operation", expression, index);
    }
}
