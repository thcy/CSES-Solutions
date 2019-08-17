// https://cses.fi/problemset/task/1628
// Meet in the Middle
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1628 extends PrintWriter {
    CSES1628() {
        super(System.out, true);
        try { _bb = System.in.readAllBytes(); } catch (IOException e) {}
    }
    byte[] _bb; int _i;
    int nextInt() {
        int n = _bb.length;
        while (_i < n && _bb[_i] < 33) _i++;
        int a = 0;
        while (_i < n && _bb[_i] > 32) a = a * 10 + _bb[_i++] - '0';
        return a;
    }
    public static void main(String[] __) { new CSES1628().main(); }
    
    long[] tt;
    long[] build(int[] aa, int l, int r) {
        long[] ss = new long[1 << r - l];
        for (int k = 1; l < r; l++, k <<= 1) {
            int a = aa[l];
            for (int h = 0; h < k; h++) {
                tt[h] = ss[h];
                tt[h + k] = ss[h] + a;
            }
            int p = 0, q = k, p_ = k, q_ = k + k, h = 0;
            while (p < p_ && q < q_)
                if (tt[p] < tt[q])
                    ss[h++] = tt[p++];
                else
                    ss[h++] = tt[q++];
            while (p < p_)
                ss[h++] = tt[p++];
            while (q < q_)
                ss[h++] = tt[q++];
        }
        return ss;
    }
    void main() {
        int n = nextInt();
        int x = nextInt();
        int[] aa = new int[n];
        for (int i = 0; i < n; i++)
            aa[i] = nextInt();
        int k0 = n / 2, k1 = n - k0, n0 = 1 << k0, n1 = 1 << k1;
        tt = new long[1 << k1];
        long[] a0 = build(aa, 0, k0);
        long[] a1 = build(aa, k0, n);
        long ans = 0;
        for (int i = 0, p = n1 - 1, q = p; i < n0; i++) {
            long y = 0;
            while (q >= 0 && (y = a0[i] + a1[q]) > x)
                q--;
            if (q < 0)
                break;
            if (y == x) {
                if (p > q)
                    p = q;
                while (p > 0 && a1[p - 1] == a1[q])
                    p--;
                ans += q - p + 1;
            }
        }
        println(ans);
    }
}
