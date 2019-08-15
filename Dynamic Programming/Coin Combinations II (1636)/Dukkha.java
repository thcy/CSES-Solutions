// https://cses.fi/problemset/task/1636
// Coin Combinations II
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1636 {
    static final int MD = 1000000007;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int[] dp = new int[x + 1];
        dp[0] = 1;
        st = new StringTokenizer(br.readLine());
        while (n-- > 0) {
            int c = Integer.parseInt(st.nextToken());
            for (int y = c; y <= x; y++)
                dp[y] = (dp[y] + dp[y - c]) % MD;
        }
        System.out.println(dp[x]);
    }
}
