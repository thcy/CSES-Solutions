// https://cses.fi/problemset/task/1697
// Chess Tournament
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1697 extends PrintWriter {
    CSES1697() { super(System.out); }
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
        CSES1697 c = new CSES1697(); c.main(); c.flush();
    }
    
    static class V {
        V next;
        int i;
        V(int i) {
            this.i = i;
        }
    }
    static class L {
        L next;
        V head, tail;
        int d, k;
        L(int d) {
            this.d = d;
        }
        void push(V v) {
            if (k == 0)
                head = tail = v;
            else {
                v.next = head; head = v;
            }
            k++;
        }
        V pop() {
            V v = head;
            head = head.next;
            if (head == null)
                tail = null;
            k--;
            return v;
        }
    }
    L cut(L a, int k) {
        L b = new L(a.d);
        b.k = k; a.k -= k;
        b.tail = b.head = a.head;
        while (--k > 0)
            b.tail = b.tail.next;
        a.head = b.tail.next; b.tail.next = null;
        if (a.head == null)
            a.tail = null;
        L c = a.next; a.next = b; b.next = c;
        return b;
    }
    void join(L a) {
        L b = a.next;
        while (b != null && a.d == b.d) {
            if (b.k > 0) {
                a.k += b.k;
                a.tail.next = b.head;
                a.tail = b.tail;
            }
            b = b.next;
        }
        a.next = b;
    }
    int[] ee;
    int m;
    void add(int i, L l) {
        for (V v = l.head; v != null; v = v.next) {
            ee[m++] = i; ee[m++] = v.i;
        }
    }
    void main() {
        int n = sc.nextInt();
        L[] ll = new L[n];
        V[] vv = new V[n];
        m = 0;
        for (int i = 0; i < n; i++) {
            int d = sc.nextInt();
            if (d >= n) {
                println("IMPOSSIBLE");
                return;
            }
            m += d;
            if (ll[d] == null)
                ll[d] = new L(d);
            ll[d].push(vv[i] = new V(i + 1));
        }
        ee = new int[m];
        m = 0;
        L l = null;
        for (int d = 0; d < n; d++)
            if (ll[d] != null) {
                ll[d].next = l; l = ll[d];
            }
        L l_ = l;
        while ((l = l_) != null) {
            if (l.k == 0) {
                l_ = l.next;
                continue;
            }
            int i = l.pop().i, d = l.d;
            while (d > 0) {
                if (l == null || l.d == 0) {
                    println("IMPOSSIBLE");
                    return;
                }
                if (l.k > 0) {
                    join(l);
                    if (l.k > d)
                        l = cut(l, d);
                    add(i, l); l.d--; d -= l.k;
                }
                l = l.next;
            }
        }
        println(m / 2);
        while (m > 0) {
            println(ee[m - 1] + " " + ee[m - 2]);
            m -= 2;
        }
    }
}
