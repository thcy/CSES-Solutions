// https://cses.fi/problemset/task/1143
// Hotels
import java.io.*;
import java.util.*;

public class CSES1143 {
    static int[] tr, hh;
    static void build(int k, int l, int r) {
        if (r - l == 1)
            tr[k] = hh[l];
        else {
            int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
            build(k1, l, m);
            build(k2, m, r);
            tr[k] = Math.max(tr[k1], tr[k2]);
        }
    }
    static int update(int k, int l, int r, int x) {
        if (r - l == 1) {
            tr[k] -= x;
            return l;
        }
        int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
        int i = tr[k1] >= x ? update(k1, l, m, x) : update(k2, m, r, x);
        tr[k] = Math.max(tr[k1], tr[k2]);
        return i;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int n_ = 1;
        while (n_ < n)
            n_ *= 2;
        tr = new int[n_ * 2];
        hh = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            hh[i] = Integer.parseInt(st.nextToken());
        build(0, 0, n);
        st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (m-- > 0) {
            int x = Integer.parseInt(st.nextToken());
            int i = tr[0] >= x ? update(0, 0, n, x) + 1 : 0;
            sb.append(i + " ");
        }
        System.out.println(sb);
    }
}
