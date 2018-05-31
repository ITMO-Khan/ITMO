package parser;

import expressions.TripleExpression;
import parser.exceptions.ParseException;

public interface Parser {
    TripleExpression parse(String expression) throws ParseException;
}
