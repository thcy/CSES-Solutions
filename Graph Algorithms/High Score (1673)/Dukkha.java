// https://cses.fi/problemset/task/1673
// High Score
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1673 {
    static ArrayList[] aa;
    static boolean[] used;
    static final long INF = 0x3f3f3f3f3f3f3f3fL;
    static int[] uu, vv, ww;
    static long[] dd;
    static void dfs(int i) {
        if (used[i])
            return;
        used[i] = true;
        ArrayList<Integer> adj = aa[i];
        for (int j : adj)
            dfs(j);
    }
    static boolean relax(int m) {
        boolean updated = false;
        for (int h = 0; h < m; h++) {
            int u = uu[h];
            int v = vv[h];
            int w = ww[h];
            if (used[u] && used[v] && dd[u] != INF) {
                long d = dd[u] + w;
                if (dd[v] > d) {
                    updated = true;
                    dd[v] = d;
                }
            }
        }
        return updated;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        aa = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++)
            aa[i] = new ArrayList<Integer>();
        uu = new int[m];
        vv = new int[m];
        ww = new int[m];
        for (int h = 0; h < m; h++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            uu[h] = u;
            vv[h] = v;
            ww[h] = -w;
            aa[v].add(u);
        }
        used = new boolean[n + 1];
        dfs(n);
        dd = new long[n + 1];
        Arrays.fill(dd, INF);
        dd[1] = 0;
        for (int h = 1; h < n; h++)
            relax(m);
        System.out.println(relax(m) ? -1 : -dd[n]);
    }
}
