// https://cses.fi/problemset/task/1705
// Forbidden Cities
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1705 extends PrintWriter {
    CSES1705() { super(System.out); }
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
        CSES1705 o = new CSES1705(); o.main(); o.flush();
    }
    
    int[] dsu;
    int find(int i) {
        return dsu[i] < 0 ? i : (dsu[i] = find(dsu[i]));
    }
    boolean join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j)
            return false;
        if (dsu[i] > dsu[j])
            dsu[i] = j;
        else {
            if (dsu[i] == dsu[j])
                dsu[i]--;
            dsu[j] = i;
        }
        return true;
    }
    int[] ta, tb, tc;
    int time;
    ArrayList[] aa;
    int[] ii, jj, hh;
    boolean[] cut;
    void dfs1(int h_, int i) {
        hh[i] = h_;
        ArrayList<Integer> adj = aa[i];
        ta[i] = tb[i] = ++time;
        int c = 0;
        for (int h : adj)
            if (h != h_) {
                int j = i ^ ii[h] ^ jj[h];
                if (ta[j] == 0) {
                    c++;
                    dfs1(h, j);
                    tb[i] = Math.min(tb[i], tb[j]);
                    if (h_ != -1 && ta[i] <= tb[j])
                        cut[i] = true;
                } else if (ta[j] < ta[i])
                    tb[i] = Math.min(tb[i], ta[j]);
            }
        if (h_ == -1 && c > 1)
            cut[i] = true;
    }
    void dfs2(int h_, int i) {
        ArrayList<Integer> adj = aa[i];
        for (int h : adj)
            if (h != h_) {
                int j = i ^ ii[h] ^ jj[h];
                if (hh[j] != h && ta[j] > ta[i])
                    while (j != i) {
                        if (!join(h, hh[j]))
                            break;
                        h = hh[j];
                        j ^= ii[h] ^ jj[h];
                    }
            }
        for (int h : adj)
            if (h != h_) {
                int j = i ^ ii[h] ^ jj[h];
                if (hh[j] == h)
                    dfs2(h, j);
            }
    }
    static final int INF = 0x3f3f3f3f;
    int[] tr;
    int n_, i_;
    void update(int k, int x) {
        for (k += n_; k >= 1; k >>= 1)
            tr[k] = Math.min(tr[k], x);
    }
    int query(int l, int r) {
        int x = INF;
        for (l += n_, r += n_; l <= r; l >>= 1, r >>= 1) {
            if ((l & 1) == 1)
                x = Math.min(x, tr[l++]);
            if ((r & 1) == 0)
                x = Math.min(x, tr[r--]);
        }
        return x;
    }
    ArrayList[] aa_;
    int[] ll, rr;
    void dfs_(int i) {
        ArrayList<Integer> adj = aa_[i];
        tc[i] = ++time;
        ll[i] = i_;
        update(i_++, tc[i]);
        for (int j : adj)
            if (tc[j] == 0) {
                dfs_(j);
                update(i_++, tc[i]);
            }
        rr[i] = i_;
    }
    boolean ancestor(int i, int a) {
        return ll[a] <= ll[i] && rr[i] <= rr[a];
    }
    boolean block(int i, int j, int k) {
        if (ll[i] > ll[j])
            return block(j, i, k);
        boolean aik = ancestor(i, k);
        boolean ajk = ancestor(j, k);
        return aik != ajk || aik && ajk && query(ll[i], ll[j]) == tc[k];
    }
    void main() {
        int n = sc.nextInt();
        int m = sc.nextInt();
        int q = sc.nextInt();
        aa = new ArrayList[n];
        for (int i = 0; i < n; i++)
            aa[i] = new ArrayList<Integer>();
        ii = new int[m];
        jj = new int[m];
        for (int h = 0; h < m; h++) {
            int i = sc.nextInt() - 1;
            int j = sc.nextInt() - 1;
            ii[h] = i;
            jj[h] = j;
            aa[i].add(h);
            aa[j].add(h);
        }
        ta = new int[n];
        tb = new int[n];
        hh = new int[n];
        cut = new boolean[n];
        dfs1(-1, 0);
        dsu = new int[m + n];
        Arrays.fill(dsu, -1);
        dfs2(-1, 0);
        for (int h = 0; h < m; h++) {
            int i = ii[h], j = jj[h];
            if (!cut[i])
                join(h, m + i);
            if (!cut[j])
                join(h, m + j);
        }
        aa_ = new ArrayList[m + n];
        for (int h = 0; h < m + n; h++)
            aa_[h] = new ArrayList<Integer>();
        for (int i = 0; i < n; i++)
            if (cut[i]) {
                ArrayList<Integer> adj = aa[i];
                for (int h : adj) {
                    h = find(h);
                    aa_[m + i].add(h);
                    aa_[h].add(m + i);
                }
            }
        int h_ = 0;
        n_ = 0;
        for (int h = 0; h < m + n; h++)
            if (aa_[h].size() != 0) {
                n_++;
                h_ = h;
            }
        n_ *= 2;
        tr = new int[n_ * 2 + 1];
        Arrays.fill(tr, INF);
        ll = new int[m + n];
        rr = new int[m + n];
        tc = new int[m + n];
        time = 0;
        dfs_(h_);
        while (q-- > 0) {
            int i = sc.nextInt() - 1;
            int j = sc.nextInt() - 1;
            int k = sc.nextInt() - 1;
            boolean yes;
            if (i == k || j == k)
                yes = false;
            else if (!cut[k])
                yes = true;
            else
                yes = !block(find(m + i), find(m + j), find(m + k));
            println(yes ? "YES" : "NO");
        }
    }
}
