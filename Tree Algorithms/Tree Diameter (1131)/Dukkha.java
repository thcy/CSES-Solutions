// https://cses.fi/problemset/task/1131
// Tree Diameter
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1131 {
    static ArrayList[] aa;
    static int d_, i_;
    static void dfs(int p, int i, int d) {
        if (d_ < d) {
            d_ = d;
            i_ = i;
        }
        ArrayList<Integer> adj = aa[i];
        for (int j : adj)
            if (j != p)
                dfs(i, j, d + 1);
    }
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        int n = sc.nextInt();
        aa = new ArrayList[n];
        for (int i = 0; i < n; i++)
            aa[i] = new ArrayList<Integer>();
        for (int h = 0; h < n - 1; h++) {
            int i = sc.nextInt() - 1;
            int j = sc.nextInt() - 1;
            aa[i].add(j);
            aa[j].add(i);
        }
        dfs(-1, 0, 0);
        dfs(-1, i_, 0);
        System.out.println(d_);
    }
    static class _Scanner {
        InputStream is;
        _Scanner(InputStream is) {
            this.is = is;
        }
        byte[] bb = new byte[1 << 15];
        int k, l;
        byte getc() throws IOException {
            if (k >= l) {
                k = 0;
                l = is.read(bb); //if (l < 0) return -1;
            }
            return bb[k++];
        }
        byte skip() throws IOException {
            byte b;
            while ((b = getc()) <= 32)
                ;
            return b;
        }
        String next() throws IOException {
            StringBuilder sb = new StringBuilder();
            for (byte b = skip(); b > 32; b = getc())
                sb.append((char) b);
            return sb.toString();
        }
        int nextInt() throws IOException {
            int n = 0;
            for (byte b = skip(); b > 32; b = getc())
                n = n * 10 + b - '0';
            return n;
        }
    }
}
