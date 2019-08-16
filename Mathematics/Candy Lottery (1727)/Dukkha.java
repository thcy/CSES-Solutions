// https://cses.fi/problemset/task/1727
// Candy Lottery
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1727 {
    static double power(double a, int k) {
        if (k == 0)
            return 1;
        double p = power(a, k / 2);
        p *= p;
        if (k % 2 == 1)
            p *= a;
        return p;
    }
    public static void main(String[] __) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out, true);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        double ans = k;
        for (int x = 1; x < k; x++)
            ans -= power((double) x / k, n);
        pw.printf("%.6f\n", ans);
        pw.close();
    }
}
