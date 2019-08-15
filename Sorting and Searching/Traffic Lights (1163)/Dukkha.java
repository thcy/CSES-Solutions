// practice with rainboy
// https://cses.fi/problemset/task/1163
// Traffic Lights
import java.io.*;
import java.util.*;

public class CSES1163 {
    static int[] gap, dsu;
    static int find(int i) {
        return dsu[i] < 0 ? i : (dsu[i] = find(dsu[i]));
    }
    static int join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (dsu[i] > dsu[j]) {
                dsu[i] = j;
                gap[j] += gap[i];
                i = j;
            } else {
                if (dsu[i] == dsu[j])
                    dsu[i]--;
                dsu[j] = i;
                gap[i] += gap[j];
            }
        }
        return gap[i];
    }
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        int x = sc.nextInt();
        int n = sc.nextInt();
        int[] pp = new int[1 + n + 1];
        pp[0] = 0;
        for (int i = 1; i <= n; i++)
            pp[i] = sc.nextInt();
        pp[n + 1] = x;
        Integer[] ii = new Integer[1 + n + 1];
        for (int i = 0; i < 1 + n + 1; i++)
            ii[i] = i;
        Arrays.sort(ii, (i, j) -> pp[i] - pp[j]);
        gap = new int[1 + n];
        for (int i = 0; i <= n; i++)
            gap[i] = pp[ii[i + 1]] - pp[ii[i]];
        dsu = new int[1 + n];
        Arrays.fill(dsu, -1);
        for (int i = 0; i < 1 + n + 1; i++)
            pp[ii[i]] = i;
        int ans = 0;
        for (int i = 0; i <= n; i++)
            ans = Math.max(ans, gap[i]);
        int[] aa = new int[n];
        aa[n - 1] = ans;
        for (int i = n; i >= 2; i--)
            aa[i - 2] = ans = Math.max(ans, join(pp[i] - 1, pp[i]));
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++)
            sb.append(aa[i] + " ");
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
