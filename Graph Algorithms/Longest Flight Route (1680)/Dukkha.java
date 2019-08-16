// https://cses.fi/problemset/task/1680
// Longest Flight Route
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1680 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
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
        int[] pp = new int[n];
        dp[0] = 1;
        while (cnt > 0) {
            int i = qq[head++]; cnt--;
            ArrayList<Integer> adj = aa[i];
            for (int j : adj) {
                if (--dd[j] == 0)
                    qq[head + cnt++] = j;
                if (dp[i] != 0)
                    if (dp[j] < dp[i] + 1) {
                        dp[j] = dp[i] + 1;
                        pp[j] = i;
                    }
            }
        }
        int k = dp[n - 1];
        if (k == 0)
            pw.println("IMPOSSIBLE");
        else {
            for (int h = k - 1, i = n - 1; h >= 0; h--, i = pp[i])
                qq[h] = i;
            pw.println(k);
            for (int h = 0; h < k; h++)
                pw.print(qq[h] + 1 + " ");
            pw.println();
        }
        pw.close();
    }
}
