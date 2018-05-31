package parser;

import expressions.TripleExpression;
import expressions.binary.CheckedAdd;
import expressions.binary.CheckedDivide;
import expressions.binary.CheckedMultiply;
import expressions.binary.CheckedSubtract;
import expressions.unary.*;
import parser.exceptions.MissingArgumentException;
import parser.exceptions.NoClosingParenthesisException;
import parser.exceptions.ParseException;
import parser.tokenizer.Token;
import parser.tokenizer.Tokenizer;

public class ExpressionParser implements Parser {
    private Tokenizer tokenizer;

    @Override
    public TripleExpression parse(String expression) throws ParseException {
        tokenizer = new Tokenizer(expression);
        return parseAddSub();
    }

    private TripleExpression parseAddSub() throws ParseException {
        TripleExpression result = parseMulDiv();
        while (true) {
            switch (tokenizer.getToken()) {
                case ADD:
                    result = new CheckedAdd(result, parseMulDiv());
                    break;
                case SUB:
                    result = new CheckedSubtract(result, parseMulDiv());
                    break;
                default:
                    return result;
            }
        }
    }

    private TripleExpression parseMulDiv() throws ParseException {
        TripleExpression result = parseLower();
        while (true) {
            switch (tokenizer.getToken()) {
                case MUL:
                    result = new CheckedMultiply(result, parseLower());
                    break;
                case DIV:
                    result = new CheckedDivide(result, parseLower());
                    break;
                default:
                    return result;
            }
        }
    }

    private TripleExpression parseLower() throws ParseException {
        TripleExpression result;
        switch (tokenizer.getNextToken()) {
            case VARIABLE:
                result = new Variable(tokenizer.getContent());
                tokenizer.getNextToken();
                break;
            case CONST:
                result = new Const(tokenizer.getNumber());
                tokenizer.getNextToken();
                break;
            case INVERSE:
                result = new CheckedNegate(parseLower());
                break;
            case LOG:
                result = new CheckedLog10(parseLower());
                break;
            case POW:
                result = new CheckedPow10(parseLower());
                break;
            case BRACE_OPN:
                result = parseAddSub();
                if (tokenizer.getToken() != Token.BRACE_CLS) {
                    throw new NoClosingParenthesisException(tokenizer.getExpression(), tokenizer.getPosition());
                }
                tokenizer.getNextToken();
                break;
            default:
                throw new MissingArgumentException(tokenizer.getExpression(), tokenizer.getPosition());
        }
        return result;
    }
}
