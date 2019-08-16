// https://cses.fi/problemset/task/1132
// Tree Distances
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1132 {
    static class V {
        ArrayList<Integer> adj = new ArrayList<>();
        int d1, d2;
    }
    static V[] vv;
    static void dfs1(int p, int i) {
        V u = vv[i];
        int d1 = -1, d2 = -1;
        for (int j : u.adj)
            if (j != p) {
                dfs1(i, j);
                int d = vv[j].d1;
                if (d1 < d) {
                    d2 = d1; d1 = d;
                } else if (d2 < d)
                    d2 = d;
            }
        u.d1 = d1 + 1;
        u.d2 = d2 + 1;
    }
    static void dfs2(int p, int i, int d_) {
        V u = vv[i];
        int d1_ = Math.max(d_, u.d1);
        int d2_ = Math.max(d_, u.d2);
        for (int j : u.adj)
            if (j != p) {
                V v = vv[j];
                dfs2(i, j, (v.d1 + 1 == u.d1 ? d2_ : d1_) + 1);
            }
        u.d1 = d1_;
    }
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        int n = sc.nextInt();
        vv = new V[n];
        for (int i = 0; i < n; i++)
            vv[i] = new V();
        for (int h = 0; h < n - 1; h++) {
            int i = sc.nextInt() - 1;
            int j = sc.nextInt() - 1;
            vv[i].adj.add(j);
            vv[j].adj.add(i);
        }
        dfs1(-1, 0);
        dfs2(-1, 0, 0);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++)
            sb.append(vv[i].d1 + " ");
        System.out.println(sb);
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
                l = is.read(bb);
                if (l < 0) return -1;
            }
            return bb[k++];
        }
        byte skip() throws IOException {
            byte b;
            while ((b = getc()) <= 32)
                ;
            return b;
        }
        int nextInt() throws IOException {
            int n = 0;
            for (byte b = skip(); b > 32; b = getc())
                n = n * 10 + b - '0';
            return n;
        }
    }
}
