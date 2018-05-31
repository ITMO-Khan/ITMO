package expression.exceptions;

public class WrongBracketException extends ParserException {
    public WrongBracketException(String s, int ind) {
        super("No pair for " + s + " bracket, index: " + ind);
    }
}
