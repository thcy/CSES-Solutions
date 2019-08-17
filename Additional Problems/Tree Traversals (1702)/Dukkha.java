// https://cses.fi/problemset/task/1702
// Tree Traversals
// practice with rainboy
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
    public static void main(String[] $) {
        CSES1702 c = new CSES1702(); c.main(); c.flush();
    }
    
    void main() {
        int n = sc.nextInt();
        int[] pp = new int[n + 2];
        pp[0] = n;
        for (int i = 1; i <= n; i++)
            pp[i] = sc.nextInt() - 1;
        pp[n + 1] = n + 1;
        int[] aa = new int[n + 2];
        for (int i = 0; i < n; i++)
            aa[i] = sc.nextInt() - 1;
        aa[n] = n;
        aa[n + 1] = n + 1;
        int[] ii = new int[n + 2];
        for (int i = 0; i < n + 2; i++)
            ii[aa[i]] = i;
        int[] s1 = new int[n + 2];
        int[] s2 = new int[n + 2];
        int k1 = 0, k2 = 0;
        s1[k1++] = pp[0];
        s2[k2++] = pp[0];
        for (int i = 1; i < n + 2; i++) {
            int a = pp[i], b = pp[i - 1];
            if (ii[a] > ii[b]) {
                int p = -1, q = -1;
                while (k2 > 0 && ii[a] > ii[q = s2[k2 - 1]]) {
                    p = q;
                    k2--;
                }
                while ((q = s1[k1 - 1]) != p) {
                    print(q + 1 + " ");
                    k1--;
                }
            }
            s1[k1++] = a;
            s2[k2++] = a;
        }
        println();
    }
}
