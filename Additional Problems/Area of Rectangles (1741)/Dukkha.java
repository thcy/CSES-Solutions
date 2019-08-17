// https://cses.fi/problemset/task/1741
// Area of Rectangles
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1741 extends PrintWriter {
    CSES1741() { super(System.out); }
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
            boolean minus = c == '-'; if (minus) c = getc();
            int a = 0;
            while (c > 32) { a = a * 10 + c - '0'; c = getc(); }
            return minus ? -a : a;
        }
    }
    Scanner sc = new Scanner(System.in);
    public static void main(String[] $) {
        CSES1741 o = new CSES1741(); o.main(); o.flush();
    }
    
    static final int Z = 1000000, A = 1 << 21;
    static class V {
        int y, l, r;
        boolean add;
        V(int y, int l, int r, boolean add) {
            this.y = y; this.l = l; this.r = r; this.add = add;
        }
    }
    int[] tr, zz;
    void update(int k, int l, int r, int ql, int qr, int x) {
        if (qr <= l || r <= ql)
            return;
        int k1 = k * 2 + 1, k2 = k * 2 + 2;
        if (ql <= l && r <= qr)
            zz[k] += x;
        else {
            int m = (l + r) / 2;
            update(k1, l, m, ql, qr, x);
            update(k2, m, r, ql, qr, x);
        }
        tr[k] = zz[k] > 0 ? r - l : r - l == 1 ? 0 : tr[k1] + tr[k2];
    }
    void main() {
        int n = sc.nextInt();
        V[] vv = new V[n * 2];
        int m = 0;
        for (int i = 0; i < n; i++) {
            int x1 = sc.nextInt() + Z;
            int y1 = sc.nextInt() + Z;
            int x2 = sc.nextInt() + Z;
            int y2 = sc.nextInt() + Z;
            vv[m++] = new V(y1, x1, x2, true);
            vv[m++] = new V(y2, x1, x2, false);
        }
        Arrays.sort(vv, (u, v) -> u.y - v.y);
        tr = new int[A * 2];
        zz = new int[A * 2];
        int y = -1;
        long ans = 0;
        for (int h = 0; h < m; h++) {
            V v = vv[h];
            if (y != -1)
                ans += (long) (v.y - y) * tr[0];
            y = v.y;
            update(0, 0, A, v.l, v.r, v.add ? 1 : -1);
        }
        println(ans);
    }
}
