// https://cses.fi/problemset/task/1639
// Edit Distance
// practice with rainboy
import java.io.*;

public class CSES1639 {
    static final int INF = 0x3f3f3f3f;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] aa = br.readLine().toCharArray();
        char[] bb = br.readLine().toCharArray();
        int n = aa.length;
        int m = bb.length;
        int[][] dp = new int[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
            dp[i][0] = i;
        for (int j = 0; j <= m; j++)
            dp[0][j] = j;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                dp[i][j] = aa[i - 1] == bb[j - 1] ? dp[i - 1][j - 1] :
                Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])) + 1;
        System.out.println(dp[n][m]);
    }
}
