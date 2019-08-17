// https://cses.fi/problemset/task/1677
// Network Breakdown
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1677 extends PrintWriter {
    CSES1677() { super(System.out); }
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
        CSES1677 o = new CSES1677(); o.main(); o.flush();
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
    void main() {
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();
        int[] aa = new int[m + k];
        int[] bb = new int[m + k];
        Integer[] ii = new Integer[m + k];
        for (int h = 0; h < m + k; h++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            if (a > b) {
                int tmp = a; a = b; b = tmp;
            }
            aa[h] = a;
            bb[h] = b;
            ii[h] = h;
        }
        Arrays.sort(ii, (i, j) -> aa[i] != aa[j] ? aa[i] - aa[j] : bb[i] - bb[j]);
        boolean[] dup = new boolean[m + k];
        for (int h = 1; h < m + k; h++) {
            int i = ii[h - 1], j = ii[h];
            if (aa[i] == aa[j] && bb[i] == bb[j])
                dup[i] = dup[j] = true;
        }
        dsu = new int[n];
        Arrays.fill(dsu, -1);
        int c = n;
        for (int h = 0; h < m; h++)
            if (!dup[h])
                if (join(aa[h], bb[h]))
                    c--;
        int[] ans = new int[k];
        for (int h = k - 1; h >= 0; h--) {
            ans[h] = c;
            if (join(aa[m + h], bb[m + h]))
                c--;
        }
        for (int h = 0; h < k; h++)
            print(ans[h] + " ");
        println();
    }
}
