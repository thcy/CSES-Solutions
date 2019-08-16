// https://cses.fi/problemset/task/1712
// Exponentiation II
// practice with rainboy
import java.io.*;

public class CSES1712 {
    static final int MD = 1000000007, T = MD - 1;
    static long power(int a, int k, int md) {
        if (k == 0)
            return 1;
        long p = power(a, k / 2, md);
        p = p * p % md;
        if (k % 2 == 1)
            p = p * a % md;
        return p;
    }
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        while (n-- > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            pw.println(power(a, (int) power(b, c, T), MD));
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
