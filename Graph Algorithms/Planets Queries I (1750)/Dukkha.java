// https://cses.fi/problemset/task/1750
// Planets Queries I
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1750 {
    static final int K = 30;
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int[][] aa = new int[K][n];
        for (int i = 0; i < n; i++)
            aa[0][i] = sc.nextInt() - 1;
        for (int k = 1; k < K; k++)
            for (int i = 0; i < n; i++)
                aa[k][i] = aa[k - 1][aa[k - 1][i]];
        while (q-- > 0) {
            int i = sc.nextInt() - 1;
            int m = sc.nextInt();
            for (int k = K - 1; k >= 0; k--)
                if (1 << k <= m) {
                    i = aa[k][i];
                    m -= 1 << k;
                }
            pw.println(i + 1);
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
