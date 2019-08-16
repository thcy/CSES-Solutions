// https://cses.fi/problemset/task/1693
// Teleporters Path
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1693 {
    static class L {
        L next;
        int j;
        L(int j) {
            this.j = j;
        }
    }
    static L[] aa;
    static void hierholzer(L e) {
        L f = e.next, l;
        int i = e.j;
        while ((l = aa[i]) != null) {
            aa[i] = l.next;
            e = e.next = new L(l.j);
            i = l.j;
        }
        e.next = f;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        aa = new L[n];
        int[] din = new int[n];
        int[] dout = new int[n];
        for (int h = 0; h < m; h++) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken()) - 1;
            int j = Integer.parseInt(st.nextToken()) - 1;
            L l = new L(j);
            l.next = aa[i]; aa[i] = l;
            dout[i]++;
            din[j]++;
        }
        if (dout[0] - din[0] != 1 || din[n - 1] - dout[n - 1] != 1) {
            System.out.println("IMPOSSIBLE");
            return;
        }
        for (int i = 1; i < n - 1; i++)
            if (dout[i] != din[i]) {
                System.out.println("IMPOSSIBLE");
                return;
            }
        L e_ = new L(0);
        m++;
        hierholzer(e_);
        for (L e = e_; e != null; e = e.next) {
            hierholzer(e);
            m--;
        }
        if (m != 0) {
            System.out.println("IMPOSSIBLE");
            return;
        }
        PrintWriter pw = new PrintWriter(System.out);
        for (L e = e_; e != null; e = e.next)
            pw.print(e.j + 1 + " ");
        pw.println();
        pw.close();
    }
}
