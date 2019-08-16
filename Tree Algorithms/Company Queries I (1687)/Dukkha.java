// https://cses.fi/problemset/task/1687
// Company Queries I
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1687 {
    static ArrayList[] aa, hh;
    static int[] stack;
    static int cnt;
    static int[] kk, bb;
    static void dfs(int i) {
        ArrayList<Integer> que = hh[i];
        for (int h : que) {
            int k = kk[h];
            bb[h] = k <= cnt ? stack[cnt - k] + 1 : -1;
        }
        stack[cnt++] = i;
        ArrayList<Integer> adj = aa[i];
        for (int j : adj)
            dfs(j);
        cnt--;
    }
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int q = sc.nextInt();
        aa = new ArrayList[n];
        hh = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            aa[i] = new ArrayList<Integer>();
            hh[i] = new ArrayList<Integer>();
        }
        for (int i = 1; i < n; i++) {
            int p = sc.nextInt() - 1;
            aa[p].add(i);
        }
        kk = new int[q];
        bb = new int[q];
        for (int h = 0; h < q; h++) {
            int i = sc.nextInt() - 1;
            kk[h] = sc.nextInt();
            hh[i].add(h);
        }
        stack = new int[n];
        dfs(0);
        for (int h = 0; h < q; h++)
            pw.println(bb[h]);
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
