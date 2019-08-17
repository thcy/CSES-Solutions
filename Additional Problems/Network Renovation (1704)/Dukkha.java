// https://cses.fi/problemset/task/1704
// Network Renovation
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1704 extends PrintWriter {
    CSES1704() { super(System.out); }
    static class Scanner {
        Scanner(InputStream in) { this.in = in; } InputStream in;
        int k, l; byte[] bb = new byte[1 << 15];
        byte getc() {
            if (k >= l) {
                k = 0;
                try { l = in.read(bb); } catch (IOException e) { l = 0; }
                if (l <= 0) return -1;
            }
            return bb[k++];
        }
        int nextInt() {
            byte c = 0; while (c <= 32) c = getc();
            int a = 0;
            while (c > 32) { a = a * 10 + c - '0'; c = getc(); }
            return a;
        }
    }
    Scanner sc = new Scanner(System.in);
    public static void main(String[] $) {
        CSES1704 c = new CSES1704(); c.main(); c.flush();
    }
    
    ArrayList[] aa;
    int[] uu, vv, ii;
    void dfs(int p, int i) {
        ArrayList<Integer> adj = aa[i];
        for (int j : adj)
            if (j != p)
                dfs(i, j);
        int m = 0;
        for (int j : adj)
            if (j != p) {
                if (uu[j] > 0)
                    m++;
                if (vv[j] > 0)
                    m++;
            }
        if (m == 0) {
            uu[i] = i;
            return;
        }
        int x = 0, y = m - 1;
        for (int j : adj)
            if (j != p) {
                if (vv[j] > 0) {
                    ii[x++] = uu[j];
                    ii[x++] = vv[j];
                } else
                    ii[y--] = uu[j];
            }
        uu[i] = ii[0];
        if (m % 2 == 0)
            vv[i] = ii[m - 1];
        for (int z = 0; z < (m - 1) / 2; z++) {
            x = z * 2 + 1;
            y = z * 2 + 2;
            println(ii[x] + " " + ii[y]);
        }
    }
    void main() {
        int n = sc.nextInt();
        aa = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++)
            aa[i] = new ArrayList<Integer>();
        for (int h = 0; h < n - 1; h++) {
            int i = sc.nextInt();
            int j = sc.nextInt();
            aa[i].add(j);
            aa[j].add(i);
        }
        uu = new int[n + 1];
        vv = new int[n + 1];
        ii = new int[n];
        int m = 0, r = 0;
        for (int i = 1; i <= n; i++)
            if (aa[i].size() == 1)
                m++;
            else
                r = i;
        println((m + 1) / 2);
        dfs(-1, r);
        println(uu[r] + " " + (vv[r] > 0 ? vv[r] : r));
    }
}
