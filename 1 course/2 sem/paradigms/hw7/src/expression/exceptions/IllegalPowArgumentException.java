package expression.exceptions;

public class IllegalPowArgumentException extends EvaluatingExceptions {
    public IllegalPowArgumentException(int x, int y) {
        super("Impossible to raise the value " + x + " to the power " + y);
    }
}
