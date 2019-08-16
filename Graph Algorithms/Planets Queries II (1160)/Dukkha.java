// https://cses.fi/problemset/task/1160/
// Teleporters
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1160 {
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int[] aa = new int[n];
        for (int i = 0; i < n; i++)
            aa[i] = sc.nextInt() - 1;
        int[] mm = new int[1 + n];
        int[] cc = new int[n];
        int[] dd = new int[n];
        int[] hh = new int[n];
        int[][] pp = new int[n][];
        int[] ll = new int[n];
        int c_ = 0;
        int[] bb = new int[n];
        for (int i = 0, j; i < n; i++) {
            if (cc[i] != 0)
                continue;
            j = i;
            while (cc[j] == 0) {
                cc[j] = -1;
                j = aa[j];
            }
            int c, d;
            if (cc[j] == -1) {
                c = ++c_;
                d = 0;
                int h = 0;
                while (cc[j] == -1) {
                    cc[j] = c;
                    hh[j] = h++;
                    j = aa[j];
                }
                mm[c] = h;
            } else {
                c = cc[j];
                d = dd[j];
            }
            j = i;
            int m = 0;
            while (cc[j] == -1) {
                cc[j] = c;
                bb[m++] = j;
                j = aa[j];
            }
            bb[m] = j;
            for (int h = m - 1; h >= 0; h--) {
                j = bb[h];
                int d_ = dd[j] = d + m - h;
                int l = 0;
                while (1 << l + 1 <= d_)
                    l++;
                int[] qq = new int[l + 1];
                qq[0] = bb[h + 1];
                for (int k = 1; k <= l; k++)
                    qq[k] = pp[qq[k - 1]][k - 1];
                pp[j] = qq;
                ll[j] = l;
            }
        }
        while (q-- > 0) {
            int i = sc.nextInt() - 1;
            int j = sc.nextInt() - 1;
            if (cc[i] != cc[j] || dd[i] < dd[j]) {
                pw.println(-1);
                continue;
            }
            int d = dd[i] - dd[j];
            if (d > 0)
                for (int l = ll[i]; l >= 0; l--)
                    if (1 << l <= dd[i] - dd[j])
                        i = pp[i][l];
            int ans;
            if (dd[i] != 0)
                ans = i == j ? d : -1;
            else {
                int h = hh[j] - hh[i];
                if (h < 0)
                    h += mm[cc[i]];
                ans = d + h;
            }
            pw.println(ans);
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
                l = is.read(bb); //if (l < 0) return -1;
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
