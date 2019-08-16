// https://cses.fi/problemset/task/1734
// Distinct Values Queries
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1734 {
    static int[] tt;
    static void update(int i, int n, int x) {
        while (i < n) {
            tt[i] += x;
            i |= i + 1;
        }
    }
    static int query(int i) {
        int x = 0;
        while (i >= 0) {
            x += tt[i];
            i &= i + 1;
            i--;
        }
        return x;
    }
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int[] aa = new int[n];
        for (int i = 0; i < n; i++)
            aa[i] = sc.nextInt();
        int[] ll = new int[q];
        int[] rr = new int[q];
        for (int h = 0; h < q; h++) {
            ll[h] = sc.nextInt() - 1;
            rr[h] = sc.nextInt() - 1;
        }
        Integer[] ii = new Integer[Math.max(n, q)];
        for (int i = 0; i < n; i++)
            ii[i] = i;
        Arrays.sort(ii, 0, n, (i, j) -> aa[i] != aa[j] ? aa[i] - aa[j] : i - j);
        int[] pp = new int[n];
        for (int i = 0; i < n; i++)
            pp[ii[i]] = i == 0 || aa[ii[i - 1]] != aa[ii[i]] ? n : ii[i - 1];
        //for (int h = 0; h < q; h++) ii[h] = h;
        //Arrays.sort(ii, 0, q, (i, j) -> rr[i] - rr[j]);
        ArrayList[] bb = new ArrayList[n];
        for (int i = 0; i < n; i++)
            bb[i] = new ArrayList<Integer>();
        for (int h = 0; h < q; h++)
            bb[rr[h]].add(h);
        q = 0;
        for (int i = 0; i < n; i++) {
            ArrayList<Integer> bi = bb[i];
            for (int h : bi)
                ii[q++] = h;
        }
        tt = new int[n];
        int[] dd = new int[q];
        for (int h = 0, r = 0; h < q; ) {
            int h_, r_;
            r_ = rr[ii[h]];
            while (r <= r_) {
                update(pp[r], n, -1);
                update(r, n, 1);
                r++;
            }
            while (h < q && rr[h_ = ii[h]] == r_) {
                dd[h_] = query(rr[h_]) - query(ll[h_] - 1);
                h++;
            }
        }
        for (int h = 0; h < q; h++)
            pw.println(dd[h]);
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
