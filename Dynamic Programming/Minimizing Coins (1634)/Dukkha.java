// https://cses.fi/problemset/task/1634
// Minimizing Coins
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1634 {
    static final int INF = 0x3f3f3f3f;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int[] dp = new int[x + 1];
        Arrays.fill(dp, INF);
        dp[0] = 0;
        st = new StringTokenizer(br.readLine());
        while (n-- > 0) {
            int c = Integer.parseInt(st.nextToken());
            for (int y = c; y <= x; y++)
                dp[y] = Math.min(dp[y], dp[y - c] + 1);
        }
        System.out.println(dp[x] == INF ? -1 : dp[x]);
    }
}
