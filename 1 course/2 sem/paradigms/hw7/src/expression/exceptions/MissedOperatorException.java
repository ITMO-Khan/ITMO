package expression.exceptions;

public class MissedOperatorException extends ParserException {
    public MissedOperatorException(String s, int ind) {
        super("Missed " + s + " argument, index: " + ind);
    }
}
