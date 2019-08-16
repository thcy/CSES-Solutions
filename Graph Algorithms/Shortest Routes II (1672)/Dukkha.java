// https://cses.fi/problemset/task/1672
// Shortest Routes II
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1672 {
    static final long INF = 0x3f3f3f3f3f3f3f3fL;
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int q = sc.nextInt();
        long[][] aa = new long[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                aa[i][j] = INF;
            aa[i][i] = 0;
        }
        while (m-- > 0) {
            int i = sc.nextInt() - 1;
            int j = sc.nextInt() - 1;
            int w = sc.nextInt();
            if (aa[i][j] > w)
                aa[j][i] = aa[i][j] = w;
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++) {
                    long a = aa[i][k] + aa[k][j];
                    if (aa[i][j] > a)
                        aa[j][i] = aa[i][j] = a;
                }
        while (q-- > 0) {
            int i = sc.nextInt() - 1;
            int j = sc.nextInt() - 1;
            long a = aa[i][j];
            pw.println(a == INF ? -1 : a);
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
