// https://cses.fi/problemset/task/1749
// List Removals
// practice with rainboy
import java.io.*;

public class CSES1749 {
    static int[] tr;
    static void build(int k, int l, int r) {
        if (r - l == 1) {
            tr[k] = 1;
            return;
        }
        int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
        build(k1, l, m);
        build(k2, m, r);
        tr[k] = tr[k1] + tr[k2];
    }
    static int query(int k, int l, int r, int x) {
        tr[k]--;
        if (r - l == 1)
            return r;
        int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
        return tr[k1] >= x ? query(k1, l, m, x) : query(k2, m, r, x - tr[k1]);
    }
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int[] aa = new int[n];
        for (int i = 0; i < n; i++)
            aa[i] = sc.nextInt();
        int n_ = 1;
        while (n_ < n)
            n_ *= 2;
        tr = new int[n_ * 2];
        build(0, 0, n);
        for (int h = 0; h < n; h++) {
            int x = sc.nextInt();
            int i = query(0, 0, n, x) - 1;
            pw.print(aa[i] + " ");
        }
        pw.println();
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
