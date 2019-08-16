// https://cses.fi/problemset/task/1713
// Counting Divisors
// practice with rainboy
import java.io.*;

public class CSES1713 {
    static final int N = 1000000;
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int[] dd = new int[N + 1];
        for (int a = 1; a <= N; a++)
            for (int b = a; b <= N; b += a)
                dd[b]++;
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            pw.println(dd[n]);
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
