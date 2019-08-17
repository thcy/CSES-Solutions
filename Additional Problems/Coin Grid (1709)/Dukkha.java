// https://cses.fi/problemset/task/1709
// Coin Grid
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1709 extends PrintWriter {
    CSES1709() { super(System.out); }
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
        int m = 1 << 7; byte[] cc = new byte[m];
        int read() {
            byte c = 0; while (c <= 32) c = getc();
            int n = 0;
            while (c > 32) {
                if (n == m) cc = Arrays.copyOf(cc, m <<= 1);
                cc[n++] = c; c = getc();
            }
            return n;
        }
        byte[] nextBytes() { int n = read(); return Arrays.copyOf(cc, n); }
    }
    Scanner sc = new Scanner(System.in);
    public static void main(String[] $) {
        CSES1709 o = new CSES1709(); o.main(); o.flush();
    }
    
    ArrayList[] aa;
    int[] qq, dd, vv, uu;
    boolean bfs(int n) {
        int head = 0, cnt = 0;
        dd[0] = n;
        for (int u = 1; u <= n; u++)
            if (vv[u] == 0) {
                dd[u] = 0;
                qq[head + cnt++] = u;
            } else
                dd[u] = n;
        while (cnt > 0) {
            int u = qq[head++]; cnt--;
            int d = dd[u] + 1;
            ArrayList<Integer> adj = aa[u];
            for (int v : adj) {
                int w = uu[v];
                if (dd[w] == n) {
                    dd[w] = d;
                    if (w == 0)
                        return true;
                    qq[head + cnt++] = w;
                }
            }
        }
        return false;
    }
    boolean dfs(int u, int n) {
        if (u == 0)
            return true;
        int d = dd[u] + 1;
        ArrayList<Integer> adj = aa[u];
        for (int v : adj) {
            int w = uu[v];
            if (dd[w] == d && dfs(w, n)) {
                vv[u] = v; uu[v] = u;
                return true;
            }
        }
        dd[u] = n;
        return false;
    }
    int hopcroft_karp(int n, int n_) {
        qq = new int[n];
        dd = new int[n + 1];
        vv = new int[n + 1];
        uu = new int[n_ + 1];
        int m = 0;
        while (bfs(n))
            for (int u = 1; u <= n; u++)
                if (vv[u] == 0 && dfs(u, n))
                    m++;
        return m;
    }
    void main() {
        int n = sc.nextInt();
        int n_ = n;
        aa = new ArrayList[n + 1];
        for (int u = 1; u <= n; u++) {
            aa[u] = new ArrayList<Integer>();
            byte[] cc = sc.nextBytes();
            for (int v = 1; v <= n_; v++)
                if (cc[v - 1] == 'o')
                    aa[u].add(v);
        }
        println(hopcroft_karp(n, n_));
        for (int u = 1; u <= n; u++) {
            if (vv[u] == 0)
                continue;
            if (dd[u] == n)
                println("1 " + u);
            else
                println("2 " + vv[u]);
        }
    }
}
