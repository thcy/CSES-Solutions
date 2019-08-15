// https://cses.fi/problemset/task/1744
// Rectangle Cutting
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1744 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int[][] dp = new int[a + 1][b + 1];
        for (int p = 1; p <= a; p++)
            for (int q = 1; q <= b; q++) {
                int x;
                if (p == q)
                    x = 0;
                else {
                    x = p * q;
                    for (int p_ = 1; p_ < p; p_++)
                        x = Math.min(x, dp[p_][q] + dp[p - p_][q] + 1);
                    for (int q_ = 1; q_ < q; q_++)
                        x = Math.min(x, dp[p][q_] + dp[p][q - q_] + 1);
                }
                dp[p][q] = x;
            }
        System.out.println(dp[a][b]);
    }
}
