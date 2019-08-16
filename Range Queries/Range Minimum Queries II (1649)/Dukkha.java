// https://cses.fi/problemset/task/1649
// Range Minimum Queries II
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1649 {
    static final int INF = 0x3f3f3f3f;
    static int[] tr, aa;
    static void build(int k, int l, int r) {
        if (r - l == 1) {
            tr[k] = aa[l];
            return;
        }
        int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
        build(k1, l, m);
        build(k2, m, r);
        tr[k] = Math.min(tr[k1], tr[k2]);
    }
    static void update(int k, int l, int r, int i, int x) {
        if (r - l == 1) {
            tr[k] = x;
            return;
        }
        int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
        if (i < m)
            update(k1, l, m, i, x);
        else
            update(k2, m, r, i, x);
        tr[k] = Math.min(tr[k1], tr[k2]);
    }
    static int query(int k, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql)
            return INF;
        if (ql <= l && r <= qr)
            return tr[k];
        int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
        int a1 = query(k1, l, m, ql, qr);
        int a2 = query(k2, m, r, ql, qr);
        return Math.min(a1, a2);
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
        tr = new int[n_ * 2];
        build(0, 0, n);
        while (q-- > 0) {
            int t = sc.nextInt();
            if (t == 1) {
                int i = sc.nextInt() - 1;
                int x = sc.nextInt();
                update(0, 0, n, i, x);
            } else {
                int l = sc.nextInt() - 1;
                int r = sc.nextInt();
                pw.println(query(0, 0, n, l, r));
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
