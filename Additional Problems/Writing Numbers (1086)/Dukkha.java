// practice with rainboy
// https://cses.fi/problemset/task/1086
// Writing Numbers
import java.io.*;

public class CSES1086 {
    static long[] p10;
    static long[] pp, dd, qq;
    static void init() {
        p10 = new long[19];
        long p = 1;
        for (int i = 0; i < 19; i++) {
            p10[i] = p;
            p *= 10;
        }
        pp = new long[19];
        dd = new long[19];
        qq = new long[19];
    }
    static int preprocess(long x) {
        long p = x, q = 0;
        int k = 0;
        while (x > 0) {
            p /= 10;
            pp[k] = p;
            qq[k] = q;
            q += (dd[k] = x % 10) * p10[k];
            k++;
            x /= 10;
        }
        return k;
    }
    static long count(int k, int b) {
        long ans = 0;
        for (int i = 0; i < k - 1 + b; i++) {
            ans += (pp[i] - 1 + b) * p10[i];
            if (dd[i] >= b)
                ans += dd[i] == b ? 1 + qq[i] : p10[i];
        }
        return ans;
    }
    public static void main(String[] args) throws IOException {
        init();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());
        // (x - 10^17) * 18 / 10 <= n
        long lower = 0, upper = 1000000000000000000L;
        while (upper - lower > 1) {
            long x = (lower + upper) / 2;
            int k = preprocess(x);
            if (count(k, 0) <= n && count(k, 1) <= n)
                lower = x;
            else
                upper = x;
        }
        System.out.println(lower);
    }
}
