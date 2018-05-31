package operations;

public class DoubleOperations implements Operations<Double> {
    @Override
    public Double parseNumber(String str) throws NumberFormatException {
        return Double.parseDouble(str);
    }

    @Override
    public Double add(Double first, Double second) {
        return first + second;
    }

    @Override
    public Double subtract(Double first, Double second) {
        return first - second;
    }

    @Override
    public Double multiply(Double first, Double second) {
        return first * second;
    }

    @Override
    public Double divide(Double first, Double second) {
        return first / second;
    }

    @Override
    public Double negate(Double value) {
        return -value;
    }
}
