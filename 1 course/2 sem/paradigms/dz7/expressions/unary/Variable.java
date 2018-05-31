package expressions.unary;

import expressions.TripleExpression;
import expressions.EvalException;

public class Variable implements TripleExpression {
    private final String var;

    public Variable(String var) {
        this.var = var;
    }

    @Override
    public int evaluate(int x, int y, int z) throws EvalException {
        switch (var) {
            case "x":
                return x;
            case "y":
                return y;
            case "z":
                return z;
            default:
                throw new WrongVariableException(var);
        }
    }

    private class WrongVariableException extends EvalException {
        WrongVariableException(String varName) {
            super("Wrong name `" + varName + "` variable");
        }
    }
}
