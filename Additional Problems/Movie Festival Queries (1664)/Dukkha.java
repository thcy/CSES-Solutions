// https://cses.fi/problemset/task/1664
// Movie Festival Queries
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1664 extends PrintWriter {
    CSES1664() { super(System.out); }
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
    public static void main(String[] $) { new CSES1664().main(); }
    
    static final int A = 1000000;
    static class V {
        int a, b;
        V(int a, int b) {
            this.a = a; this.b = b;
        }
    }
    void main() {
        int n = sc.nextInt();
        int q = sc.nextInt();
        V[] vv = new V[n];
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            vv[i] = new V(a, b);
        }
        int k = 0;
        while (1 << k + 1 <= n)
            k++;
        int[][] pp = new int[k + 1][A + 1];
        Arrays.sort(vv, (u, v) -> u.b - v.b);
        for (int a = 0, b = 0, i = 0; b <= A; b++) {
            while (i < n && vv[i].b == b) {
                a = Math.max(a, vv[i].a);
                i++;
            }
            pp[0][b] = a;
        }
        for (int h = 1; h <= k; h++)
            for (int a = 0; a <= A; a++)
                pp[h][a] = pp[h - 1][pp[h - 1][a]];
        while (q-- > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int m = 0;
            for (int h = k; h >= 0; h--)
                if (pp[h][b] >= a) {
                    b = pp[h][b];
                    m += 1 << h;
                }
            println(m);
        }
        flush();
    }
}
