// https://cses.fi/problemset/task/1748
// Increasing Subsequence II
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1748 extends PrintWriter {
    CSES1748() { super(System.out); }
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
        CSES1748 c = new CSES1748(); c.main(); c.flush();
    }
    
    static final int MD = 1000000007;
    int[] tt;
    void update(int i, int n, int x) {
        while (i < n) {
            tt[i] = (tt[i] + x) % MD;
            i |= i + 1;
        }
    }
    int query(int i) {
        int x = 0;
        while (i >= 0) {
            x = (x + tt[i]) % MD;
            i &= i + 1;
            i--;
        }
        return x;
    }
    void main() {
        int n = sc.nextInt();
        int[] aa = new int[n];
        Integer[] ii = new Integer[n];
        for (int i = 0; i < n; i++) {
            aa[i] = sc.nextInt();
            ii[i] = i;
        }
        Arrays.sort(ii, (i, j) -> aa[i] != aa[j] ? aa[i] - aa[j] : j - i);
        tt = new int[n];
        for (int h = 0; h < n; h++) {
            int i = ii[h];
            update(i, n, query(i) + 1);
        }
        println(query(n - 1));
    }
}
