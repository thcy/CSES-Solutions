// https://cses.fi/problemset/task/1080
// Empty String
// practice with rainboy
import java.io.*;

public class CSES1080 {
    static final int MD = 1000000007;
    static int[][] ch;
    static void init(int n) {
        ch = new int[n + 1][n + 1];
        ch[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            ch[i][0] = 1;
            for (int j = 1; j <= i; j++)
                ch[i][j] = (ch[i - 1][j] + ch[i - 1][j - 1]) % MD;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] cc = (" " + br.readLine()).toCharArray();
        int n = cc.length - 1;
        init(n / 2);
        long[][] dp = new long[n + 1][n + 1];
        for (int i = 1; i <= n; i++)
            dp[i][i - 1] = 1;
        for (int h = n; h >= 1; h--)
            for (int j = h + 1; j <= n; j += 2) {
                long x = 0;
                for (int i = h; i < j; i += 2)
                    if (cc[i] == cc[j])
                        x = (x + dp[h][i - 1] * dp[i + 1][j - 1] % MD * ch[(j - h + 1) / 2][(i - h) / 2]) % MD;
                dp[h][j] = x;
            }
        System.out.println(dp[1][n]);
    }
}
