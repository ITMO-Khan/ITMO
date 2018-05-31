package parser.tokenizer;

import parser.exceptions.*;

import java.util.EnumSet;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class Tokenizer {
    private final String expression;
    private static final Map<String, Token> IDENTIFIERS = new HashMap<>();
    private Token token;
    private static final Set<Token> operations = EnumSet.of(Token.ADD, Token.SUB, Token.MUL, Token.DIV);

    static {
        IDENTIFIERS.put("x", Token.VARIABLE);
        IDENTIFIERS.put("y", Token.VARIABLE);
        IDENTIFIERS.put("z", Token.VARIABLE);
    }

    private int begin, end, balance;

    public Tokenizer(String expression) {
        this.expression = expression;
        token = Token.INIT;
        begin = end = balance = 0;
    }

    public String getExpression() {
        return expression;
    }

    public int getPosition() {
        return begin;
    }

    public Token getToken() {
        return token;
    }

    public Token getNextToken() throws ParseException {
        moveForward();
        return token;
    }

    public String getContent() {
        return expression.substring(begin, end);
    }

    private void skipWhiteSpace() {
        while (begin < expression.length() && Character.isWhitespace(expression.charAt(begin))) {
            ++begin;
        }
    }

    private void checkForOperation() throws MissingOperationException {
        if (token == Token.BRACE_CLS || token == Token.VARIABLE || token == Token.CONST) {
            throw new MissingOperationException(expression, begin);
        }
    }

    private void checkForOperand() throws MissingOperandException {
        if (operations.contains(token) || token == Token.BRACE_OPN || token == Token.INIT) {
            throw new MissingOperandException(expression, begin);
        }
    }

    private void moveForward() throws ParseException {
        begin = end;
        skipWhiteSpace();
        if (begin < expression.length()) {
            end = begin + 1;
            switch (expression.charAt(begin)) {
                case '+':
                    checkForOperand();
                    token = Token.ADD;
                    break;
                case '-':
                    if (token == Token.CONST || token == Token.VARIABLE || token == Token.BRACE_CLS) {
                        token = Token.SUB;
                    } else {
                        if (end >= expression.length()) {
                            throw new MissingOperandException(expression, end);
                        }
                        if (Character.isDigit(expression.charAt(end))) {
                            parseNumber();
                            token = Token.CONST;
                        } else {
                            token = Token.INVERSE;
                        }
                    }
                    break;
                case '*':
                    checkForOperand();
                    token = Token.MUL;
                    break;
                case '/':
                    checkForOperand();
                    token = Token.DIV;
                    break;
                case '(':
                    checkForOperation();
                    token = Token.BRACE_OPN;
                    ++balance;
                    break;
                case ')':
                    if (operations.contains(token) || token == Token.BRACE_OPN) {
                        throw new MissingOperandException(expression, begin);
                    }
                    if (--balance < 0) {
                        throw new NoOpeningParenthesisException(expression, begin);
                    }
                    token = Token.BRACE_CLS;
                    break;
                default:
                    if (Character.isDigit(expression.charAt(begin))) {
                        checkForOperation();
                        parseNumber();
                        token = Token.CONST;
                    } else {
                        parseIdentifier();
                        if (!IDENTIFIERS.containsKey(getContent())) {
                            throw new IllegalIdentifierException(getContent(), getExpression(), begin);
                        }
                        token = IDENTIFIERS.get(getContent());
                    }
            }
        } else {
            checkForOperand();
            token = Token.END;
        }
    }

    private void parseIdentifier() throws IllegalIdentifierException {
        if (!Character.isLetter(expression.charAt(begin))) {
            throw new IllegalIdentifierException(getExpression(), begin);
        }
        while (end < expression.length() && isPartOfIdentifier(expression.charAt(end))) {
            ++end;
        }
    }

    private boolean isPartOfIdentifier(char c) {
        return Character.isLetterOrDigit(c) || c == '_';
    }

    private void parseNumber() {
        while (end < expression.length() && Character.isDigit(expression.charAt(end))) {
            ++end;
        }
    }
}
