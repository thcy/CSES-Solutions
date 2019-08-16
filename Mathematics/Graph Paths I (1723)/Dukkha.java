// https://cses.fi/problemset/task/1723
// Graph Paths I
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1723 {
    static final int MD = 1000000007;
    static void mult(int[][] aa, int[][] bb, int[][] cc, int n) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                long c = 0;
                for (int k = 0; k < n; k++)
                    c = (c + (long) aa[i][k] * bb[k][j]) % MD;
                cc[i][j] = (int) c;
            }
    }
    static void power(int[][] aa, int[][] pp, int[][] tt, int n, int k) {
        if (k == 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    pp[i][j] = 0;
                pp[i][i] = 1;
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
        int[][] aa = new int[n][n];
        int[][] pp = new int[n][n];
        int[][] tt = new int[n][n];
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken()) - 1;
            int j = Integer.parseInt(st.nextToken()) - 1;
            aa[i][j]++;
        }
        power(aa, pp, tt, n, k);
        pw.println(pp[0][n - 1]);
        pw.close();
    }
}
