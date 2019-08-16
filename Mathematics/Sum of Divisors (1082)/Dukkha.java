// https://cses.fi/problemset/task/1082
// Sum of Divisors
// practice with rainboy
import java.io.*;

public class CSES1082 {
    static final int MD = 1000000007;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());
        long ans = 0;
        for (long a = 1; a <= n / a; a++) {
            long q = n / a;
            ans = (ans + a * q) % MD;
            if (a != q) {
                long p = n / (a + 1);
                p %= MD;
                q %= MD;
                long k = (q - p) * (q + p + 1) / 2 % MD;
                ans = (ans + k * a) % MD;
            }
        }
        if (ans < 0)
            ans += MD;
        System.out.println(ans);
    }
}
