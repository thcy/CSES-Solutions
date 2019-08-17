// https://cses.fi/problemset/task/1747
// Pyramid Array
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1747 extends PrintWriter {
    CSES1747() { super(System.out); }
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
        CSES1747 c = new CSES1747(); c.main(); c.flush();
    }
    
    int[] tt;
    void update(int i, int n) {
        while (i < n) {
            tt[i]++;
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
    void main() {
        int n = sc.nextInt();
        int[] aa = new int[n];
        Integer[] ii = new Integer[n];
        for (int i = 0; i < n; i++) {
            aa[i] = sc.nextInt();
            ii[i] = i;
        }
        Arrays.sort(ii, (i, j) -> aa[i] - aa[j]);
        tt = new int[n];
        long ans = 0;
        for (int h = 0; h < n; h++) {
            int i = ii[h];
            int l = query(i);
            ans += Math.min(i - l, (n - 1 - i) - (h - l));
            update(i, n);
        }
        println(ans);
    }
}
