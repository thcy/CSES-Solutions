// https://cses.fi/problemset/task/1746
// Array Description
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1746 {
    static final int MD = 1000000007;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] dp = new int[m + 1];
        int[] dq = new int[m + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(st.nextToken());
            if (i == 0) {
                if (x == 0)
                    Arrays.fill(dq, 1);
                else {
                    Arrays.fill(dq, 0);
                    dq[x] = 1;
                }
            } else {
                if (x == 0)
                    for (x = 1; x <= m; x++) {
                        long z = dp[x];
                        if (x > 1)
                            z += dp[x - 1];
                        if (x < m)
                            z += dp[x + 1];
                        dq[x] = (int) (z % MD);
                    }
                else {
                    Arrays.fill(dq, 0);
                    long z = dp[x];
                    if (x > 1)
                        z += dp[x - 1];
                    if (x < m)
                        z += dp[x + 1];
                    dq[x] = (int) (z % MD);
                }
            }
            int[] tmp = dp; dp = dq; dq = tmp;
        }
        long ans = 0;
        for (int x = 1; x <= m; x++)
            ans += dp[x];
        System.out.println(ans % MD);
    }
}
