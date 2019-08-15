// practice with rainboy
// https://cses.fi/problemset/task/1093
// Two Sets II
import java.io.*;
import java.util.*;

public class CSES1093 {
    static final int MD = 1000000007;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n % 4 == 1 || n % 4 == 2) {
            System.out.println(0);
            return;
        }
        int m = n * (n + 1) / 4;
        int[] dp = new int[1 + m];
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = m; j >= i; j--)
                dp[j] = (dp[j] + dp[j - i]) % MD;
        System.out.println((long) dp[m] * ((MD + 1) / 2) % MD);
    }
}
