// https://cses.fi/problemset/task/1683
// Planets and Kingdoms
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1683 {
    static ArrayList[] aa, bb;
    static int[] qq, cc;
    static int cnt;
    static int[] stack;
    static void dfs1(int i) {
        int k = 0;
        stack[k++] = i;
        while (k > 0) {
            i = stack[k - 1];
            if (cc[i] == 0) {
                cc[i] = 1;
                ArrayList<Integer> adj = aa[i];
                for (int j : adj)
                    if (cc[j] == 0)
                        stack[k++] = j;
            } else {
                k--;
                if (cc[i] == 1) {
                    cc[i] = -1;
                    qq[cnt++] = i;
                }
            }
        }
    }
    static void dfs2(int j, int c) {
        int k = 0;
        stack[k++] = j; cc[j] = c;
        while (k > 0) {
            j = stack[--k];
            ArrayList<Integer> adj = bb[j];
            for (int i : adj)
                if (cc[i] == -1) {
                    stack[k++] = i; cc[i] = c;
                }
        }
    }
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int m = sc.nextInt();
        aa = new ArrayList[n];
        bb = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            aa[i] = new ArrayList<Integer>();
            bb[i] = new ArrayList<Integer>();
        }
        stack = new int[Math.max(m + 1, n)];
        while (m-- > 0) {
            int i = sc.nextInt() - 1;
            int j = sc.nextInt() - 1;
            aa[i].add(j);
            bb[j].add(i);
        }
        cc = new int[n];
        qq = new int[n];
        for (int i = 0; i < n; i++)
            if (cc[i] == 0)
                dfs1(i);
        int c = 0;
        for (int h = n - 1; h >= 0; h--) {
            int j = qq[h];
            if (cc[j] == -1)
                dfs2(j, ++c);
        }
        pw.println(c);
        for (int i = 0; i < n; i++)
            pw.print(cc[i] + " ");
        pw.println();
        pw.close();
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
                if (l <= 0) return -1;
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
