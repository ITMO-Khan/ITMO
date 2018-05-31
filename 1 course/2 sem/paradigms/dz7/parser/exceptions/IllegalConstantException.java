package parser.exceptions;

public class IllegalConstantException extends ParseException {
    public IllegalConstantException(String content, String expression, int index) {
        super(String.format("Can't create const '%s'", content), expression, index);
    }
}
