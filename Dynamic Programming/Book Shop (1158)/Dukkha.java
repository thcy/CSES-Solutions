// https://cses.fi/problemset/task/1158
// Book Shop
import java.io.*;
import java.util.*;

public class CSES1158 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int[] dp = new int[x + 1];
        int[] hh = new int[n];
        int[] ss = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            hh[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            ss[i] = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            int h = hh[i], s = ss[i];
            for (int y = x; y >= h; y--)
                dp[y] = Math.max(dp[y], dp[y - h] + s);
        }
        System.out.println(dp[x]);
    }
}
