package expression;

public class Variable implements TripleExpression {
   private final String name;

   public Variable(String s) {
       name = s;
   }

    @Override
    public int evaluate(int x, int y, int z) {
       switch (name) {
           case "x" : return x;
           case "y" : return y;
           case "z" : return z;
       }
       return 0;
   }
}