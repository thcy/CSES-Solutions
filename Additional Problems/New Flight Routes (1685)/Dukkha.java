// https://cses.fi/problemset/task/1685
// New Flight Routes
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1685 extends PrintWriter {
    CSES1685() { super(System.out); }
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
        CSES1685 o = new CSES1685(); o.main(); o.flush();
    }
    
    ArrayList[] aa, bb;
    boolean[] visited;
    int[] po;
    int npo;
    void dfs1(int i) {
        if (visited[i])
            return;
        visited[i] = true;
        ArrayList<Integer> adj = aa[i];
        for (int j : adj)
            dfs1(j);
        po[npo++] = i;
    }
    ArrayList[] aa_;
    int[] dd;
    int[] cc;
    void dfs2(int j, int c) {
        int c_ = cc[j];
        if (c_ != -1) {
            if (c_ != c) {
                aa_[c_].add(c);
                dd[c]++;
            }
            return;
        }
        cc[j] = c;
        ArrayList<Integer> adj = bb[j];
        for (int i : adj)
            dfs2(i, c);
    }
    int dfs3(int i) {
        if (visited[i])
            return -1;
        visited[i] = true;
        ArrayList<Integer> adj = aa_[i];
        if (adj.size() == 0)
            return i;
        for (int j : adj) {
            int w = dfs3(j);
            if (w != -1)
                return w;
        }
        return -1;
    }
    void add(int i, int j) {
        println((i + 1) + " " + (j + 1));
    }
    void augment(int n) {
        int[] vv = new int[n];
        int[] ww = new int[n];
        boolean[] iv = new boolean[n];
        boolean[] iw = new boolean[n];
        int p = 0, q, s, t;
        for (int i = 0; i < n; i++) {
            if (cc[i] != i)
                continue;
            if (dd[i] == 0) {
                int w = dfs3(i);
                if (w != -1) {
                    iv[vv[p] = i] = true;
                    iw[ww[p] = w] = true;
                    p++;
                }
            }
        }
        s = t = p;
        for (int i = 0; i < n; i++) {
            if (cc[i] != i)
                continue;
            if (!iv[i] && dd[i] == 0)
                vv[s++] = i;
            if (!iw[i] && aa_[i].size() == 0)
                ww[t++] = i;
        }
        println(Math.max(s, t));
        for (int h = 0; h < p - 1; h++)
            add(ww[h], vv[h + 1]);
        q = Math.min(s, t);
        for (int h = p; h < q; h++)
            add(ww[h], vv[h]);
        int x = ww[p - 1];
        for (int h = q; h < s; h++) {
            add(x, vv[h]); x = vv[h];
        }
        for (int h = q; h < t; h++) {
            add(x, ww[h]); x = ww[h];
        }
        add(x, vv[0]);
    }
    void main() {
        int n = sc.nextInt();
        int m = sc.nextInt();
        aa = new ArrayList[n];
        bb = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            aa[i] = new ArrayList<Integer>();
            bb[i] = new ArrayList<Integer>();
        }
        while (m-- > 0) {
            int i = sc.nextInt() - 1;
            int j = sc.nextInt() - 1;
            aa[i].add(j);
            bb[j].add(i);
        }
        visited = new boolean[n];
        po = new int[n];
        for (int i = 0; i < n; i++)
            dfs1(i);
        aa_ = new ArrayList[n];
        for (int i = 0; i < n; i++)
            aa_[i] = new ArrayList<Integer>();
        dd = new int[n];
        cc = new int[n];
        Arrays.fill(cc, -1);
        int k = 0;
        for (int h = n - 1; h >= 0; h--) {
            int j = po[h];
            if (cc[j] == -1) {
                dfs2(j, j);
                k++;
            }
        }
        if (k == 1) {
            println(0);
            return;
        }
        Arrays.fill(visited, false);
        augment(n);
    }
}
