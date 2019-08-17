// https://cses.fi/problemset/task/1162
// Sorting Methods
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1162 {
    static int[] tt;
    static void update(int i, int n) {
        while (i < n) {
            tt[i]++;
            i |= i + 1;
        }
    }
    static int query(int i) {
        int cnt = 0;
        while (i >= 0) {
            cnt += tt[i];
            i &= i + 1;
            i--;
        }
        return cnt;
    }
    static void update_max(int i, int n, int x) {
        while (i < n) {
            tt[i] = Math.max(tt[i], x);
            i |= i + 1;
        }
    }
    static int query_max(int i) {
        int max = 0;
        while (i >= 0) {
            max = Math.max(max, tt[i]);
            i &= i + 1;
            i--;
        }
        return max;
    }
    static long solve1(int[] aa, int n) {
        Arrays.fill(tt, 0);
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += query(aa[i]);
            update(aa[i], n);
        }
        return (long) n * (n - 1) / 2 - sum;
    }
    static int solve2(int[] aa, int n) {
        boolean[] used = new boolean[n];
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (!used[i]) {
                cnt++;
                for (int j = i; !used[j]; j = aa[j])
                    used[j] = true;
            }
        return n - cnt;
    }
    static int solve3(int[] aa, int n) {
        Arrays.fill(tt, 0);
        for (int i = 0; i < n; i++)
            update_max(aa[i], n, query_max(aa[i]) + 1);
        return n - query_max(n - 1);
    }
    static int solve4(int[] aa, int n) {
        int[] pp = new int[n];
        for (int i = 0; i < n; i++)
            pp[aa[i]] = i;
        int i = n - 1;
        while (i > 0 && pp[i - 1] < pp[i])
            i--;
        return i;
    }
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        int n = sc.nextInt();
        int[] aa = new int[n];
        for (int i = 0; i < n; i++)
            aa[i] = sc.nextInt() - 1;
        tt = new int[n];
        long ans1 = solve1(aa, n);
        int ans2 = solve2(aa, n);
        int ans3 = solve3(aa, n);
        int ans4 = solve4(aa, n);
        System.out.println(ans1 + " " + ans2 + " " + ans3 + " " + ans4);
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
