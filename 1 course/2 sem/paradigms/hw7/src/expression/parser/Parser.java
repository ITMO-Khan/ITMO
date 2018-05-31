package expression.parser;

import expression.TripleExpression;
import expression.exceptions.*;

public interface Parser {
    TripleExpression parse(String expression) throws ParserException;
}