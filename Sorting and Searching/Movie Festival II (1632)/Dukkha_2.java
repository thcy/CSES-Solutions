// https://cses.fi/problemset/task/1632
// Movie Festival II
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1632 {
    static Random rand = new Random();
    static class V {
        V l, r;
        int key, cnt, x;
        V(int key) {
            this.key = key;
            x = rand.nextInt();
        }
    }
    static V v_, l_, r_;
    static void split(V v, int key) {
        if (v == null) {
            v_ = l_ = r_ = null;
        } else if (v.key < key) {
            split(v.r, key);
            v.r = l_; l_ = v;
        } else if (v.key > key) {
            split(v.l, key);
            v.l = r_; r_ = v;
        } else {
            v_ = v;
            l_ = v.l;
            r_ = v.r;
            v.l = v.r = null;
        }
    }
    static V merge(V l, V r) {
        if (l == null)
            return r;
        if (r == null)
            return l;
        if (l.x <= r.x) {
            l.r = merge(l.r, r);
            return l;
        } else {
            r.l = merge(l, r.l);
            return r;
        }
    }
    static V last(V v) {
        if (v != null)
            while (v.r != null)
                v = v.r;
        return v;
    }
    static void tr_add(int key) {
        split(v_, key);
        if (v_ == null)
            v_ = new V(key);
        v_.cnt++;
        v_ = merge(merge(l_, v_), r_);
    }
    static void tr_remove(int key) {
        split(v_, key);
        if (--v_.cnt == 0)
            v_ = null;
        v_ = merge(merge(l_, v_), r_);
    }
    static V tr_floor(int key) {
        split(v_, key);
        V v = v_ != null ? v_ : last(l_);
        v_ = merge(merge(l_, v_), r_);
        return v;
    }
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] aa = new int[n];
        int[] bb = new int[n];
        Integer[] ii = new Integer[n];
        for (int i = 0; i < n; i++) {
            aa[i] = sc.nextInt();
            bb[i] = sc.nextInt();
            ii[i] = i;
        }
        while (k-- > 0)
            tr_add(0);
        Arrays.sort(ii, (i, j) -> bb[i] - bb[j]);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            V v = tr_floor(aa[ii[i]]);
            if (v != null) {
                tr_remove(v.key);
                tr_add(bb[ii[i]]);
                cnt++;
            }
        }
        System.out.println(cnt);
    }
    static class _Scanner {
        InputStream is;
        _Scanner(InputStream is) {
            this.is = is;
        }
        byte[] bb = new byte[1 << 15];
        int k, l;
        byte getc() throws IOException {
            if (k >= l) {
                k = 0;
                l = is.read(bb);
                if (l < 0) return -1;
            }
            return bb[k++];
        }
        byte skip() throws IOException {
            byte b;
            while ((b = getc()) <= 32)
                ;
            return b;
        }
        int nextInt() throws IOException {
            int n = 0;
            for (byte b = skip(); b > 32; b = getc())
                n = n * 10 + b - '0';
            return n;
        }
    }
}
