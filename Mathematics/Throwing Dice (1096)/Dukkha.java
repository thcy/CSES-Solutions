// https://cses.fi/problemset/task/1096
// Throwing Dice
// practice with rainboy
import java.io.*;

public class CSES1096 {
    static final int MD = 1000000007;
    static void mult(int[][] aa, int[][] bb, int[][] cc) {
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++) {
                long c = 0;
                for (int k = 0; k < 6; k++)
                    c = (c + (long) aa[i][k] * bb[k][j]) % MD;
                cc[i][j] = (int) c;
            }
    }
    static void power(int[][] aa, int[][] pp, int[][] tt, long n) {
        if (n == 0) {
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++)
                    pp[i][j] = 0;
                pp[i][i] = 1;
            }
            return;
        }
        if (n % 2 == 0) {
            power(aa, tt, pp, n / 2);
            mult(tt, tt, pp);
        } else {
            power(aa, pp, tt, n / 2);
            mult(pp, pp, tt);
            mult(tt, aa, pp);
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());
        int[][] aa = new int[6][6];
        aa[0][1] = aa[1][2] = aa[2][3] = aa[3][4] = aa[4][5] = 1;
        aa[5][0] = aa[5][1] = aa[5][2] = aa[5][3] = aa[5][4] = aa[5][5] = 1;
        int[][] pp = new int[6][6];
        int[][] tt = new int[6][6];
        power(aa, pp, tt, n);
        System.out.println(pp[5][5]);
    }
}
