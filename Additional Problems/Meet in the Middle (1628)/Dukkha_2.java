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
        boolean minus = _bb[_i] == '-'; if (minus) _i++;
        int a = 0;
        while (_i < n && _bb[_i] > 32) a = a * 10 + _bb[_i++] - '0';
        return minus ? -a : a;
    }
    public static void main(String[] __) { new CSES1628().main(); }
    
    Random rand = new Random();
    void shuffle(long[] aa, int n) {
        for (int j = 0; j < n; j++) {
            int i = rand.nextInt(j + 1);
            long tmp = aa[i]; aa[i] = aa[j]; aa[j] = tmp;
        }
    }
    void main() {
        int n = nextInt();
        int x = nextInt();
        int[] aa = new int[n];
        for (int i = 0; i < n; i++)
            aa[i] = nextInt();
        int k0 = n / 2, k1 = n - k0;
        int n0 = 1 << k0, n1 = 1 << k1;
        long[] a0 = new long[n0];
        long[] a1 = new long[n1];
        for (int i = 0; i < k0; i++)
            a0[1 << i] = aa[i];
        for (int b = 1; b < n0; b++) {
            int b_ = b & b - 1;
            a0[b] = a0[b_] + a0[b ^ b_];
        }
        for (int i = 0; i < k1; i++)
            a1[1 << i] = aa[k0 + i];
        for (int b = 1; b < n1; b++) {
            int b_ = b & b - 1;
            a1[b] = a1[b_] + a1[b ^ b_];
        }
        shuffle(a0, n0);
        Arrays.sort(a0);
        shuffle(a1, n1);
        Arrays.sort(a1);
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
