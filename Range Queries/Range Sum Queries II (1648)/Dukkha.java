// https://cses.fi/problemset/task/1648
// Range Sum Queries II
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1648 {
    static long[] tt;
    static void update(int i, int n, int x) {
        while (i < n) {
            tt[i] += x;
            i |= i + 1;
        }
    }
    static long query(int i) {
        long x = 0;
        while (i >= 0) {
            x += tt[i];
            i &= i + 1;
            i--;
        }
        return x;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        int[] aa = new int[n];
        tt = new long[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            aa[i] = Integer.parseInt(st.nextToken());
            update(i, n, aa[i]);
        }
        while (q-- > 0) {
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if (t == 1) {
                int i = a - 1;
                update(i, n, b - aa[i]);
                aa[i] = b;
            } else
                pw.println(query(b - 1) - query(a - 2));
        }
        pw.close();
    }
}
