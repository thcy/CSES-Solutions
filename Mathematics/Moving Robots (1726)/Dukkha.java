// https://cses.fi/problemset/task/1726
// Moving Robots
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1726 {
    static final int N = 64;
    static void mult(double[][] aa, double[][] bb, double[][] cc) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                double x = 0;
                for (int k = 0; k < N; k++)
                    x += aa[i][k] * bb[k][j];
                cc[i][j] = x;
            }
    }
    static void power(double[][] aa, double[][] pp, double[][] tt, int k) {
        if (k == 0) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++)
                    pp[i][j] = 0;
                pp[i][i] = 1;
            }
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
        StringTokenizer st = new StringTokenizer(br.readLine());
        int k = Integer.parseInt(st.nextToken());
        double[][] aa = new double[N][N];
        double[][] pp = new double[N][N];
        double[][] tt = new double[N][N];
        for (int r = 0; r < 8; r++)
            for (int c = 0; c < 8; c++) {
                int h = r * 8 + c;
                int m = 0;
                if (r > 0) m++;
                if (r < 7) m++;
                if (c > 0) m++;
                if (c < 7) m++;
                double x = 1.0 / m;
                if (r > 0) aa[(r - 1) * 8 + c][h] = x;
                if (r < 7) aa[(r + 1) * 8 + c][h] = x;
                if (c > 0) aa[r * 8 + c - 1][h] = x;
                if (c < 7) aa[r * 8 + c + 1][h] = x;
            }
        power(aa, pp, tt, k);
        double ans = 0;
        for (int i = 0; i < N; i++) {
            double x = 1;
            for (int j = 0; j < N; j++)
                x *= 1 - pp[i][j];
            ans += x;
        }
        pw.printf("%.6f\n", ans);
        pw.close();
    }
}
