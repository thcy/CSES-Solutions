// https://cses.fi/problemset/task/1677
// Network Breakdown
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1677 extends PrintWriter {
    CSES1677() { super(System.out); }
    byte[] __; int $;
    { try { __ = System.in.readAllBytes(); } catch (IOException e) {} }
    int nextInt() {
        while ($ < __.length && __[$] <= 32) $++;
        int a = 0;
        while ($ < __.length && __[$] > 32) a = a * 10 + __[$++] - '0';
        return a;
    }
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
        int n = nextInt();
        int m = nextInt();
        int k = nextInt();
        int[] aa = new int[m + k];
        int[] bb = new int[m + k];
        Integer[] ii = new Integer[m + k];
        for (int h = 0; h < m + k; h++) {
            int a = nextInt() - 1;
            int b = nextInt() - 1;
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
