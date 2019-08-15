// https://cses.fi/problemset/task/1640
// Sum of Two Values
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1640 {
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        int[] aa = new int[n];
        Integer[] ii = new Integer[n];
        for (int i = 0; i < n; i++) {
            aa[i] = sc.nextInt();
            ii[i] = i;
        }
        Arrays.sort(ii, (i, j) -> aa[i] - aa[j]);
        for (int i = 0, j = n - 1; i < j; i++) {
            int a = 0;
            while (i < j && (a = aa[ii[i]] + aa[ii[j]]) > x)
                j--;
            if (i < j && a == x) {
                System.out.println((ii[i] + 1) + " " + (ii[j] + 1));
                return;
            }
        }
        System.out.println("IMPOSSIBLE");
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
