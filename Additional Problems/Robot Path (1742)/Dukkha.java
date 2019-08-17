// https://cses.fi/problemset/task/1742
// Robot Path
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1742 extends PrintWriter {
    CSES1742() { super(System.out); }
    byte[] __; int $;
    { try { __ = System.in.readAllBytes(); } catch (IOException e) {} }
    int nextInt() {
        while ($ < __.length && __[$] <= 32) $++;
        int a = 0;
        while ($ < __.length && __[$] > 32) a = a * 10 + __[$++] - '0';
        return a;
    }
    byte nextByte() {
        while ($ < __.length && __[$] <= 32) $++;
        return __[$++];
    }
    public static void main(String[] $) {
        CSES1742 o = new CSES1742(); o.main(); o.flush();
    }
    
    static final int INF = 0x3f3f3f3f;
    int[] tt;
    int nt;
    void update(int i, int x) {
        while (i < nt) {
            tt[i] += x;
            i |= i + 1;
        }
    }
    int query(int i) {
        int x = 0;
        while (i >= 0) {
            x += tt[i];
            i &= i + 1;
            i--;
        }
        return x;
    }
    static class V {
        int y, l, r;
        V(int y, int l, int r) {
            this.y = y; this.l = l; this.r = r;
        }
    }
    V[] vv;
    int[] xl, xr, yd, yu;
    boolean check(int n) {
        int bound = n - 1;
        int n_ = 0;
        for (int i = 0; i < n; i++)
            if (xl[i] != xr[i])
                vv[n_++] = new V(yd[i], xl[i], xr[i]);
            else {
                vv[n_++] = new V(yd[i], xl[i], -INF);
                vv[n_++] = new V(yu[i], xl[i], INF);
            }
        n = n_;
        Arrays.sort(vv, 0, n, (u, v) -> u.y != v.y ? u.y - v.y : u.r - v.r);
        Arrays.fill(tt, 0);
        int r = -INF;
        for (int i = 0; i < n; i++) {
            V v = vv[i];
            if (i > 0 && vv[i - 1].y != vv[i].y)
                r = -INF;
            if (v.r == -INF) {
                if (query(v.l) - query(v.l - 1) != 0)
                    return false;
                update(v.l, 1);
            } else if (v.r == INF) {
                update(v.l, -1);
            } else {
                if (r >= v.l)
                    return false;
                bound -= query(v.r) - query(v.l - 1);
                if (bound < 0)
                    return false;
                r = v.r;
            }
        }
        return true;
    }
    boolean opposite(byte a, byte b) {
        return a == 'L' && b == 'R' || a == 'R' && b == 'L' || a == 'D' && b == 'U' || a == 'U' && b == 'D';
    }
    void main() {
        int n = nextInt();
        long[] xx_ = new long[n + 1];
        long[] yy_ = new long[n + 1];
        long x_, y_;
        xx_[0] = x_ = 0;
        yy_[0] = y_ = 0;
        byte dir_ = ' ';
        int n_ = 1;
        for (int i = 0; i < n; i++) {
            byte dir = nextByte();
            if (opposite(dir, dir_))
                break;
            int z = nextInt();
            if (dir == 'L')
                x_ -= z;
            else if (dir == 'R')
                x_ += z;
            else if (dir == 'D')
                y_ -= z;
            else
                y_ += z;
            if (dir_ != dir) {
                dir_ = dir;
                n_++;
            }
            xx_[n_ - 1] = x_;
            yy_[n_ - 1] = y_;
        }
        n = n_ - 1;
        
        int[] xx = new int[n + 1];
        int[] yy = new int[n + 1];
        Integer[] ii = new Integer[n + 1];
        for (int i = 0; i <= n; i++)
            ii[i] = i;
        Arrays.sort(ii, (i, j) -> Long.signum(xx_[i] - xx_[j]));
        for (int h = 0, x = 0; h <= n; h++)
            xx[ii[h]] = h == n || xx_[ii[h]] != xx_[ii[h + 1]] ? x++ : x;
        Arrays.sort(ii, (i, j) -> Long.signum(yy_[i] - yy_[j]));
        for (int h = 0, y = 0; h <= n; h++)
            yy[ii[h]] = h == n || yy_[ii[h]] != yy_[ii[h + 1]] ? y++ : y;
        
        xl = new int[n];
        xr = new int[n];
        yd = new int[n];
        yu = new int[n];
        for (int i = 0; i < n; i++) {
            xl[i] = xx[i]; xr[i] = xx[i + 1];
            if (xl[i] > xr[i]) { int tmp = xl[i]; xl[i] = xr[i]; xr[i] = tmp; }
            yd[i] = yy[i]; yu[i] = yy[i + 1];
            if (yd[i] > yu[i]) { int tmp = yd[i]; yd[i] = yu[i]; yu[i] = tmp; }
        }
        
        tt = new int[nt = n + 1];
        vv = new V[n * 2];
        int lower = 0, upper = n;
        while (upper - lower > 1) {
            n_ = (lower + upper) / 2;
            if (!check(n_))
                upper = n_;
            else
                lower = n_;
        }
        int j = upper - 1;
        
        x_ = xx_[j];
        y_ = yy_[j];
        long[] xl_ = new long[n];
        long[] xr_ = new long[n];
        long[] yd_ = new long[n];
        long[] yu_ = new long[n];
        for (int i = 0; i < n; i++) {
            xl_[i] = xx_[i]; xr_[i] = xx_[i + 1];
            if (xl_[i] > xr_[i]) { long tmp = xl_[i]; xl_[i] = xr_[i]; xr_[i] = tmp; }
            yd_[i] = yy_[i]; yu_[i] = yy_[i + 1];
            if (yd_[i] > yu_[i]) { long tmp = yd_[i]; yd_[i] = yu_[i]; yu_[i] = tmp; }
        }
        long w = 0, wj = xr_[j] - xl_[j] + yu_[j] - yd_[j];
        for (int i = 0; i < j; i++) {
            w += xr_[i] - xl_[i] + yu_[i] - yd_[i];
            if (i < j - 1) {
                long l = Math.max(xl_[i], xl_[j]);
                long r = Math.min(xr_[i], xr_[j]);
                if (l > r)
                    continue;
                long d = Math.max(yd_[i], yd_[j]);
                long u = Math.min(yu_[i], yu_[j]);
                if (d > u)
                    continue;
                wj = Math.min(wj, Math.abs(l - x_) + Math.abs(d - y_));
                wj = Math.min(wj, Math.abs(r - x_) + Math.abs(u - y_));
            }
        }
        w += wj;
        println(w);
    }
}
