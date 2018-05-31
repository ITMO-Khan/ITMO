package parser.exceptions;

public class IllegalIdentifierException extends ParseException {
    public IllegalIdentifierException(String expression, int index) {
        super("Identifier need starts with letter", expression, index);
    }

    public IllegalIdentifierException(String content, String expression, int index) {
        super(String.format("Wrong identifier name \"%s\"", content), expression, index);
    }
}
