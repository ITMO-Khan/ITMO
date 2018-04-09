package expression;

public abstract class Operation implements AllExpression {
    protected AllExpression firstOperand;
    protected AllExpression secondOperand;

    public Operation(AllExpression first, AllExpression second) {
        assert (first != null && second != null);
        firstOperand = first;
        secondOperand = second;
    }

    protected abstract double makeOperation(double firstOperand, double secondOperand);

    protected abstract int makeOperation(int firstOperand, int secondOperand);

    public double evaluate(double x) {
        return makeOperation(firstOperand.evaluate(x), secondOperand.evaluate(x));
    }

    public int evaluate(int x) {
        return makeOperation(firstOperand.evaluate(x), secondOperand.evaluate(x));
    }
}
