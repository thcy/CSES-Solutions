// https://cses.fi/problemset/task/1706
// School Excursion
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1706 extends PrintWriter {
    CSES1706() { super(System.out); }
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
        CSES1706 o = new CSES1706(); o.main(); o.flush();
    }
    
    int[] dsu;
    int find(int i) {
        return dsu[i] < 0 ? i : (dsu[i] = find(dsu[i]));
    }
    void join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j)
            return;
        if (dsu[i] > dsu[j]) {
            dsu[j] += dsu[i];
            dsu[i] = j;
        } else {
            dsu[i] += dsu[j];
            dsu[j] = i;
        }
    }
    void main() {
        int n = sc.nextInt();
        int m = sc.nextInt();
        dsu = new int[n];
        Arrays.fill(dsu, -1);
        while (m-- > 0) {
            int i = sc.nextInt() - 1;
            int j = sc.nextInt() - 1;
            join(i, j);
        }
        int[] kk = new int[n + 1];
        for (int i = 0; i < n; i++)
            if (dsu[i] < 0) {
                int c = -dsu[i];
                kk[c]++;
            }
        int[] dp = new int[n + 1];
        int inf = n + 1;
        Arrays.fill(dp, inf);
        dp[0] = 0;
        for (int c = 1; c <= n; c++) {
            int k = kk[c];
            if (k == 0)
                continue;
            for (int a = 0; a <= n; a++) {
                if (dp[a] < k)
                    dp[a + c] = Math.min(dp[a + c], dp[a] + 1);
                dp[a] = dp[a] <= k ? 0 : inf;
            }
        }
        char[] cc = new char[n];
        for (int c = 1; c <= n; c++)
            cc[c - 1] = dp[c] == 0 ? '1' : '0';
        println(cc);
    }
}
