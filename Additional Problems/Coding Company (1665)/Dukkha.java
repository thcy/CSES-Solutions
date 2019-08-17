// https://cses.fi/problemset/task/1665
// Coding Company
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1665 extends PrintWriter {
    CSES1665() { super(System.out); }
    static class Scanner {
        Scanner(InputStream in) { this.in = in; } InputStream in;
        int k, l; byte[] bb = new byte[1 << 15];
        byte getc() {
            if (k >= l) {
                k = 0;
                try { l = in.read(bb); } catch (IOException e) { l = 0; }
                if (l <= 0) return -1;
            }
            return bb[k++];
        }
        int nextInt() {
            byte c = 0; while (c <= 32) c = getc();
            int a = 0;
            while (c > 32) { a = a * 10 + c - '0'; c = getc(); }
            return a;
        }
    }
    Scanner sc = new Scanner(System.in);
    public static void main(String[] $) {
        CSES1665 o = new CSES1665(); o.main(); o.flush();
    }
    
    static final int MD = 1000000007;
    void main() {
        int n = sc.nextInt();
        int x = sc.nextInt();
        int[] aa = new int[n];
        for (int i = 0; i < n; i++)
            aa[i] = sc.nextInt();
        aa = Arrays.stream(aa).boxed().sorted((a, b) -> b - a).mapToInt($->$).toArray();
        int h = n / 2, y = 0;
        for (int i = 0; i < h; i++)
            y += aa[i];
        int[][] dp = new int[h + 1][y + 1];
        int[][] dq = new int[h + 1][y + 1];
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int t = 0; t <= h; t++)
                for (int b = 0; b <= y; b++)
                    dq[t][b] = 0;
            int a = aa[i];
            for (int t = 0; t <= h; t++)
                for (int b = 0; b <= y; b++) {
                    int p = dp[t][b];
                    if (p == 0)
                        continue;
                    if (t + 1 <= h)
                        dq[t + 1][b + a] = (dq[t + 1][b + a] + p) % MD;
                    if (t - 1 >= 0)
                        dq[t - 1][b - a] = (int) ((dq[t - 1][b - a] + (long) p * t) % MD);
                    dq[t][b] = (int) ((dq[t][b] + (long) p * (t + 1)) % MD);
                }
            int[][] tmp = dp; dp = dq; dq = tmp;
        }
        int sum = 0;
        for (int b = 0; b <= x && b <= y; b++)
            sum = (sum + dp[0][b]) % MD;
        println(sum);
    }
}
