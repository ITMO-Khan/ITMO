package expression;

public class Xor extends Binary {

    public Xor(TripleExpression first, TripleExpression second) {
        super(first, second);
    }

    @Override
    protected int apply(int first, int second) {
        return first ^ second;
    }
}
