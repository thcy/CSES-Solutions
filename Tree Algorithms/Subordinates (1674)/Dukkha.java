// https://cses.fi/problemset/task/1674
// Subordinates
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1674 {
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int[] pp = new int[n + 1];
        int[] dd = new int[n + 1];
        for (int i = 2; i <= n; i++) {
            int p = sc.nextInt();
            pp[i] = p;
            dd[p]++;
        }
        int[] qq = new int[n + 1];
        int head = 0, cnt = 0;
        for (int i = 1; i <= n; i++)
            if (dd[i] == 0)
                qq[head + cnt++] = i;
        int[] aa = new int[n + 1];
        Arrays.fill(aa, 1);
        while (cnt > 0) {
            int i = qq[head++]; cnt--;
            int p = pp[i];
            aa[p] += aa[i];
            if (--dd[p] == 0)
                qq[head + cnt++] = p;
        }
        for (int i = 1; i <= n; i++)
            pw.print(aa[i] - 1 + " ");
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
