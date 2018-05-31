package parser.exceptions;

public class NoClosingParenthesisException extends ParseException {
    public NoClosingParenthesisException(String expression, int index) {
        super("Missing closing", expression, index);
    }
}
