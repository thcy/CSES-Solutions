// https://cses.fi/problemset/task/1737
// Range Queries and Copies
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1737 {
    static class T {
        T l, r;
        long x;
    }
    static int[] aa;
    static T build(int l, int r) {
        T t = new T();
        if (r - l == 1)
            t.x = aa[l];
        else {
            int m = (l + r) / 2;
            t.l = build(l, m);
            t.r = build(m, r);
            t.x = t.l.x + t.r.x;
        }
        return t;
    }
    static T update(T t, int l, int r, int i, int x) {
        T t_ = new T();
        if (r - l == 1)
            t_.x = x;
        else {
            int m = (l + r) / 2;
            if (i < m) {
                t_.l = update(t.l, l, m, i, x);
                t_.r = t.r;
            } else {
                t_.l = t.l;
                t_.r = update(t.r, m, r, i, x);
            }
            t_.x = t_.l.x + t_.r.x;
        }
        return t_;
    }
    static long query(T t, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql || t == null)
            return 0;
        if (ql <= l && r <= qr)
            return t.x;
        int m = (l + r) / 2;
        return query(t.l, l, m, ql, qr) + query(t.r, m, r, ql, qr);
    }
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int q = sc.nextInt();
        aa = new int[n];
        for (int i = 0; i < n; i++)
            aa[i] = sc.nextInt();
        T[] tt = new T[q];
        int k = 0;
        tt[k++] = build(0, n);
        while (q-- > 0) {
            int t = sc.nextInt();
            int h = sc.nextInt() - 1;
            if (t == 1) {
                int i = sc.nextInt() - 1;
                int x = sc.nextInt();
                tt[h] = update(tt[h], 0, n, i, x);
            } else if (t == 3) {
                tt[k++] = tt[h];
            } else {
                int l = sc.nextInt() - 1;
                int r = sc.nextInt();
                pw.println(query(tt[h], 0, n, l, r));
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
