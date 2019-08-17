// https://cses.fi/problemset/task/1653
// Elevator Rides
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1653 extends PrintWriter {
    CSES1653() { super(System.out, true); } byte[] __; int $;
    { try { __ = System.in.readAllBytes(); } catch (IOException e) {} }
    int nextInt() {
        while ($ < __.length && __[$] < 33) $++;
        int a = 0;
        while ($ < __.length && __[$] > 32) a = a * 10 + __[$++] - '0';
        return a;
    }
    public static void main(String[] __) { new CSES1653().main(); }
    
    void main() {
        int n = nextInt();
        int x = nextInt();
        int[] aa = new int[n];
        for (int i = 0; i < n; i++)
            aa[i] = nextInt();
        int[] dp = new int[1 << n];
        int[] dq = new int[1 << n];
        Arrays.fill(dp, n + 1);
        dp[0] = 0;
        dq[0] = x;
        for (int b = 0; b < 1 << n; b++)
            for (int i = 0; i < n; i++)
                if ((b & 1 << i) == 0) {
                    int p = dp[b], q = dq[b], a = aa[i];
                    if (q + a <= x)
                        q += a;
                    else {
                        p++;
                        q = a;
                    }
                    int b_ = b | 1 << i;
                    if (dp[b_] > p || dp[b_] == p && dq[b_] > q) {
                        dp[b_] = p; dq[b_] = q;
                    }
                }
        println(dp[(1 << n) - 1]);
    }
}
