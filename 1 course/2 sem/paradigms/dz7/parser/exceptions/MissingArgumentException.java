package parser.exceptions;

public class MissingArgumentException extends ParseException {
    public MissingArgumentException(String expression, int index) {
        super("Missing argument", expression, index);
    }
}
