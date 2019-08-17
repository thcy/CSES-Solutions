// https://cses.fi/problemset/task/1078
// Grid Paths
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1078 {
    static final int MD = 1000000007;
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
    static void init(int n) {
        ff = new int[n];
        gg = new int[n];
        long f = 1;
        for (int i = 0; i < n; i++) {
            ff[i] = (int) f;
            gg[i] = (int) power(f, MD - 2);
            f = f * (i + 1) % MD;
        }
    }
    static long ch(int n, int k) {
        return (long) ff[n] * gg[k] % MD * gg[n - k] % MD;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        init(n * 2);
        int[] xx = new int[m + 1];
        int[] yy = new int[m + 1];
        for (int h = 0; h < m; h++) {
            st = new StringTokenizer(br.readLine());
            xx[h] = Integer.parseInt(st.nextToken()) - 1;
            yy[h] = Integer.parseInt(st.nextToken()) - 1;
        }
        xx[m] = n - 1;
        yy[m] = n - 1;
        Integer[] ii = new Integer[m + 1];
        for (int h = 0; h <= m; h++)
            ii[h] = h;
        Arrays.sort(ii, (i, j) -> xx[i] != xx[j] ? xx[i] - xx[j] : yy[i] - yy[j]);
        int[] zz = new int[m + 1];
        for (int h = 0; h <= m; h++) {
            int j = ii[h];
            int x = xx[j];
            int y = yy[j];
            long z = ch(x + y, x);
            for (int h_ = 0; h_ < h; h_++) {
                int i = ii[h_];
                if (xx[i] <= xx[j] && yy[i] <= yy[j]) {
                    x = xx[j] - xx[i];
                    y = yy[j] - yy[i];
                    z = (z - zz[i] * ch(x + y, x)) % MD;
                }
            }
            zz[j] = (int) z;
        }
        System.out.println((zz[m] + MD) % MD);
    }
}
