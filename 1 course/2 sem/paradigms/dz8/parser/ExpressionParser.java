package parser;


import expressions.TripleExpression;
import expressions.binary.*;
import expressions.unary.*;
import operations.Operations;
import parser.exceptions.MissingOperandException;
import parser.exceptions.NoClosingParenthesisException;
import parser.exceptions.ParseException;
import parser.tokenizer.Token;
import parser.tokenizer.Tokenizer;

public class ExpressionParser<T> implements Parser {
    private Tokenizer tokenizer;
    private final Operations<T> operations;

    public ExpressionParser(Operations<T> operations) {
        this.operations = operations;
    }

    @Override
    public TripleExpression<T> parse(String expression) throws ParseException {
        tokenizer = new Tokenizer(expression);
        return parseAddSub();
    }

    private TripleExpression<T> parseAddSub() throws ParseException {
        TripleExpression<T> result = parseMulDiv();
        while (true) {
            switch (tokenizer.getToken()) {
                case ADD:
                    result = new Add<>(result, parseMulDiv(), operations);
                    break;
                case SUB:
                    result = new Subtract<>(result, parseMulDiv(), operations);
                    break;
                default:
                    return result;
            }
        }
    }

    private TripleExpression<T> parseMulDiv() throws ParseException {
        TripleExpression<T> result = parseLower();
        while (true) {
            switch (tokenizer.getToken()) {
                case MUL:
                    result = new Multiply<>(result, parseLower(), operations);
                    break;
                case DIV:
                    result = new Divide<>(result, parseLower(), operations);
                    break;
                default:
                    return result;
            }
        }
    }

    private TripleExpression<T> parseLower() throws ParseException {
        TripleExpression<T> result;
        switch (tokenizer.getNextToken()) {
            case VARIABLE:
                result = new Variable<>(tokenizer.getContent());
                tokenizer.getNextToken();
                break;
            case CONST:
                result = new Const<>(operations.parseNumber(tokenizer.getContent()));
                tokenizer.getNextToken();
                break;
            case INVERSE:
                result = new Negate<>(parseLower(), operations);
                break;
            case BRACE_OPN:
                result = parseAddSub();
                if (tokenizer.getToken() != Token.BRACE_CLS) {
                    throw new NoClosingParenthesisException(tokenizer.getExpression(), tokenizer.getPosition());
                }
                tokenizer.getNextToken();
                break;
            default:
                throw new MissingOperandException(tokenizer.getExpression(), tokenizer.getPosition());
        }
        return result;
    }
}
