package expressions.unary;

import expressions.TripleExpression;
import expressions.EvaluateException;

public class Variable<T> implements TripleExpression<T> {
    private final String name;

    public Variable(String name) {
        this.name = name;
    }

    @Override
    public T evaluate(T x, T y, T z) throws EvaluateException {
        switch (name) {
            case "x":
                return x;
            case "y":
                return y;
            case "z":
                return z;
            default:
                throw new WrongVariableNameException(name);
        }
    }

    static class WrongVariableNameException extends EvaluateException {
        WrongVariableNameException(String name) {
            super("Wrong variable name", name);
        }
    }
}
