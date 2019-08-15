// https://cses.fi/problemset/task/1630
// Tasks and Deadlines
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1630 {
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        int n = sc.nextInt();
        Integer[] aa = new Integer[n];
        long d = 0;
        for (int i = 0; i < n; i++) {
            aa[i] = sc.nextInt();
            d += sc.nextInt();
        }
        Arrays.sort(aa);
        long a = 0, sum = 0;
        for (int i = 0; i < n; i++)
            sum += a += aa[i];
        System.out.println(d - sum);
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
