// https://cses.fi/problemset/task/1638
// Grid Paths
// practice with rainboy
import java.io.*;

public class CSES1638 {
    static final int MD = 1000000007;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        char[][] cc = new char[n][n];
        for (int i = 0; i < n; i++)
            br.readLine().getChars(0, n, cc[i], 0);
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (cc[i][j] == '*')
                    continue;
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else {
                    int x = 0;
                    if (i > 0)
                        x += dp[i - 1][j];
                    if (j > 0)
                        x += dp[i][j - 1];
                    dp[i][j] = x % MD;
                }
            }
        System.out.println(dp[n - 1][n - 1]);
    }
}
