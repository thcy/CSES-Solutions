// https://cses.fi/problemset/task/1651
// Range Update Queries
// practice with rainboy
import java.io.*;

public class CSES1651 {
    static long[] tt;
    static void update(int i, int n, int a) {
        while (i < n) {
            tt[i] += a;
            i |= i + 1;
        }
    }
    static long query(int i) {
        long a = 0;
        while (i >= 0) {
            a += tt[i];
            i &= i + 1;
            i--;
        }
        return a;
    }
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int q = sc.nextInt();
        tt = new long[n];
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            update(i, n, a);
            update(i + 1, n, -a);
        }
        while (q-- > 0) {
            int t = sc.nextInt();
            if (t == 1) {
                int l = sc.nextInt() - 1;
                int r = sc.nextInt() - 1;
                int a = sc.nextInt();
                update(l, n, a);
                update(r + 1, n, -a);
            } else {
                int i = sc.nextInt() - 1;
                pw.println(query(i));
            }
        }
        pw.close();
    }
    static class _Scanner {
        InputStream is;
        _Scanner(InputStream is) {
            this.is = is;
        }
        byte[] bb = new byte[1 << 15];
        int k, l;
        byte getc() throws IOException {
            if (k >= l) {
                k = 0;
                l = is.read(bb);
                if (l < 0) return -1;
            }
            return bb[k++];
        }
        byte skip() throws IOException {
            byte b;
            while ((b = getc()) <= 32)
                ;
            return b;
        }
        int nextInt() throws IOException {
            int n = 0;
            for (byte b = skip(); b > 32; b = getc())
                n = n * 10 + b - '0';
            return n;
        }
    }
}
