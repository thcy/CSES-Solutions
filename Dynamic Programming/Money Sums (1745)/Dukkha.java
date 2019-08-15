// https://cses.fi/problemset/task/1745
// Money Sums
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1745 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] aa = new int[n];
        int b = 0;
        for (int i = 0; i < n; i++)
            b += aa[i] = Integer.parseInt(st.nextToken());
        boolean[] dp = new boolean[b + 1];
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            int c = aa[i - 1];
            for (int a = b; a >= c; a--)
                dp[a] = dp[a] || dp[a - c];
        }
        int[] qq = new int[b + 1];
        int cnt = 0;
        for (int a = b; a >= 1; a--)
            if (dp[a])
                qq[cnt++] = a;
        PrintWriter pw = new PrintWriter(System.out);
        pw.println(cnt);
        while (cnt-- > 0)
            pw.print(qq[cnt] + " ");
        pw.println();
        pw.close();
    }
}
