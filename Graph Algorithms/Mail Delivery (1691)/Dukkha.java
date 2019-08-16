// https://cses.fi/problemset/task/1691
// Mail Delivery
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1691 {
    static class L {
        L next;
        int h;
        L(int h) {
            this.h = h;
        }
    }
    static L[] aa;
    static int[] ii, jj;
    static boolean[] removed;
    static void link(int i, int h) {
        L l = new L(h);
        l.next = aa[i]; aa[i] = l;
    }
    static L hierholzer(L e, int i) {
        L l;
        while ((l = aa[i]) != null) {
            int h = l.h;
            if (removed[h])
                aa[i] = l.next;
            else {
                removed[h] = true;
                e = e.next = new L(h);
                i ^= ii[h] ^ jj[h];
            }
        }
        return e;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        ii = new int[m + 1];
        jj = new int[m + 1];
        removed = new boolean[m + 1];
        aa = new L[n + 1];
        int[] dd = new int[n + 1];
        for (int h = 1; h <= m; h++) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken());
            int j = Integer.parseInt(st.nextToken());
            ii[h] = i;
            jj[h] = j;
            link(i, h);
            link(j, h);
            dd[i]++;
            dd[j]++;
        }
        for (int i = 1; i <= n; i++)
            if (dd[i] % 2 != 0) {
                System.out.println("IMPOSSIBLE");
                return;
            }
        ii[0] = 0;
        jj[0] = 1;
        L e_ = new L(0);
        int i = 0;
        m++;
        for (L e = e_; e != null; e = e.next) {
            i ^= ii[e.h] ^ jj[e.h];
            L f = e.next;
            hierholzer(e, i).next = f;
            m--;
        }
        if (m != 0) {
            System.out.println("IMPOSSIBLE");
            return;
        }
        PrintWriter pw = new PrintWriter(System.out);
        i = 0;
        for (L e = e_; e != null; e = e.next) {
            i ^= ii[e.h] ^ jj[e.h];
            pw.print(i + " ");
        }
        pw.println();
        pw.close();
    }
}
