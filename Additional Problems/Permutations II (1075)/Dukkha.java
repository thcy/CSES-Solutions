// https://cses.fi/problemset/task/1075
// Permutations II
// practice with rainboy
import java.io.*;

public class CSES1075 {
    static final int MD = 1000000007;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] dp0 = new int[n + 1][n + 1];
        int[][] dp1 = new int[n + 1][n + 1];
        dp0[1][0] = 1;
        for (int k = 2; k <= n; k++) {
            for (int a = 0; a < k; a++) {
                long x = 0;
                x = (x + (long) dp0[k - 1][a + 1] * (a + 1)) % MD;
                x = (x + (long) dp1[k - 1][a + 1] * a) % MD;
                x = (x + (long) dp0[k - 1][a] * (k - a - 2)) % MD;
                x = (x + (long) dp1[k - 1][a] * (k - a - 1)) % MD;
                dp0[k][a] = (int) x;
                x = dp1[k - 1][a];    // replace
                if (a > 0) {
                    x = (x + (long) dp0[k - 1][a - 1] * 2) % MD;
                    x = (x + (long) dp1[k - 1][a - 1]) % MD;
                }
                dp1[k][a] = (int) x;
            }
        }
        System.out.println(dp0[n][0]);
    }
}
