// https://cses.fi/problemset/task/1081
// Common Divisors
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1081 {
    static final int X = 1000000;
    static int[] kk = new int[X + 1];
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        int n = sc.nextInt();
        if (n == 1) {
            int x = sc.nextInt();
            System.out.println(x);
            return;
        }
        while (n-- > 0) {
            int x = sc.nextInt();
            kk[x]++;
        }
        for (int a = X; a >= 2; a--) {
            int k = 0;
            for (int b = a; b <= X; b += a)
                k += kk[b];
            if (k >= 2) {
                System.out.println(a);
                return;
            }
        }
        System.out.println(1);
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
