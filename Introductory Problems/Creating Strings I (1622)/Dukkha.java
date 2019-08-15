// https://cses.fi/problemset/task/1622
// Creating Strings I
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1622 {
    static final int K = 40320;
    static String[] ss = new String[K];
    static int k;
    static void solve(char[] cc, int n) {
        if (n == 0) {
            ss[k++] = new String(cc);
            return;
        }
        for (int i = 0; i < n; i++) {
            char tmp;
            tmp = cc[i]; cc[i] = cc[n - 1]; cc[n - 1] = tmp;
            solve(cc, n - 1);
            tmp = cc[i]; cc[i] = cc[n - 1]; cc[n - 1] = tmp;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        char[] cc = br.readLine().toCharArray();
        int n = cc.length;
        solve(cc, n);
        Arrays.sort(ss, 0, k, (s, t) -> s.compareTo(t));
        int k_ = 1;
        for (int h = 1; h < k; h++)
            if (ss[k_ - 1].compareTo(ss[h]) != 0)
                ss[k_++] = ss[h];
        k = k_;
        pw.println(k);
        for (int h = 0; h < k; h++)
            pw.println(ss[h]);
        pw.close();
    }
}
