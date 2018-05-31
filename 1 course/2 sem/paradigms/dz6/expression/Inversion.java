package expression;

public class Inversion extends Unary {
    public Inversion(TripleExpression expression) {
        super(expression);
    }

    @Override
    protected int apply(int expression) {
        return -expression;
    }


}
