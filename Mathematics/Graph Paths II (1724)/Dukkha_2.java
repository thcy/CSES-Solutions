// https://cses.fi/problemset/task/1724
// Graph Paths II
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1724 {
    static final long INF = 0x3f3f3f3f3f3f3f3fL;
    static void mult(long[][] aa, long[][] bb, long[][] cc, int n) {
        for (int i = 0; i < n; i++) {
            long[] ci = cc[i];
            for (int j = 0; j < n; j++)
                ci[j] = INF;
            for (int k = 0; k < n; k++) {
                long a = aa[i][k];
                if (a != INF) {
                    long[] bk = bb[k];
                    for (int j = 0; j < n; j++)
                        ci[j] = Math.min(ci[j], a + bk[j]);
                }
            }
        }
    }
    static void power(long[][] aa, long[][] pp, long[][] tt, int n, int k) {
        if (k == 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    pp[i][j] = INF;
                pp[i][i] = 0;
            }
            return;
        }
        if (k % 2 == 0) {
            power(aa, tt, pp, n, k / 2);
            mult(tt, tt, pp, n);
        } else {
            power(aa, pp, tt, n, k / 2);
            mult(pp, pp, tt, n);
            mult(tt, aa, pp, n);
        }
    }
    public static void main(String[] __) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out, true);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        long[][] aa = new long[n][n];
        long[][] pp = new long[n][n];
        long[][] tt = new long[n][n];
        for (int i = 0; i < n; i++)
            Arrays.fill(aa[i], INF);
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken()) - 1;
            int j = Integer.parseInt(st.nextToken()) - 1;
            int w = Integer.parseInt(st.nextToken());
            aa[i][j] = Math.min(aa[i][j], w);
        }
        power(aa, pp, tt, n, k);
        long ans = pp[0][n - 1];
        pw.println(ans == INF ? -1 : ans);
        pw.close();
    }
}
