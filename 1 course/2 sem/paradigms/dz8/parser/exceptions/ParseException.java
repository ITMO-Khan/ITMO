package parser.exceptions;

public abstract class ParseException extends Exception {
    ParseException(String message, String string, int position) {
        super(String.format("%s in \t'%s' \tat index %d", message, string, position));
    }
}
