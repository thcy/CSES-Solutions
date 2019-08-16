// https://cses.fi/problemset/task/1690
// Hamiltonian Flights
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1690 {
    static final int MD = 1000000007;
    static ArrayList[] aa;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        aa = new ArrayList[n];
        for (int i = 0; i < n; i++)
            aa[i] = new ArrayList<Integer>();
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken()) - 1;
            int j = Integer.parseInt(st.nextToken()) - 1;
            aa[i].add(j);
        }
        int[][] dp = new int[1 << n][n];
        dp[1 << 0][0] = 1;
        for (int b = 1; b < 1 << n; b += 2)
            for (int i = 0; i < n - 1; i++) {
                int x = dp[b][i];
                if (x == 0)
                    continue;
                ArrayList<Integer> adj = aa[i];
                for (int j : adj)
                    if ((b & 1 << j) == 0) {
                        int b_ = b | 1 << j;
                        dp[b_][j] = (dp[b_][j] + x) % MD;
                    }
            }
        System.out.println(dp[(1 << n) - 1][n - 1]);
    }
}
