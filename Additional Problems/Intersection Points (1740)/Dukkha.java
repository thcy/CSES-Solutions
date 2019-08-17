// https://cses.fi/problemset/task/1740
// Intersection Points
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1740 extends PrintWriter {
    CSES1740() { super(System.out); }
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
            boolean minus = c == '-'; if (minus) c = getc();
            int a = 0;
            while (c > 32) { a = a * 10 + c - '0'; c = getc(); }
            return minus ? -a : a;
        }
    }
    Scanner sc = new Scanner(System.in);
    public static void main(String[] $) {
        CSES1740 c = new CSES1740(); c.main(); c.flush();
    }
    
    static final int M = 1000000, INF = M * 2 + 1;
    int[] tt = new int[INF];
    void update(int i, int x) {
        while (i < INF) {
            tt[i] += x;
            i |= i + 1;
        }
    }
    int query(int i) {
        int x = 0;
        while (i >= 0) {
            x += tt[i];
            i &= i + 1;
            i--;
        }
        return x;
    }
    static class V {
        int y, l, r;
        V(int y, int l, int r) {
            this.y = y; this.l = l; this.r = r;
        }
    }
    void main() {
        int n = sc.nextInt();
        ArrayList<V> list = new ArrayList<>();
        while (n-- > 0) {
            int x1 = sc.nextInt() + M;
            int y1 = sc.nextInt();
            int x2 = sc.nextInt() + M;
            int y2 = sc.nextInt();
            if (y1 == y2)
                list.add(new V(y1, x1, x2));
            else {
                list.add(new V(y1, -1, x1));
                list.add(new V(y2, INF, x1));
            }
        }
        Collections.sort(list, (u, v) -> u.y != v.y ? u.y - v.y : u.l - v.l);
        //V[] vv = list.toArray(new V[0]);
        //Arrays.sort(vv, (u, v) -> u.y != v.y ? u.y - v.y : u.l - v.l);
        long ans = 0;
        for (V v : list)
            if (v.l == -1)
                update(v.r, 1);
            else if (v.l == INF)
                update(v.r, -1);
            else
                ans += query(v.r) - query(v.l - 1);
        println(ans);
    }
}
