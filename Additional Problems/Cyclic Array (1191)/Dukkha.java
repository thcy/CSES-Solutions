// https://cses.fi/problemset/task/1191
// Cyclic Array
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1191 {
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        int n = sc.nextInt();
        long b = sc.nextLong();
        long[] aa = new long[1 + n + n];
        for (int i = 1; i <= n; i++)
            aa[n + i] = aa[i] = sc.nextInt();
        for (int i = 1; i <= n + n; i++)
            aa[i] += aa[i - 1];
        int l = 0;
        while (1 << l + 1 <= n)
            l++;
        int[][] pp = new int[l + 1][1 + n + n];
        for (int i = 1, j = 1; i <= n + n; i++) {
            while (j < n + n && aa[j] - aa[i - 1] <= b)
                j++;
            pp[0][i] = j;
        }
        for (int k = 1; k <= l; k++)
            for (int i = 1; i <= n + n; i++)
                pp[k][i] = pp[k - 1][pp[k - 1][i]];
        int ans = n;
        for (int i = 1; i <= n; i++) {
            int cnt = 1;
            int j = i;
            for (int k = l; k >= 0; k--)
                if (pp[k][j] < i + n) {
                    j = pp[k][j];
                    cnt += 1 << k;
                }
            ans = Math.min(ans, cnt);
        }
        System.out.println(ans);
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
        int nextInt() throws IOException {
            int n = 0;
            for (byte b = skip(); b > 32; b = getc())
                n = n * 10 + b - '0';
            return n;
        }
        long nextLong() throws IOException {
            long n = 0;
            for (byte b = skip(); b > 32; b = getc())
                n = n * 10 + b - '0';
            return n;
        }
    }
}
