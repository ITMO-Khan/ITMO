import expressions.EvaluateException;
import expressions.TripleExpression;
import operations.*;
import parser.ExpressionParser;
import parser.exceptions.ParseException;

public class GenericTabulator implements Tabulator {
    @Override
    public Object[][][] tabulate(String mode, String expression, int x1, int x2, int y1, int y2, int z1, int z2) throws UnknownModeException {
        Operations<?> operations;
        switch (mode) {
            case "i":
                operations = new IntegerOperations(true);
                break;
            case "d":
                operations = new DoubleOperations();
                break;
            case "bi":
                operations = new BigIntegerOperations();
                break;
            case "u":
                operations = new IntegerOperations(false);
                break;
            case "l":
                operations = new LongOperations();
                break;
            case "s":
                operations = new ShortOperations();
                break;
            default:
                throw new UnknownModeException(mode);
        }
        return getTable(operations, expression, x1, x2, y1, y2, z1, z2);
    }

    private <T> Object[][][] getTable(Operations<T> operations, String expression, int x1, int x2, int y1, int y2, int z1, int z2) {
        Object[][][] res = new Object[x2 - x1 + 1][y2 - y1 + 1][z2 - z1 + 1];
        ExpressionParser<T> parser = new ExpressionParser<>(operations);
        TripleExpression<T> parsedExpression;
        try {
            parsedExpression = parser.parse(expression);
        } catch (ParseException exception) {
            return res;
        }
        for (int x = x1; x <= x2; ++x) {
            for (int y = y1; y <= y2; ++y) {
                for (int z = z1; z <= z2; ++z) {
                    try {
                        res[x - x1][y - y1][z - z1] = parsedExpression.evaluate(
                                operations.parseNumber(Integer.toString(x)),
                                operations.parseNumber(Integer.toString(y)),
                                operations.parseNumber(Integer.toString(z))
                        );
                    } catch (EvaluateException | NumberFormatException e) {
                        res[x - x1][y - y1][z - z1] = null;
                    }
                }
            }
        }
        return res;
    }

    private class UnknownModeException extends Exception {
        UnknownModeException(String mode) {
            super(String.format("Illegal mode '%s'", mode));
        }
    }
}
