// https://cses.fi/problemset/task/1716
// Distributing Apples
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1716 {
    static final int MD = 1000000007;
    static long power(long a, int k) {
        if (k == 0)
            return 1;
        long p = power(a, k / 2);
        p = p * p % MD;
        if (k % 2 == 1)
            p = p * a % MD;
        return p;
    }
    static int choose(int a, int b) {
        int c = a - b;
        int fa = 0, fb = 0, fc = 0;
        int f = 1;
        for (int i = 0; i <= a; i++) {
            if (i == a)
                fa = f;
            if (i == b)
                fb = f;
            if (i == c)
                fc = f;
            f = (int) ((long) f * (i + 1) % MD);
        }
        return (int) (fa * power((long) fb * fc % MD, MD - 2) % MD);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        System.out.println(choose(m + n - 1, m));
    }
}
