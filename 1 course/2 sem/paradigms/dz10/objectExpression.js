'use strict';

function Const(value) {
    this.value = value;
}

Const.prototype.toString = function () {
    return this.value.toString();
};
Const.prototype.evaluate = function (x, y, z) {
    return this.value;
};

function Variable(varName) {
    this.name = varName;
}

Variable.prototype.toString = function () {
    return this.name.toString();
};
Variable.prototype.evaluate = function (x, y, z) {
    switch (this.name) {
        case 'x':
            return x;
        case 'y':
            return y;
        case 'z':
	    return z;
    }
};

function Unary(expression) {
    this.expression = expression;
}

Unary.prototype.toString = function () {
    return this.expression.toString() + ' ' + this.symbol;
};
Unary.prototype.evaluate = function (x, y, z) {
    return this.apply(this.expression.evaluate(x, y, z));
};

function Negate(expression) {
    Unary.call(this, expression);
}

Negate.prototype = Object.create(Unary.prototype);
Negate.prototype.symbol = 'negate';
Negate.prototype.apply = function (value) {
    return -value;
};

function Square(expression) {
    Unary.call(this, expression);
}

Square.prototype = Object.create(Unary.prototype);
Square.prototype.symbol = 'square';
Square.prototype.apply = function (value) {
    return Math.pow(value, 2);
};

function Sqrt(expression) {
    Unary.call(this, expression);
}

Sqrt.prototype = Object.create(Unary.prototype);
Sqrt.prototype.symbol = 'sqrt';
Sqrt.prototype.apply = function (value) {
    return Math.sqrt(Math.abs(value));
};

function Binary(first, second) {
    this.first = first;
    this.second = second;
}

Binary.prototype.toString = function () {
    return this.first.toString() + ' ' + this.second.toString() + ' ' + this.symbol;
};
Binary.prototype.evaluate = function (x, y, z) {
    return this.apply(this.first.evaluate(x, y, z), this.second.evaluate(x, y, z));
};

function Add(first, second) {
    Binary.call(this, first, second);
}

Add.prototype = Object.create(Binary.prototype);
Add.prototype.symbol = '+';
Add.prototype.apply = function (first, second) {
    return first + second;
};

function Subtract(first, second) {
    Binary.call(this, first, second);
}

Subtract.prototype = Object.create(Binary.prototype);
Subtract.prototype.symbol = '-';
Subtract.prototype.apply = function (first, second) {
    return first - second;
};

function Multiply(first, second) {
    Binary.call(this, first, second);
}

Multiply.prototype = Object.create(Binary.prototype);
Multiply.prototype.symbol = '*';
Multiply.prototype.apply = function (first, second) {
    return first * second;
};

function Divide(first, second) {
    Binary.call(this, first, second);
}

Divide.prototype = Object.create(Binary.prototype);
Divide.prototype.symbol = '/';
Divide.prototype.apply = function (first, second) {
    return first / second;
};