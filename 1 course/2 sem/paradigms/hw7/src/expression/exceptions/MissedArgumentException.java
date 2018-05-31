package expression.exceptions;

public class MissedArgumentException extends ParserException {
    public MissedArgumentException(String str, int ind) {
        super("Missed argument on the position " + ind + ", expression: " + str);
    }

    public MissedArgumentException(String pos, String str, int ind) {
        super("Missed " + pos + " argument on the position " + ind + ", expression: " + str);
    }
}
