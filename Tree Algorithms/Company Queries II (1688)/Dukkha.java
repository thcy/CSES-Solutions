// https://cses.fi/problemset/task/1688
// Company Queries II
// practice with rainboy
import java.io.*;

public class CSES1688 {
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int ln = 0;
        while (1 << ln + 1 <= n - 1)
            ln++;
        int[][] pp = new int[ln + 1][n];
        int[] dd = new int[n];
        for (int i = 1; i < n; i++) {
            int p = sc.nextInt() - 1;
            dd[i] = dd[p] + 1;
            pp[0][i] = p;
        }
        for (int k = 1; k <= ln; k++)
            for (int i = 0; i < n; i++)
                pp[k][i] = pp[k - 1][pp[k - 1][i]];
        while (q-- > 0) {
            int i = sc.nextInt() - 1;
            int j = sc.nextInt() - 1;
            if (dd[i] < dd[j]) {
                int tmp = i; i = j; j = tmp;
            }
            if (dd[i] != dd[j])
                for (int k = ln; k >= 0; k--)
                    if (1 << k <= dd[i] - dd[j])
                        i = pp[k][i];
            if (i != j) {
                for (int k = ln; k >= 0; k--)
                    if (1 << k <= dd[i] && pp[k][i] != pp[k][j]) {
                        i = pp[k][i];
                        j = pp[k][j];
                    }
                i = pp[0][i];
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
