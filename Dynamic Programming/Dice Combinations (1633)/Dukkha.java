// https://cses.fi/problemset/task/1633
// Dice Combinations
// practice with rainboy
import java.io.*;

public class CSES1633 {
    static final int MD = 1000000007;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] dp = new int[n + 1];
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            long x = 0;
            for (int j = i - 1; j >= i - 6 && j >= 0; j--)
                x += dp[j];
            dp[i] = (int) (x % MD);
        }
        System.out.println(dp[n]);
    }
}
