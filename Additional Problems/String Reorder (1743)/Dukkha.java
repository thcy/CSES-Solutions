// https://cses.fi/problemset/task/1743
// String Reorder
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1743 extends PrintWriter {
    CSES1743() { super(System.out); }
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
        int m = 1 << 7; byte[] cc = new byte[m];
        int read() {
            byte c = 0; while (c <= 32) c = getc();
            int n = 0;
            while (c > 32) {
                if (n == m) cc = Arrays.copyOf(cc, m <<= 1);
                cc[n++] = c; c = getc();
            }
            return n;
        }
        byte[] nextBytes() { int n = read(); return Arrays.copyOf(cc, n); }
    }
    Scanner sc = new Scanner(System.in);
    public static void main(String[] $) {
        CSES1743 c = new CSES1743(); c.main(); c.flush();
    }
    
    static final int A = 26;
    void main() {
        byte[] cc = sc.nextBytes();
        int n = cc.length;
        int[] kk = new int[A];
        for (int i = 0; i < n; i++) {
            int a = cc[i] - 'A';
            kk[a]++;
        }
        for (int a = 0; a < A; a++)
            if (n < kk[a] * 2 - 1) {
                println(-1);
                return;
            }
        int p = -1;
        for (int i = 0; i < n; i++) {
            int a = 0;
            while (a < A && (a == p || kk[a] == 0))
                a++;
            int b = 0;
            for (int c = 1; c < A; c++)
                if (kk[b] < kk[c])
                    b = c;
            a = a != b && n - i - 1 < kk[b] * 2 - 1 ? b : a;
            kk[a]--;
            cc[i] = (byte) (a + 'A');
            p = a;
        }
        println(new String(cc));
    }
}
