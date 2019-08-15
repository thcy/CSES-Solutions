// https://cses.fi/problemset/task/1619
// Restaurant Customers
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1619 {
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        int n = sc.nextInt();
        Integer[] aa = new Integer[n + n];
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            aa[i * 2 + 0] = a * 2 + 0;
            aa[i * 2 + 1] = b * 2 + 1;
        }
        Arrays.sort(aa);
        int k = 0, k_ = 0;
        for (int i = 0; i < n + n; i++)
            if ((aa[i] & 1) == 0) {
                if (k_ < ++k)
                    k_ = k;
            } else
                k--;
        System.out.println(k_);
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
