// https://cses.fi/problemset/task/1757
// Course Schedule II
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1757 extends PrintWriter {
    CSES1757() { super(System.out); }
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
        CSES1757 o = new CSES1757(); o.main(); o.flush();
    }
    
    void main() {
        int n = sc.nextInt();
        int m = sc.nextInt();
        ArrayList[] aa = new ArrayList[n];
        for (int i = 0; i < n; i++)
            aa[i] = new ArrayList<Integer>();
        int[] dd = new int[n];
        while (m-- > 0) {
            int i = sc.nextInt() - 1;
            int j = sc.nextInt() - 1;
            aa[j].add(i);
            dd[i]++;
        }
        TreeSet<Integer> pq = new TreeSet<>((i, j) -> i - j);
        for (int i = 0; i < n; i++)
            if (dd[i] == 0)
                pq.add(i);
        int[] stack = new int[n];
        n = 0;
        Integer last;
        while ((last = pq.pollLast()) != null) {
            int i = last;
            stack[n++] = i;
            ArrayList<Integer> adj = aa[i];
            for (int j : adj)
                if (--dd[j] == 0)
                    pq.add(j);
        }
        while (n-- > 0)
            print(stack[n] + 1 + " ");
        println();
    }
}
