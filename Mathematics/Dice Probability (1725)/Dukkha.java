// https://cses.fi/problemset/task/1725
// Dice Probability
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1725 {
    public static void main(String[] __) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out, true);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int m = n * 6;
        double[] dp = new double[m + 1];
        dp[0] = 1;
        while (n-- > 0)
            for (int j = m; j >= 0; j--) {
                double x = dp[j] / 6;
                for (int h = 1; h <= 6 && j + h <= m; h++)
                    dp[j + h] += x;
                dp[j] = 0;
            }
        double ans = 0;
        for (int j = a; j <= b; j++)
            ans += dp[j];
        pw.printf("%.6f\n", ans);
        pw.close();
    }
}
