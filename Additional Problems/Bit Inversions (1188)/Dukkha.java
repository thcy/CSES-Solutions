// practice with rainboy
// https://cses.fi/problemset/task/1188
// Bit Inversions
import java.io.*;
import java.util.*;

public class CSES1188 {
    static char[] cc;
    static int[] pp, qq, tr;
    static void pull(int k, int l, int r) {
        int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
        pp[k] = pp[k1];
        if (pp[k1] == m - l && cc[l] == cc[m])
            pp[k] += pp[k2];
        qq[k] = qq[k2];
        if (qq[k2] == r - m && cc[r - 1] == cc[m - 1])
            qq[k] += qq[k1];
        tr[k] = Math.max(tr[k1], tr[k2]);
        if (cc[m - 1] == cc[m])
            tr[k] = Math.max(tr[k], qq[k1] + pp[k2]);
    }
    static void build(int k, int l, int r) {
        if (r - l == 1) {
            pp[k] = qq[k] = tr[k] = 1;
            return;
        }
        int m = (l + r) / 2;
        build(k * 2 + 1, l, m);
        build(k * 2 + 2, m, r);
        pull(k, l, r);
    }
    static void update(int k, int l, int r, int i) {
        if (r - l == 1) {
            cc[i] = cc[i] == '0' ? '1' : '0';
            return;
        }
        int m = (l + r) / 2;
        if (i < m)
            update(k * 2 + 1, l, m, i);
        else
            update(k * 2 + 2, m, r, i);
        pull(k, l, r);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        cc = br.readLine().toCharArray();
        int n = cc.length;
        int m = 1;
        while (m < n)
            m *= 2;
        pp = new int[m * 2];
        qq = new int[m * 2];
        tr = new int[m * 2];
        build(0, 0, n);
        m = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (m-- > 0) {
            int i = Integer.parseInt(st.nextToken()) - 1;
            update(0, 0, n, i);
            sb.append(tr[0] + " ");
        }
        System.out.println(sb);
    }
}
