// https://cses.fi/problemset/task/1095
// Exponentiation
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1095 {
    static final int MD = 1000000007;
    static long power(int a, int b) {
        if (b == 0)
            return 1;
        long p = power(a, b / 2);
        p = p * p % MD;
        if (b % 2 == 1)
            p = p * a % MD;
        return p;
    }
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        int n = sc.nextInt();
        PrintWriter pw = new PrintWriter(System.out);
        while (n-- > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            pw.println(power(a, b));
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
