// practice with rainboy
// https://cses.fi/problemset/task/1140
// Projects
import java.io.*;
import java.util.*;

public class CSES1140 {
    static class V {
        int a, b;
        long p;
        V(int a, int b, long p) {
            this.a = a; this.b = b; this.p = p;
        }
    }
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        int n = sc.nextInt();
        V[] vv = new V[n];
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int p = sc.nextInt();
            vv[i] = new V(a, b, p);
        }
        Arrays.sort(vv, (u, v) -> u.b - v.b);
        for (int j = 0; j < n; j++) {
            int lower = -1, upper = j;
            while (upper - lower > 1) {
                int i = (lower + upper) / 2;
                if (vv[i].b < vv[j].a)
                    lower = i;
                else
                    upper = i;
            }
            if (lower != -1)
                vv[j].p += vv[lower].p;
            if (j > 0 && vv[j].p < vv[j - 1].p)
                vv[j].p = vv[j - 1].p;
        }
        System.out.println(vv[n - 1].p);
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
