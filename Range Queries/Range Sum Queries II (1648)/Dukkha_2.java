// https://cses.fi/problemset/task/1648
// Range Sum Queries II
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1648 {
    static long[] tt;
    static void update(int i, int n, int x) {
        while (i < n) {
            tt[i] += x;
            i |= i + 1;
        }
    }
    static long query(int i) {
        long x = 0;
        while (i >= 0) {
            x += tt[i];
            i &= i + 1;
            i--;
        }
        return x;
    }
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int[] aa = new int[n];
        tt = new long[n];
        for (int i = 0; i < n; i++) {
            aa[i] = sc.nextInt();
            update(i, n, aa[i]);
        }
        while (q-- > 0) {
            int t = sc.nextInt();
            int a = sc.nextInt();
            int b = sc.nextInt();
            if (t == 1) {
                int i = a - 1;
                update(i, n, b - aa[i]);
                aa[i] = b;
            } else
                pw.println(query(b - 1) - query(a - 2));
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
