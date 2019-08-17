// https://cses.fi/problemset/task/1704
// Network Renovation
// upsolve with rainboy
// https://cses.fi/problemset/hack/1704/entry/169196/ (Noam527)
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
    int[] ii;
    int n;
    void dfs(int p, int i) {
        ArrayList<Integer> adj = aa[i];
        if (adj.size() == 1)
            ii[n++] = i;
        else
            for (int j : adj)
                if (j != p)
                    dfs(i, j);
    }
    void main() {
        n = sc.nextInt();
        aa = new ArrayList[n];
        for (int i = 0; i < n; i++)
            aa[i] = new ArrayList<Integer>();
        for (int h = 0; h < n - 1; h++) {
            int i = sc.nextInt() - 1;
            int j = sc.nextInt() - 1;
            aa[i].add(j);
            aa[j].add(i);
        }
        int r = 0;
        while (aa[r].size() == 1)
            r++;
        ii = new int[n];
        n = 0;
        dfs(-1, r);
        int m = (n + 1) / 2, c = m - 1;
        println(m);
        for (int h = 0; h < c; h++)
            println(ii[h] + 1 + " " + (ii[c * 2 - h] + 1));
        println(ii[c] + 1 + " " + (ii[n - 1] + 1));
    }
}
