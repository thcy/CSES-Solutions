// https://cses.fi/problemset/task/1700
// Tree Isomorphism I
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1700 extends PrintWriter {
    CSES1700() { super(System.out); }
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
        CSES1700 o = new CSES1700(); o.main(); o.flush();
    }
    
    static final int MD = 1000000007;
    Random rand = new Random();
    ArrayList[] aa;
    int[] xx, yy, xx_, yy_;
    int dfs(int p, int i) {
        ArrayList<Integer> adj = aa[i];
        int h_ = -1;
        for (int j : adj)
            if (j != p) {
                int h = dfs(i, j);
                if (h_ < h)
                    h_ = h;
            }
        h_++;
        int x = xx[h_], x_ = 1;
        int y = yy[h_], y_ = 1;
        for (int j : adj)
            if (j != p) {
                x_ = (int) ((long) x_ * (x + xx_[j]) % MD);
                y_ = (int) ((long) y_ * (y + yy_[j]) % MD);
            }
        xx_[i] = x_;
        yy_[i] = y_;
        return h_;
    }
    void main() {
        long[] hh = new long[2];
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            aa = new ArrayList[n];
            xx = new int[n];
            yy = new int[n];
            xx[0] = yy[0] = 1;
            for (int h = 1; h < n; h++) {
                xx[h] = rand.nextInt(MD - 2) + 2;
                yy[h] = rand.nextInt(MD - 2) + 2;
            }
            xx_ = new int[n];
            yy_ = new int[n];
            for (int k = 0; k < 2; k++) {
                for (int i = 0; i < n; i++)
                    aa[i] = new ArrayList<Integer>();
                for (int h = 0; h < n - 1; h++) {
                    int i = sc.nextInt() - 1;
                    int j = sc.nextInt() - 1;
                    aa[i].add(j);
                    aa[j].add(i);
                }
                dfs(-1, 0);
                hh[k] = (long) xx_[0] * MD + yy_[0];
            }
            println(hh[0] == hh[1] ? "YES" : "NO");
        }
    }
}
