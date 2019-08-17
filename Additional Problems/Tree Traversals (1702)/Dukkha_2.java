// https://cses.fi/problemset/task/1702
// Tree Traversals
// upsolve with rainboy
// https://cses.fi/problemset/hack/1702/entry/169043/ (Noam527)
import java.io.*;
import java.util.*;

public class CSES1702 extends PrintWriter {
    CSES1702() { super(System.out, true); }
    static class Scanner {
        Scanner(InputStream in) { this.in = in; } InputStream in;
        int k, l; byte[] bb = new byte[1 << 15];
        byte getc() {
            if (k >= l) {
                k = 0;
                try { l = in.read(bb); } catch (IOException e) { l = 0; }
                if (l <= 0) return -1;
            }
            return bb[k++];
        }
        int nextInt() {
            byte c = 0; while (c <= 32) c = getc();
            int a = 0;
            while (c > 32) { a = a * 10 + c - '0'; c = getc(); }
            return a;
        }
    }
    Scanner sc = new Scanner(System.in);
    public static void main(String[] $) { new CSES1702().main(); }
    
    int[] pp, ii;
    int cnt;
    void solve(int l, int r) {
        if (l == r)
            return;
        int a = pp[cnt++], i = ii[a];
        solve(l, i);
        solve(i + 1, r);
        print(a + 1 + " ");
    }
    void main() {
        int n = sc.nextInt();
        pp = new int[n];
        for (int i = 0; i < n; i++)
            pp[i] = sc.nextInt() - 1;
        ii = new int[n];
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt() - 1;
            ii[a] = i;
        }
        solve(0, n);
        println();
    }
}
