// https://cses.fi/problemset/task/1694
// Download Speed
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1694 {
    static final int INF = 0x3f3f3f3f;
    static ArrayList[] aa;
    static int[] dd, qq;
    static int[] ij, cc;
    static boolean bfs(int n, int s, int t) {
        Arrays.fill(dd, n);
        dd[s] = 0;
        int head = 0, cnt = 0;
        qq[head + cnt++] = s;
        while (cnt > 0) {
            int i = qq[head++]; cnt--;
            int d = dd[i] + 1;
            ArrayList<Integer> adj = aa[i];
            for (int h : adj)
                if (cc[h] > 0) {
                    int j = i ^ ij[h >> 1];
                    if (dd[j] == n) {
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
        for (int h : adj)
            if (cc[h] > 0) {
                int j = i ^ ij[h >> 1];
                if (dd[j] == d) {
                    int f = dfs(n, j, t, Math.min(c, cc[h]));
                    if (f != 0) {
                        cc[h] -= f;
                        cc[h ^ 1] += f;
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
        ij = new int[m];
        cc = new int[m * 2];
        for (int h = 0; h < m; h++) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken()) - 1;
            int j = Integer.parseInt(st.nextToken()) - 1;
            int c = Integer.parseInt(st.nextToken());
            cc[h * 2] = c;
            ij[h] = i ^ j;
            aa[i].add(h * 2);
            aa[j].add(h * 2 + 1);
        }
        System.out.println(dinic(n, 0, n - 1));
    }
}
