// https://cses.fi/problemset/task/1699
// Flight Route Requests
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1699 extends PrintWriter {
    CSES1699() { super(System.out); }
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
        CSES1699 o = new CSES1699(); o.main(); o.flush();
    }
    
    ArrayList[] aa, bb;
    int[] dd;
    boolean[] visited;
    int[] ii;
    int n_;
    void dfs(int i) {
        if (visited[i])
            return;
        visited[i] = true;
        ii[n_++] = i;
        ArrayList<Integer> adj;
        adj = aa[i];
        for (int j : adj)
            dfs(j);
        adj = bb[i];
        for (int j : adj)
            dfs(j);
    }
    int[] qq;
    boolean acyclic() {
        int head = 0, cnt = 0;
        for (int h = 0; h < n_; h++) {
            int i = ii[h];
            if (dd[i] == 0)
                qq[head + cnt++] = i;
        }
        while (cnt > 0) {
            int i = qq[head++]; cnt--;
            ArrayList<Integer> adj = aa[i];
            for (int j : adj)
                if (--dd[j] == 0)
                    qq[head + cnt++] = j;
        }
        return head == n_;
    }
    void main() {
        int n = sc.nextInt();
        int m = sc.nextInt();
        aa = new ArrayList[n];
        bb = new ArrayList[n];
        dd = new int[n];
        for (int i = 0; i < n; i++) {
            aa[i] = new ArrayList<Integer>();
            bb[i] = new ArrayList<Integer>();
        }
        for (int h = 0; h < m; h++) {
            int i = sc.nextInt() - 1;
            int j = sc.nextInt() - 1;
            if (i == j)
                continue;
            aa[i].add(j);
            bb[j].add(i);
            dd[j]++;
        }
        visited = new boolean[n];
        ii = new int[n];
        qq = new int[n];
        int ans = n;
        for (int i = 0; i < n; i++)
            if (!visited[i]) {
                n_ = 0;
                dfs(i);
                if (acyclic())
                    ans--;
            }
        println(ans);
    }
}
