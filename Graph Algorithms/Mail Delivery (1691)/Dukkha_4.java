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
    static int[] ij;
    static boolean[] lazy;
    static void link(int i, int h) {
        L l = new L(h);
        l.next = aa[i]; aa[i] = l;
    }
    static void hierholzer(L e, int i) {
        L f = e.next, l;
        while ((l = aa[i]) != null) {
            int h = l.h;
            if (lazy[h])
                aa[i] = l.next;
            else {
                lazy[h] = true;
                e = e.next = new L(h);
                i ^= ij[h];
            }
        }
        e.next = f;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        ij = new int[m + 1];
        lazy = new boolean[m + 1];
        aa = new L[n];
        int[] dd = new int[n];
        for (int h = 1; h <= m; h++) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken()) - 1;
            int j = Integer.parseInt(st.nextToken()) - 1;
            ij[h] = i ^ j;
            link(i, h);
            link(j, h);
            dd[i]++;
            dd[j]++;
        }
        for (int i = 0; i < n; i++)
            if (dd[i] % 2 != 0) {
                System.out.println("IMPOSSIBLE");
                return;
            }
        L e_ = new L(0);
        int i = 0;
        m++;
        for (L e = e_; e != null; e = e.next) {
            i ^= ij[e.h];
            hierholzer(e, i);
            m--;
        }
        if (m != 0) {
            System.out.println("IMPOSSIBLE");
            return;
        }
        PrintWriter pw = new PrintWriter(System.out);
        i = 0;
        for (L e = e_; e != null; e = e.next) {
            i ^= ij[e.h];
            pw.print(i + 1 + " ");
        }
        pw.println();
        pw.close();
    }
}
