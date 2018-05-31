package parser;

import expressions.TripleExpression;
import parser.exceptions.ParseException;

interface Parser<T> {
    TripleExpression<T> parse(String expression) throws ParseException;
}
