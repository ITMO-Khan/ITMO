package search;
 
public class BinarySearchSpan {
    // Pre: args.length > 0
    public static void main(String[] args) {
        assert args.length > 0 : "enter the val x!";
 
        int n = args.length - 1;
        int x = Integer.parseInt(args[0]);
 
        int l = iterBinSearch(x, 0, n + 1, args);
        int r = recBinSearch(x, 1, n + 1, args);
 
        if (l == n || Integer.parseInt(args[l + 1]) != x) {
            System.out.println(l + " 0");
        } else {
            System.out.println(l + " " + (r - l + 1));
        }
    }
 
    // Pre: 0 <= l < r <= a.length
    // && if (r - l > 1) forall i, j = l + 1 to r - 1 :
    // if (i < j) a[i] > a[j]
    public static int iterBinSearch(int x, int l, int r, String[] a) {
        // Pre: 0 <= l < r <= a.length
        int m = (l + r) / 2;
        // Post: 0 < l' == l <= m == (l + r) / 2 <= r == r' <= a.length
 
        // Inv: 0 <= l <= m <= r <= a.length && a == a'
        // && (r == a.length || a[r] <= x) && (a[l] == 0 || a[l] > x)
        // Pre: Inv
        while (l < r - 1) {
            // Pre: Inv && l < r - 1
            if (Integer.parseInt(a[m]) <= x) {
                // Pre: Inv && l < r - 1 && a[m] <= x
                r = m;
                // Post: Inv && r == m
            } else {
                // Pre: Inv && l < r - 1 && a[m] > x
                l = m;
                // Post: Inv && l == m
            }
            // Post: Inv
 
            // Pre: Inv
            m = (l + r) / 2;
            // Post: Inv && m == (l + r) / 2
        }
        // Post: Inv && l >= r - 1
        return r - 1;
    }
    // Post: a == a' && l < R <= r
    // && (R == r && (r - l == 1 || a[r - 1] > x)) || (a[R] <= x && (R == l + 1 || a[R - 1] > x))
 
    // Pre: 0 <= l <= r <= a.length
    // && if (r - l > 1) forall i, j = l + 1 to r - 1:
    // if (i < j) a[i] > a[j]
    public static int recBinSearch(int x, int l, int r, String[] a) {
        // Pre: 0 <= l <= r <= a.length
        int m = (l + r) / 2;
        // Post: m == (l + r) / 2 && 0 <= l <= m <= r <= a.length
 
        // Inv: 0 <= l <= m <= r <= a.length && a == a'
        // && (l == 0 || a[l] >= x) && (r == n || a[r] < x)
        // Pre: Inv
        if (l < r - 1) {
            // Pre: Inv && l < r - 1
            if (Integer.parseInt(a[m]) >= x) {
                // Pre: Inv && l < r - 1 && a[m] >= x
                return recBinSearch(x, m, r, a);
                // Post: Inv
            } else {
                // Pre: Inv && l < r - 1 && a[m] < x
                return recBinSearch(x, l, m, a);
                // Post: Inv
            }
            // Post: Inv
        }
        // Post: l < r - 1
        return l - 1;
    }
    // Post: a == a' && 0 <= R < a.length && a[R] >= x && (R == a.length - 1 || a[R + 1] < x)
}