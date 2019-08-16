// https://cses.fi/problemset/task/1681
// Game Routes
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1681 {
    static final int MD = 1000000007;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        ArrayList[] aa = new ArrayList[n];
        for (int i = 0; i < n; i++)
            aa[i] = new ArrayList<Integer>();
        int[] dd = new int[n];
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken()) - 1;
            int j = Integer.parseInt(st.nextToken()) - 1;
            aa[i].add(j);
            dd[j]++;
        }
        int[] qq = new int[n];
        int head = 0, cnt = 0;
        for (int i = 0; i < n; i++)
            if (dd[i] == 0)
                qq[head + cnt++] = i;
        int[] dp = new int[n];
        dp[0] = 1;
        while (cnt > 0) {
            int i = qq[head++]; cnt--;
            ArrayList<Integer> adj = aa[i];
            for (int j : adj) {
                if (--dd[j] == 0)
                    qq[head + cnt++] = j;
                dp[j] = (dp[j] + dp[i]) % MD;
            }
        }
        System.out.println(dp[n - 1]);
    }
}
