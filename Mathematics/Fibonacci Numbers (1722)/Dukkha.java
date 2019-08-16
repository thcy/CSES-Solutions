// https://cses.fi/problemset/task/1722
// Fibonacci Numbers
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1722 {
    static final int MD = 1000000007;
    static void mult(int[][] aa, int[][] bb, int[][] cc) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
                long c = 0;
                for (int k = 0; k < 2; k++)
                    c += (long) aa[i][k] * bb[k][j];
                cc[i][j] = (int) (c % MD);
            }
    }
    static void power(int[][] aa, int[][] pp, int[][] tt, long k) {
        if (k == 0) {
            pp[0][0] = pp[1][1] = 1;
            pp[0][1] = pp[1][0] = 0;
            return;
        }
        if (k % 2 == 0) {
            power(aa, tt, pp, k / 2);
            mult(tt, tt, pp);
        } else {
            power(aa, pp, tt, k / 2);
            mult(pp, pp, tt);
            mult(tt, aa, pp);
        }
    }
    public static void main(String[] __) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out, true);
        StringTokenizer st;
        int[][] aa = new int[2][2];
        int[][] pp = new int[2][2];
        int[][] tt = new int[2][2];
        aa[0][1] = aa[1][0] = aa[1][1] = 1;
        st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());
        power(aa, pp, tt, n);
        pw.println(pp[0][1]);
        pw.close();
    }
}
