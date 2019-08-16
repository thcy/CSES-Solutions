// https://cses.fi/problemset/task/1647
// Range Minimum Queries I
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1647 {
    static final int INF = 0x3f3f3f3f;
    static int[] tr, aa;
    static void build(int k, int l, int r) {
        if (r - l == 1) {
            tr[k] = aa[l];
            return;
        }
        int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
        build(k1, l, m);
        build(k2, m, r);
        tr[k] = Math.min(tr[k1], tr[k2]);
    }
    static int query(int k, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql)
            return INF;
        if (ql <= l && r <= qr)
            return tr[k];
        int m = (l + r) / 2;
        int a1 = query(k * 2 + 1, l, m, ql, qr);
        int a2 = query(k * 2 + 2, m, r, ql, qr);
        return Math.min(a1, a2);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        aa = new int[n];
        for (int i = 0; i < n; i++)
            aa[i] = Integer.parseInt(st.nextToken());
        int n_ = 1;
        while (n_ < n)
            n_ *= 2;
        tr = new int[n_ * 2];
        build(0, 0, n);
        while (q-- > 0) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken()) - 1;
            int r = Integer.parseInt(st.nextToken());
            pw.println(query(0, 0, n, l, r));
        }
        pw.close();
    }
}
