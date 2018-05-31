package parser.exceptions;

public class NoClosingParenthesisException extends ParseException {
    public NoClosingParenthesisException(String expression, int index) {
        super("No closing parenthesis", expression, index);
    }
}
