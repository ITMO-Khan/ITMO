package expression.parser;

import expression.*;
import expression.exceptions.*;

import java.util.HashMap;
import java.util.Map;

public class Tokenizer {
    int openBracketNum = 0;
    String expression;
    int index;

    int value;
    String name;

    Token curToken;
    Token prevToken;

    public Tokenizer(String str) {
        expression = str;
        index = 0;
        openBracketNum = 0;
        curToken = Token.FAIL;
        prevToken = Token.FAIL;
    }

    public enum Token {
        PLUS("operator"),
        OPEN_BRACKET("bracket"),
        CLOSE_BRACKET("bracket"),
        MINUS("minus"),
        MUL("operator"),
        DIV("operator"),
        END("end"),
        FAIL("fail"),
        VARIABLE("value"),
        CONST("value"),
        POW("pow"),
        LOG("log");

        final String meaning;

        Token(String meaning) {
            this.meaning = meaning;
        }
    }

    private static Map<Character, Token> tokenMap = new HashMap<>();

    static {
        tokenMap.put('+', Token.PLUS);
        tokenMap.put('-', Token.MINUS);
        tokenMap.put('/', Token.DIV);
        tokenMap.put('*', Token.MUL);
        tokenMap.put('(', Token.OPEN_BRACKET);
        tokenMap.put(')', Token.CLOSE_BRACKET);
    }

    private void match() throws ParserException {
        if (curToken.meaning.equals("operator")) {
            if (prevToken == Token.OPEN_BRACKET || prevToken == Token.FAIL) {
                throw new MissedArgumentException("first", expression, index - 1);
            }
            if (prevToken.meaning.equals("operator")) {
                throw new MissedArgumentException("middle", expression, index - 1);
            }
        }

        if (curToken == Token.OPEN_BRACKET
                && (prevToken == Token.CLOSE_BRACKET || prevToken.meaning.equals("value"))) {
            throw new MissedOperatorException(expression, index - 1);
        }

        if (curToken == Token.CLOSE_BRACKET) {
            if (openBracketNum == 0) {
                throw new WrongBracketException("closing", index - 1);
            }
            if (prevToken.meaning.equals("operator") || prevToken.meaning.equals("minus")) {
                throw new MissedArgumentException("last", expression, index - 1);
            }
        }

        if ((prevToken == Token.LOG || prevToken == Token.POW)
            && curToken.meaning.equals("operator")) {
            throw new MissedArgumentException("last", expression, index - 1);
        }
    }

    public void getToken() throws ParserException {
        skipWhiteSpace();
        if (index >= expression.length()) {
            curToken = Token.END;
            return;
        }
        char ch = expression.charAt(index++);
        prevToken = curToken;
        
        if (tokenMap.containsKey(ch)) {
            curToken = tokenMap.get(ch);
            if (ch == '/' || ch == '*') {
                changeToken(ch);
            }
            match();
            return;
        }

        if (Character.isLetter(ch)) {
            parseString();
            return;
        }

        if (Character.isDigit(ch)) {
            value = getConst();
            curToken = Token.CONST;
            return;
        }
        throw new WrongTokenException(ch, expression);
    }

    private void changeToken(char ch) throws ParserException {
        if (index >= expression.length()) {
            throw new MissedArgumentException("last", expression, index - 1);
        }
        else if (expression.charAt(index) == ch) {
            index++;
            if (ch == '*') {
                curToken = Token.POW;
            } else {
                curToken = Token.LOG;
            }
        }
    }

    private int getConst() throws ParserException {
        int start = index - 1;
        while (index < expression.length() &&
                Character.isDigit(expression.charAt(index))) {
            index++;
        }
        String toInt = expression.substring(start, index);
        int v;
        try {
            v = Integer.parseInt(toInt);
        } catch (NumberFormatException e) {
            throw new ConstantOverflowException(toInt);
        }
        return v;
    }

    private void parseString() throws ParserException {
        int start = index - 1;
        while (index < expression.length() &&
                (Character.isLetter(expression.charAt(index)) || Character.isDigit(expression.charAt(index)))) {
            index++;
        }
        String str = expression.substring(start, index);

        switch (str) {
            /*case "log10":
                curToken = Token.LOG10;
                return;
            case "pow10":
                curToken = Token.POW10;
                return;*/
            case "x":
            case "y":
            case "z":
                name = str;
                curToken = Token.VARIABLE;
                return;
        }
        throw new WrongTokenException(str, expression);
    }

    private void skipWhiteSpace() {
        while (index < expression.length() &&
                Character.isWhitespace(expression.charAt(index))) {
            index++;
        }
    }

    protected TripleExpression primaryVariable() throws ParserException {
        String n = name;
        getToken();
        return new Variable(n);
    }

    protected TripleExpression primaryMinus() throws ParserException {
        curToken = Token.CONST;
        value = getConst();
        getToken();
        return new Const(value);
    }

    protected TripleExpression primaryConst() throws ParserException {
        int v = value;
        getToken();
        return new Const(v);
    }

    protected void primaryLeftBracket() throws ParserException {
        if (curToken == Token.CLOSE_BRACKET) {
            openBracketNum--;
            getToken();
        } else {
            throw new WrongBracketException("opening", index - 1);
        }
    }

    protected boolean isDigit() {
        return Character.isDigit(expression.charAt(index));
    }
}
