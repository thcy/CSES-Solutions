// https://cses.fi/problemset/task/1112
// Substrings
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1112 {
    static final int C = 26, MD = 1000000007;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        char[] cc = br.readLine().toCharArray();
        int m = cc.length;
        int[] ff = new int[m];
        ff[0] = -1;
        for (int j = 1; j < m; j++) {
            int i = ff[j - 1] + 1;
            while (cc[i] != cc[j]) {
                if (i == 0) {
                    i--;
                    break;
                }
                i = ff[i - 1] + 1;
            }
            ff[j] = i;
        }
        int[][] delta = new int[m][C];
        for (int j = 0; j < m; j++)
            for (int c = 0; c < C; c++) {
                int i = j;
                while (cc[i] != c + 'A') {
                    if (i == 0) {
                        i--;
                        break;
                    }
                    i = ff[i - 1] + 1;
                }
                delta[j][c] = i + 1;
            }
        int[][] dp = new int[n + 1][m + 1];
        dp[0][0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int x = dp[i][j];
                if (x == 0)
                    continue;
                for (int c = 0; c < C; c++) {
                    int j_ = delta[j][c];
                    dp[i + 1][j_] = (dp[i + 1][j_] + x) % MD;
                }
            }
        long ans = 0, q = 1;
        for (int i = n; i >= m; i--) {
            ans = (ans + dp[i][m] * q) % MD;
            q = q * 26 % MD;
        }
        System.out.println(ans);
    }
}
