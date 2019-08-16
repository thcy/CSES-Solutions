// https://cses.fi/problemset/task/1195
// Flight Discount
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1195 {
    static final long INF = Long.MAX_VALUE;
    static class E {
        int j, c;
        E(int j, int c) {
            this.j = j; this.c = c;
        }
    }
    static class V {
        ArrayList<E> adj = new ArrayList<>();
        int i;
        long c = INF;
        V(int i) {
            this.i = i;
        }
    }
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        V[] vv = new V[n * 2];
        for (int i = 0; i < n * 2; i++)
            vv[i] = new V(i);
        for (int h = 0; h < m; h++) {
            int i = sc.nextInt() - 1;
            int j = sc.nextInt() - 1;
            int c = sc.nextInt();
            vv[i * 2 + 0].adj.add(new E(j * 2 + 0, c));
            vv[i * 2 + 1].adj.add(new E(j * 2 + 1, c));
            vv[i * 2 + 0].adj.add(new E(j * 2 + 1, c / 2));
        }
        TreeSet<V> pq = new TreeSet<>((u, v) -> u.c == v.c ? u.i - v.i : u.c < v.c ? -1 : 1);
        vv[0].c = vv[1].c = 0;
        pq.add(vv[0]);
        pq.add(vv[1]);
        V u;
        while ((u = pq.pollFirst()) != null) {
            if (u == vv[n * 2 - 1]) {
                System.out.println(u.c);
                return;
            }
            for (E e : u.adj) {
                V v = vv[e.j];
                long c = u.c + e.c;
                if (v.c == INF) {
                    v.c = c;
                    pq.add(v);
                } else if (v.c > c) {
                    pq.remove(v);
                    v.c = c;
                    pq.add(v);
                }
            }
        }
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
