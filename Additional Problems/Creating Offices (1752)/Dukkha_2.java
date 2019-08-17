// https://cses.fi/problemset/task/1752
// Creating Offices
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1752 extends PrintWriter {
    CSES1752() { super(System.out); }
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
        CSES1752 o = new CSES1752(); o.main(); o.flush();
    }
    
    static final int INF = 0x3f3f3f3f;
    ArrayList[] aa;
    boolean[] used;
    int[] cc, dd, dd_;
    int lambda;
    void dfs(int p, int i, int d) {
        dd[i] = d;
        ArrayList<Integer> adj = aa[i];
        int d_ = INF, c_ = -1;
        for (int j : adj)
            if (j != p) {
                dfs(i, j, d + 1);
                d_ = Math.min(d_, dd_[j]);
                int c = cc[j];
                if (c == -1)
                    continue;
                if ((dd[c] - d) * 2 >= lambda) {
                    used[c] = true;
                    d_ = Math.min(d_, dd[c]);
                } else if (c_ == -1 || dd[c_] < dd[c])
                    c_ = c;
            }
        dd_[i] = d_;
        if (c_ != -1 && dd[c_] - d + d_ - d < lambda)
            c_ = -1;
        if (c_ == -1 && d_ - d >= lambda)
            c_ = i;
        cc[i] = c_;
    }
    void main() {
        int n = sc.nextInt();
        lambda = sc.nextInt();
        aa = new ArrayList[n];
        for (int i = 0; i < n; i++)
            aa[i] = new ArrayList<Integer>();
        for (int h = 0; h < n - 1; h++) {
            int i = sc.nextInt() - 1;
            int j = sc.nextInt() - 1;
            aa[i].add(j);
            aa[j].add(i);
        }
        cc = new int[n];
        dd = new int[n];
        dd_ = new int[n];
        used = new boolean[n];
        dfs(-1, 0, 0);
        if (cc[0] != -1)
            used[cc[0]] = true;
        int k = 0;
        for (int i = 0; i < n; i++)
            if (used[i])
                k++;
        println(k);
        for (int i = 0; i < n; i++)
            if (used[i])
                print(i + 1 + " ");
        println();
    }
}
