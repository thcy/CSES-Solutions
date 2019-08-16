// https://cses.fi/problemset/task/1736
// Polynomial Queries
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1736 {
    static int[] xx;
    static long[] tr, aa, bb;
    static void build(int k, int l, int r) {
        if (r - l == 1) {
            tr[k] = xx[l];
            return;
        }
        int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
        build(k1, l, m);
        build(k2, m, r);
        tr[k] = tr[k1] + tr[k2];
    }
    static long sum(long a, long b, int n) {
        return n * (b * 2 + (n - 1) * a) / 2;
    }
    static void update(int k, int l, int r, int ql, int qr, long a, long b) {
        if (qr <= l || r <= ql)
            return;
        if (ql <= l && r <= qr) {
            long b_ = b + (l - ql) * a;
            tr[k] += sum(a, b_, r - l);
            aa[k] += a;
            bb[k] += b_;
            return;
        }
        int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
        if (aa[k] != 0 || bb[k] != 0) {
            update(k1, l, m, l, m, aa[k], bb[k]);
            update(k2, m, r, m, r, aa[k], bb[k] + (m - l) * aa[k]);
            aa[k] = bb[k] = 0;
        }
        update(k1, l, m, ql, qr, a, b);
        update(k2, m, r, ql, qr, a, b);
        tr[k] = tr[k1] + tr[k2];
    }
    static long query(int k, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql)
            return 0;
        if (ql <= l && r <= qr)
            return tr[k];
        int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
        if (aa[k] != 0 || bb[k] != 0) {
            update(k1, l, m, l, m, aa[k], bb[k]);
            update(k2, m, r, m, r, aa[k], bb[k] + (m - l) * aa[k]);
            aa[k] = bb[k] = 0;
        }
        return query(k1, l, m, ql, qr) + query(k2, m, r, ql, qr);
    }
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int q = sc.nextInt();
        xx = new int[n];
        for (int i = 0; i < n; i++)
            xx[i] = sc.nextInt();
        int n_ = 1;
        while (n_ <= n)
            n_ *= 2;
        tr = new long[n_ * 2];
        aa = new long[n_ * 2];
        bb = new long[n_ * 2];
        build(0, 0, n);
        while (q-- > 0) {
            int t = sc.nextInt();
            int l = sc.nextInt() - 1;
            int r = sc.nextInt();
            if (t == 1)
                update(0, 0, n, l, r, 1, 1);
            else
                pw.println(query(0, 0, n, l, r));
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
