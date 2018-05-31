package expression.exceptions;

public class IllegalLogArgumentException extends EvaluatingExceptions {
    public IllegalLogArgumentException(int x, int y) {
        super("Impossible to find log" + x + " " + y);
    }
}
