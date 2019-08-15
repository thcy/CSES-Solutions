// practice with rainboy
// https://cses.fi/problemset/task/1097
// Removal Game
import java.io.*;
import java.util.*;

public class CSES1097 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        long[] aa = new long[1 + n];
        for (int i = 1; i <= n; i++)
            aa[i] = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= n; i++)
            aa[i] += aa[i - 1];
        long[] dp = new long[n];
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = aa[i + 1] - aa[i];
            for (int j = i + 1; j < n; j++)
                dp[j] = aa[j + 1] - aa[i] - Math.min(dp[j - 1], dp[j]);
        }
        System.out.println(dp[n - 1]);
    }
}
