// https://cses.fi/problemset/task/1698
// Swap Round Sorting
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1698 extends PrintWriter {
    CSES1698() { super(System.out); }
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
        CSES1698 o = new CSES1698(); o.main(); o.flush();
    }
    
    void main() {
        int n = sc.nextInt();
        int[] aa = new int[n];
        for (int i = 0; i < n; i++)
            aa[i] = sc.nextInt() - 1;
        int[] s1 = new int[n];
        int[] s2 = new int[n];
        int[] qq = new int[n];
        int k1 = 0, k2 = 0;
        for (int i = 0; i < n; i++) {
            if (aa[i] < 0 || aa[i] == i)
                continue;
            int cnt = 0;
            for (int j = i; aa[j] >= 0; aa[j] = -aa[j], j = -aa[j])
                qq[cnt++] = j;
            for (int u = 0, v = cnt - 2; u < v; u++, v--) {
                s1[k1++] = qq[u];
                s1[k1++] = qq[v];
            }
            for (int u = 0, v = cnt - 1; u < v; u++, v--) {
                s2[k2++] = qq[u];
                s2[k2++] = qq[v];
            }
        }
        println(k2 == 0 ? 0 : k1 == 0 ? 1 : 2);
        if (k1 != 0) {
            println(k1 / 2);
            while (k1 > 0) {
                println((s1[k1 - 1] + 1) + " " + (s1[k1 - 2] + 1));
                k1 -= 2;
            }
        }
        if (k2 != 0) {
            println(k2 / 2);
            while (k2 > 0) {
                println((s2[k2 - 1] + 1) + " " + (s2[k2 - 2] + 1));
                k2 -= 2;
            }
        }
    }
}
