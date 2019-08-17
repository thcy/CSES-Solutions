// https://cses.fi/problemset/task/1703
// Critical Cities
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1703 extends PrintWriter {
    CSES1703() { super(System.out); }
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
        CSES1703 o = new CSES1703(); o.main(); o.flush();
    }
    
    ArrayList[] aa;
    int[] stack, dd;
    int cnt, n, d_;
    boolean dfs(int i, int d) {
        if (dd[i] < n)
            return false;
        dd[i] = d;
        if (i == n - 1) {
            stack[cnt++] = i;
            return true;
        }
        ArrayList<Integer> adj = aa[i];
        for (int j : adj)
            if (dfs(j, d + 1)) {
                stack[cnt++] = i;
                return true;
            }
        return false;
    }
    void dfs2(int i) {
        if (dd[i] < n) {
            if (d_ < dd[i])
                d_ = dd[i];
            return;
        }
        dd[i] = -1;
        ArrayList<Integer> adj = aa[i];
        for (int j : adj)
            dfs2(j);
    }
    void main() {
        n = sc.nextInt();
        int m = sc.nextInt();
        aa = new ArrayList[n];
        for (int i = 0; i < n; i++)
            aa[i] = new ArrayList<Integer>();
        while (m-- > 0) {
            int i = sc.nextInt() - 1;
            int j = sc.nextInt() - 1;
            aa[i].add(j);
        }
        dd = new int[n];
        Arrays.fill(dd, n);
        stack = new int[n];
        dfs(0, 0);
        Arrays.fill(dd, n);
        for (int h = 0; h < cnt; h++) {
            int i = stack[h];
            dd[i] = cnt - 1 - h;
        }
        ArrayList<Integer> cc = new ArrayList<>();
        for (int h = cnt - 1; h >= 0; h--) {
            int i = stack[h];
            if (dd[i] == d_)
                cc.add(i);
            dd[i] = n;
            dfs2(i);
        }
        println(cc.size());
        Collections.sort(cc);
        for (int i : cc)
            print(i + 1 + " ");
        println();
    }
}
