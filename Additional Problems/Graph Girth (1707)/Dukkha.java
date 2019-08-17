// https://cses.fi/problemset/task/1707
// Graph Girth
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1707 extends PrintWriter {
    CSES1707() { super(System.out, true); }
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
    public static void main(String[] $) { new CSES1707().main(); }
    
    int[][] aa;
    int[] qq, dd;
    static final int INF = 2501;
    int bfs(int i) {
        Arrays.fill(dd, INF);
        int d_ = INF;
        int head = 0, cnt = 0;
        dd[i] = 0;
        qq[head + cnt++] = i;
        while (cnt > 0) {
            i = qq[head++]; cnt--;
            int d = dd[i];
            if (d > d_)
                return d_ * 2 + 2;
            for (int h = 0; h < aa[i].length; h++) {
                int j = aa[i][h];
                if (dd[j] < d)
                    continue;
                if (dd[j] == INF) {
                    dd[j] = d + 1;
                    qq[head + cnt++] = j;
                } else {
                    if (dd[j] == d)
                        return d * 2 + 1;
                    d_ = d;
                }
            }
        }
        return INF;
    }
    void main() {
        int n = sc.nextInt();
        int m = sc.nextInt();
        ArrayList[] aa_ = new ArrayList[n];
        for (int i = 0; i < n; i++)
            aa_[i] = new ArrayList<Integer>();
        while (m-- > 0) {
            int i = sc.nextInt() - 1;
            int j = sc.nextInt() - 1;
            if (i == j) {
                println(1);
                return;
            }
            aa_[i].add(j);
            aa_[j].add(i);
        }
        aa = new int[n][];
        for (int i = 0; i < n; i++) {
            ArrayList<Integer> adj = aa_[i];
            aa[i] = adj.stream().mapToInt($->$).toArray();
        }
        qq = new int[n];
        dd = new int[n];
        int ans = INF;
        for (int i = 0; i < n; i++)
            ans = Math.min(ans, bfs(i));
        println(ans == INF ? -1 : ans);
    }
}
