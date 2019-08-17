// https://cses.fi/problemset/task/1701
// Tree Isomorphism II
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1701 extends PrintWriter {
    CSES1701() { super(System.out); }
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
        CSES1701 o = new CSES1701(); o.main(); o.flush();
    }
    
    static final int MD = 1000000007, N = 100000;
    Random rand = new Random();
    ArrayList[] aa;
    int[] xx, yy, xx_, yy_, hh;
    {
        aa = new ArrayList[N];
        xx = new int[N];
        yy = new int[N];
        xx[0] = yy[0] = 1;
        for (int h = 1; h < N - 1; h++) {
            xx[h] = rand.nextInt(MD - 2) + 2;
            yy[h] = rand.nextInt(MD - 2) + 2;
        }
        xx_ = new int[N];
        yy_ = new int[N];
        hh = new int[N];
    }
    void dfs(int p, int i) {
        ArrayList<Integer> adj = aa[i];
        int h = -1;
        for (int j : adj)
            if (j != p) {
                dfs(i, j);
                h = Math.max(h, hh[j]);
            }
        hh[i] = ++h;
        int x = xx[h], y = yy[h], x_ = 1, y_ = 1;
        for (int j : adj)
            if (j != p) {
                x_ = (int) ((long) x_ * (x + xx_[j]) % MD);
                y_ = (int) ((long) y_ * (y + yy_[j]) % MD);
            }
        xx_[i] = x_; yy_[i] = y_;
    }
    void dfs2(int p, int i, int hp, int xp, int yp) {
        ArrayList<Integer> adj = aa[i];
        int c = 0;
        for (int j : adj)
            if (j != p)
                c++;
        int[] jj = new int[c];
        c = 0;
        int h1 = -1, h2 = -1, j1 = -1;
        for (int j : adj)
            if (j != p) {
                if (h1 < hh[j]) {
                    h2 = h1; h1 = hh[j];
                    j1 = j;
                } else if (h2 < hh[j])
                    h2 = hh[j];
                jj[c++] = j;
            }
        h1 = Math.max(h1, hp) + 1;
        h2 = Math.max(h2, hp) + 1;
        int[] px = new int[c];
        int[] py = new int[c];
        int x = xx[h1], y = yy[h1], x_, y_;
        x_ = y_ = 1;
        if (hp != -1) {
            x_ = (int) ((long) x_ * (x + xp) % MD);
            y_ = (int) ((long) y_ * (y + yp) % MD);
        }
        for (int a = 0; a < c; a++) {
            px[a] = x_;
            py[a] = y_;
            int j = jj[a];
            x_ = (int) ((long) x_ * (x + xx_[j]) % MD);
            y_ = (int) ((long) y_ * (y + yy_[j]) % MD);
        }
        int xi = x_, yi = y_;
        int[] qx = new int[c];
        int[] qy = new int[c];
        x_ = y_ = 1;
        for (int a = c - 1; a >= 0; a--) {
            qx[a] = x_;
            qy[a] = y_;
            int j = jj[a];
            x_ = (int) ((long) x_ * (x + xx_[j]) % MD);
            y_ = (int) ((long) y_ * (y + yy_[j]) % MD);
        }
        if (j1 != -1) {
            x = xx[h2]; y = yy[h2];
            x_ = y_ = 1;
            if (hp != -1) {
                x_ = (int) ((long) x_ * (x + xp) % MD);
                y_ = (int) ((long) y_ * (y + yp) % MD);
            }
            for (int a = 0; a < c; a++) {
                int j = jj[a];
                if (j != j1) {
                    x_ = (int) ((long) x_ * (x + xx_[j]) % MD);
                    y_ = (int) ((long) y_ * (y + yy_[j]) % MD);
                }
            }
            dfs2(i, j1, h2, x_, y_);
        }
        for (int a = 0; a < c; a++) {
            int j = jj[a];
            if (j != j1) {
                x_ = (int) ((long) px[a] * qx[a] % MD);
                y_ = (int) ((long) py[a] * qy[a] % MD);
                dfs2(i, j, h1, x_, y_);
            }
        }
        xx_[i] = xi; yy_[i] = yi;
    }
    void main() {
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            long z = 0;
            for (int k = 0; k < 2; k++) {
                for (int i = 0; i < n; i++)
                    aa[i] = new ArrayList<Integer>();
                for (int h = 0; h < n - 1; h++) {
                    int i = sc.nextInt() - 1;
                    int j = sc.nextInt() - 1;
                    aa[i].add(j);
                    aa[j].add(i);
                }
                dfs(-1, 0);
                if (k == 0) {
                    z = (long) xx_[0] * MD + yy_[0];
                    continue;
                }
                dfs2(-1, 0, -1, -1, -1);
            }
            boolean yes = false;
            for (int i = 0; i < n; i++)
                if (z == (long) xx_[i] * MD + yy_[i]) {
                    yes = true;
                    break;
                }
            println(yes ? "YES" : "NO");
        }
    }
}
