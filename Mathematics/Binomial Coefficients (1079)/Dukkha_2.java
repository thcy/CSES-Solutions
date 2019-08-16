// https://cses.fi/problemset/task/1079
// Binomial Coefficients
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1079 {
    static final int MD = 1000000007, A = 1000000;
    static int[] ff, gg;
    static long power(long a, int k) {
        if (k == 0)
            return 1;
        long p = power(a, k / 2);
        p = p * p % MD;
        if (k % 2 == 1)
            p = p * a % MD;
        return p;
    }
    static void init() {
        ff = new int[A + 1];
        gg = new int[A + 1];
        long f = 1;
        for (int a = 0; a <= A; a++) {
            ff[a] = (int) f;
            gg[a] = (int) power(f, MD - 2);
            f = f * (a + 1) % MD;
        }
    }
    public static void main(String[] args) throws IOException {
        init();
        _Scanner sc = new _Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        while (n-- > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            pw.println((long) ff[a] * gg[b] % MD * gg[a - b] % MD);
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
