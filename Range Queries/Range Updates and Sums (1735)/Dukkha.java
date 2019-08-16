// https://cses.fi/problemset/task/1735
// Range Updates and Sums
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1735 {
    static int[] aa;
    static long[] tr, inc, set;
    static void build(int k, int l, int r) {
        if (r - l == 1) {
            tr[k] = aa[l];
            return;
        }
        int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
        build(k1, l, m);
        build(k2, m, r);
        tr[k] = tr[k1] + tr[k2];
    }
    static void push(int k, int l, int r) {
        int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
        if (set[k] != 0) {
            update(k1, l, m, l, m, 2, set[k]);
            update(k2, m, r, m, r, 2, set[k]);
            set[k] = 0;
        } else if (inc[k] != 0) {
            update(k1, l, m, l, m, 1, inc[k]);
            update(k2, m, r, m, r, 1, inc[k]);
            inc[k] = 0;
        }
    }
    static void update(int k, int l, int r, int ql, int qr, int t, long x) {
        if (qr <= l || r <= ql)
            return;
        if (ql <= l && r <= qr) {
            if (t == 1) {
                tr[k] += (r - l) * x;
                if (set[k] == 0)
                    inc[k] += x;
                else
                    set[k] += x;
            } else {
                tr[k] = (r - l) * x;
                set[k] = x;
                inc[k] = 0;
            }
            return;
        }
        push(k, l, r);
        int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
        update(k1, l, m, ql, qr, t, x);
        update(k2, m, r, ql, qr, t, x);
        tr[k] = tr[k1] + tr[k2];
    }
    static long query(int k, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql)
            return 0;
        if (ql <= l && r <= qr)
            return tr[k];
        push(k, l, r);
        int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
        return query(k1, l, m, ql, qr) + query(k2, m, r, ql, qr);
    }
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int q = sc.nextInt();
        aa = new int[n];
        for (int i = 0; i < n; i++)
            aa[i] = sc.nextInt();
        int n_ = 1;
        while (n_ < n)
            n_ *= 2;
        tr = new long[n_ * 2];
        inc = new long[n_ * 2];
        set = new long[n_ * 2];
        build(0, 0, n);
        while (q-- > 0) {
            int t = sc.nextInt();
            int l = sc.nextInt() - 1;
            int r = sc.nextInt();
            if (t != 3) {
                int x = sc.nextInt();
                update(0, 0, n, l, r, t, x);
            } else
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
