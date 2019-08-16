// https://cses.fi/problemset/task/1739
// Forest Queries II
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1739 {
    static int[][] tt;
    static void update(int i, int j_, int n, int x) {
        while (i < n) {
            int j = j_;
            while (j < n) {
                tt[i][j] += x;
                j |= j + 1;
            }
            i |= i + 1;
        }
    }
    static int query(int i, int j_) {
        int x = 0;
        while (i >= 0) {
            int j = j_;
            while (j >= 0) {
                x += tt[i][j];
                j &= j + 1;
                j--;
            }
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
        char[][] cc = new char[n][n];
        for (int i = 0; i < n; i++)
            sc.next().getChars(0, n, cc[i], 0);
        int[][] aa = new int[n + 1][n + 1];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (cc[i][j] == '*') {
                    aa[i + 1][j + 1] = 1;
                    cc[i][j] = 1;
                } else
                    cc[i][j] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                aa[i][j] += aa[i][j - 1];
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= n; i++)
                aa[i][j] += aa[i - 1][j];
        tt = new int[n][n];
        while (q-- > 0) {
            int t = sc.nextInt();
            if (t == 1) {
                int i = sc.nextInt() - 1;
                int j = sc.nextInt() - 1;
                update(i, j, n, (cc[i][j] ^= 1) == 1 ? 1 : -1);
            } else {
                int il = sc.nextInt();
                int jl = sc.nextInt();
                int ir = sc.nextInt();
                int jr = sc.nextInt();
                int a = aa[ir][jr] - aa[il - 1][jr] - aa[ir][jl - 1] + aa[il - 1][jl - 1];
                il--; jl--; ir--; jr--;
                a += query(ir, jr) - query(il - 1, jr) - query(ir, jl - 1) + query(il - 1, jl - 1);
                pw.println(a);
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
        String next() throws IOException {
            StringBuilder sb = new StringBuilder();
            for (byte b = skip(); b > 32; b = getc())
                sb.append((char) b);
            return sb.toString();
        }
        int nextInt() throws IOException {
            int n = 0;
            for (byte b = skip(); b > 32; b = getc())
                n = n * 10 + b - '0';
            return n;
        }
    }
}
