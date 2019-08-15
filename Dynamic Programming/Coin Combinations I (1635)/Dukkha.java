// https://cses.fi/problemset/task/1635
// Coin Combinations I
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1635 {
    static final int MD = 1000000007;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] cc = new int[n];
        for (int i = 0; i < n; i++)
            cc[i] = Integer.parseInt(st.nextToken());
        int[] dp = new int[x + 1];
        dp[0] = 1;
        for (int y = 1; y <= x; y++) {
            long c = 0;
            for (int i = 0; i < n; i++)
                if (y >= cc[i])
                    c += dp[y - cc[i]];
            dp[y] = (int) (c % MD);
        }
        System.out.println(dp[x]);
    }
}
