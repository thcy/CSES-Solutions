// https://cses.fi/problemset/task/1654
// Bit Problem
// practice with rainboy
import java.io.*;

public class CSES1654 extends PrintWriter {
    CSES1654() { super(System.out); }
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
        CSES1654 c = new CSES1654(); c.main(); c.flush();
    }
    
    static final int K = 20, A = 1 << K;
    void main() {
        int n = sc.nextInt();
        int[] aa = new int[n];
        for (int i = 0; i < n; i++)
            aa[i] = sc.nextInt();
        int[] dp = new int[A];
        int[] dq = new int[A];
        for (int i = 0; i < n; i++) {
            int a = aa[i];
            dp[a]++;
            dq[a]++;
        }
        for (int h = 0; h < K; h++)
            for (int a = 0; a < A; a++)
                if ((a & 1 << h) != 0)
                    dp[a] += dp[a ^ 1 << h];
                else
                    dq[a] += dq[a ^ 1 << h];
        for (int i = 0; i < n; i++) {
            int a = aa[i];
            println(dp[a] + " " + dq[a] + " " + (n - dp[a ^ A - 1]));
        }
    }
}
