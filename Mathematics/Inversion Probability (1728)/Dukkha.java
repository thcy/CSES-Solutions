// https://cses.fi/problemset/task/1728
// Inversion Probability
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1728 {
    static final int A = 100;
    static int[] t1, t2;
    static void update(int[] tt, int i, int x) {
        while (i <= A) {
            tt[i] += x;
            i |= i + 1;
        }
    }
    static int query(int[] tt, int i) {
        int x = 0;
        while (i >= 0) {
            x += tt[i];
            i &= i + 1;
            i--;
        }
        return x;
    }
    public static void main(String[] __) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out, true);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] aa = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            aa[i] = Integer.parseInt(st.nextToken());
        t1 = new int[A + 1];
        t2 = new int[A + 1];
        double ans = 0;
        for (int i = 0; i < n; i++) {
            int b = aa[i];
            int sum = query(t2, b);
            ans += sum / 2.0 / b;
            update(t2, b, b - 1);
        }
        Arrays.fill(t2, 0);
        for (int i = n - 1; i >= 0; i--) {
            int a = aa[i];
            int sum = query(t2, a - 1);
            int cnt = query(t1, a - 1);
            ans += cnt - sum / 2.0 / a;
            update(t2, a, a + 1);
            update(t1, a, 1);
        }
        pw.printf("%.06f\n", ans);
    }
}
