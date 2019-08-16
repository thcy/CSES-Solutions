// https://cses.fi/problemset/task/1694
// Download Speed
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1694 {
    static final int INF = 0x3f3f3f3f;
    static ArrayList[] aa;
    static int[] dd, qq;
    static int[] ii, jj, cc, ff;
    static boolean bfs(int n, int s, int t) {
        Arrays.fill(dd, n);
        dd[s] = 0;
        int head = 0, cnt = 0;
        qq[head + cnt++] = s;
        while (cnt > 0) {
            int i = qq[head++]; cnt--;
            int d = dd[i] + 1;
            ArrayList<Integer> adj = aa[i];
            for (int h : adj) {
                int j = i ^ ii[h] ^ jj[h];
                if (dd[j] == n && (i == ii[h] && ff[h] < cc[h] || i == jj[h] && ff[h] > 0)) {
                    dd[j] = d;
                    if (j == t)
                        return true;
                    qq[head + cnt++] = j;
                }
            }
        }
        return false;
    }
    static int dfs(int n, int i, int t, int c) {
        if (i == t || c == 0)
            return c;
        int d = dd[i] + 1;
        ArrayList<Integer> adj = aa[i];
        for (int h : adj) {
            int j = i ^ ii[h] ^ jj[h];
            if (dd[j] == d) {
                int c_ = i == ii[h] ? cc[h] - ff[h] : ff[h];
                int f = dfs(n, j, t, Math.min(c, c_));
                if (f != 0) {
                    ff[h] += i == ii[h] ? f : -f;
                    return f;
                }
            }
        }
        dd[i] = n;
        return 0;
    }
    static long dinic(int n, int s, int t) {
        dd = new int[n];
        qq = new int[n];
        long sum = 0;
        while (bfs(n, s, t)) {
            int f;
            while ((f = dfs(n, s, t, INF)) != 0)
                sum += f;
        }
        return sum;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        aa = new ArrayList[n];
        for (int i = 0; i < n; i++)
            aa[i] = new ArrayList<Integer>();
        ii = new int[m];
        jj = new int[m];
        cc = new int[m];
        ff = new int[m];
        for (int h = 0; h < m; h++) {
            st = new StringTokenizer(br.readLine());
            ii[h] = Integer.parseInt(st.nextToken()) - 1;
            jj[h] = Integer.parseInt(st.nextToken()) - 1;
            cc[h] = Integer.parseInt(st.nextToken());
            aa[ii[h]].add(h);
            aa[jj[h]].add(h);
        }
        System.out.println(dinic(n, 0, n - 1));
    }
}
