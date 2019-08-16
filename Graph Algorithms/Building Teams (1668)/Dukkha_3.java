// https://cses.fi/problemset/task/1668
// Building Teams
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1668 {
    static ArrayList[] aa;
    static int[] cc;
    static int[] stack;
    static boolean dfs(int i, int c) {
        int cnt = 0;
        cc[i] = c;
        stack[cnt++] = i;
        while (cnt > 0) {
            i = stack[--cnt];
            c = 3 - cc[i];
            ArrayList<Integer> adj = aa[i];
            for (int j : adj)
                if (cc[j] == 0) {
                    cc[j] = c;
                    stack[cnt++] = j;
                } else if (cc[j] != c)
                    return false;
        }
        return true;
    }
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        aa = new ArrayList[n];
        for (int i = 0; i < n; i++)
            aa[i] = new ArrayList<Integer>();
        while (m-- > 0) {
            int i = sc.nextInt() - 1;
            int j = sc.nextInt() - 1;
            aa[i].add(j);
            aa[j].add(i);
        }
        cc = new int[n];
        stack = new int[n];
        boolean yes = true;
        for (int i = 0; i < n; i++)
            if (cc[i] == 0 && !dfs(i, 1)) {
                yes = false;
                break;
            }
        PrintWriter pw = new PrintWriter(System.out);
        if (yes) {
            for (int i = 0; i < n; i++)
                pw.print(cc[i] + " ");
            pw.println();
        } else
            pw.println("IMPOSSIBLE");
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
