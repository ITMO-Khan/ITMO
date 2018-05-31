package expressions;

public interface TripleExpression<T> {
    T evaluate(T x, T y, T z) throws EvaluateException;
}
