package expression.parser;

import expression.*;
import expression.parser.Tokenizer.Token;
import expression.exceptions.*;

public class ExpressionParser implements Parser {
    private Tokenizer token;

    @Override
    public TripleExpression parse(String str) throws ParserException {
        token = new Tokenizer(str);
        token.getToken();
        if (token.curToken == Token.END) {
            return new Const(0);
        }
        return addSub(false);
    }

    private TripleExpression primary(boolean newToken) throws ParserException {
        if (newToken) {
            token.getToken();
        }
        switch (token.curToken) {
            case CONST:
                return token.primaryConst();
            case VARIABLE:
                return token.primaryVariable();
            case MINUS:
                if (token.isDigit()) {
                    return token.primaryMinus();
                }
                return new CheckedNegate(primary(true)); 
            case OPEN_BRACKET:
                token.openBracketNum++;
                TripleExpression e = addSub(true);
                token.primaryLeftBracket();
                return e;
            default:
                throw new MissedArgumentException("last", token.expression, token.index - 1);
        }
    }

    private TripleExpression logPow(boolean newToken) throws ParserException {
        TripleExpression left = primary(newToken);

        while (true) {
            if (token.curToken == Token.LOG) {
                left = new CheckedLog(left, primary(true));
            } else if (token.curToken == Token.POW) {
                left = new CheckedPow(left, primary(true));
            } else {
                return left;
            }
        }
    }

    private TripleExpression mulDiv(boolean newToken) throws ParserException {
        TripleExpression left = logPow(newToken);

        while (true) {
            if (token.curToken == Token.MUL) {
                left = new CheckedMultiply(left, logPow(true));
            } else if (token.curToken == Token.DIV) {
                left = new CheckedDivide(left, logPow(true));
            } else {
                return left;
            }
        }
    }

    private TripleExpression addSub(boolean newToken) throws ParserException {
        TripleExpression left = mulDiv(newToken);

        while (true) {
            if (token.curToken == Token.PLUS) {
                left = new CheckedAdd(left, mulDiv(true));
            } else if (token.curToken == Token.MINUS) {
                left = new CheckedSubtract(left, mulDiv(true));
            } else {
                return left;
            }
        }
    }
}
