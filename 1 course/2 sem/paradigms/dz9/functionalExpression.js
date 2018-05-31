'use strict';

var cnst = function (value) {
    return function (x, y, z) {
        return value;
    }
};

var variable = function (name) {
    return function (x, y, z) {
        switch (name) {
            case 'x':
                return x;
            case 'y':
                return y;
            case 'z':
                return z;
        }
    }
};

var unary = function (apply) {
    return function (expression) {
        return function (x, y, z) {
            return apply(expression(x, y, z));
        }
    }
};

var negate = unary(
    function (expression) {
        return -expression;
    }
);

var cube = unary(
    function (expression) {
        return Math.pow(expression, 3);
    }
);

var cuberoot = unary(
    function (expression) {
        return Math.pow(expression, 1/3);
    }
);

var binary = function (apply) {
    return function (left, right) {
        return function (x, y, z) {
            return apply(left(x, y, z), right(x, y, z));
        };
    }
};

var add = binary(
    function (left, right) {
        return left + right;
    }
);

var subtract = binary(
    function (left, right) {
        return left - right;
    }
);

var multiply = binary(
    function (left, right) {
        return left * right;
    }
);

var divide = binary(
    function (left, right) {
        return left / right;
    }
);