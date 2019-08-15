// https://cses.fi/problemset/task/1637
// Removing Digits
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1637 {
    static final int INF = 0x3f3f3f3f;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] dp = new int[n + 1];
        Arrays.fill(dp, INF);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int x = INF;
            for (int j = i; j > 0; j /= 10) {
                int d = j % 10;
                if (d > 0)
                    x = Math.min(x, dp[i - d]);
            }
            dp[i] = x + 1;
        }
        System.out.println(dp[n]);
    }
}
