// https://cses.fi/problemset/task/1642
// Sum of Four Values
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1642 {
    static class V {
        int a, l, r;
        V(int a, int l, int r) {
            this.a = a; this.l = l; this.r = r;
        }
    }
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
        int m = n * (n - 1) / 2;
        V[] vv = new V[m];
        m = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int i_ = ii[i], j_ = ii[j];
                vv[m++] = new V(aa[i_] + aa[j_], i, j);
            }
        Arrays.sort(vv, (u, v) -> u.a != v.a ? u.a - v.a : u.l - v.l);
        for (int i = 0, j = m - 1; i < j; i++) {
            long a = vv[i].a;
            while (i < j && a + vv[j].a > x)
                j--;
            if (i < j && a + vv[j].a == x && vv[i].r < vv[j].l) {
                int il = ii[vv[i].l] + 1;
                int ir = ii[vv[i].r] + 1;
                int jl = ii[vv[j].l] + 1;
                int jr = ii[vv[j].r] + 1;
                System.out.println(il + " " + ir + " " + jl + " " + jr);
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
        int nextInt() throws IOException {
            int n = 0;
            for (byte b = skip(); b > 32; b = getc())
                n = n * 10 + b - '0';
            return n;
        }
    }
}
