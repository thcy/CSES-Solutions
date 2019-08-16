// https://cses.fi/problemset/task/1715
// Creating Strings II
// practice with rainboy
import java.io.*;

public class CSES1715 {
    static final int A = 26, MD = 1000000007;
    static long power(int a, int k) {
        if (k == 0)
            return 1;
        long p = power(a, k / 2);
        p = p * p % MD;
        if (k % 2 == 1)
            p = p * a % MD;
        return p;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] cc = br.readLine().toCharArray();
        int n = cc.length;
        int[] kk = new int[A];
        for (int i = 0; i < n; i++)
            kk[cc[i] - 'a']++;
        int[] ff = new int[n + 1];
        int f = 1;
        for (int i = 0; i <= n; i++) {
            ff[i] = f;
            f = (int) ((long) f * (i + 1) % MD);
        }
        long ans = ff[n];
        for (int a = 0; a < A; a++)
            ans = ans * power(ff[kk[a]], MD - 2) % MD;
        System.out.println(ans);
    }
}
