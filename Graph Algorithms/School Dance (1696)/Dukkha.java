// https://cses.fi/problemset/task/1696
// School Dance
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1696 {
    static ArrayList[] aa;
    static int[] uu, vv, dd, qq;
    static boolean bfs(int n) {
        int head = 0, cnt = 0;
        dd[0] = n;
        for (int u = 1; u <= n; u++)
            if (vv[u] == 0) {
                dd[u] = 0;
                qq[head + cnt++] = u;
            } else
                dd[u] = n;
        while (cnt > 0) {
            int u = qq[head++]; cnt--;
            int d = dd[u] + 1;
            ArrayList<Integer> adj = aa[u];
            for (int v : adj) {
                int w = uu[v];
                if (dd[w] == n) {
                    dd[w] = d;
                    if (w == 0)
                        return true;
                    qq[head + cnt++] = w;
                }
            }
        }
        return false;
    }
    static boolean dfs(int n, int u) {
        if (u == 0)
            return true;
        int d = dd[u] + 1;
        ArrayList<Integer> adj = aa[u];
        for (int v : adj) {
            int w = uu[v];
            if (dd[w] == d && dfs(n, w)) {
                vv[u] = v;
                uu[v] = u;
                return true;
            }
        }
        dd[u] = n;
        return false;
    }
    static int hopcroft_karp(int n, int n_) {
        vv = new int[n + 1];
        uu = new int[n_ + 1];
        dd = new int[n + 1];
        qq = new int[n];
        int m = 0;
        while (bfs(n))
            for (int u = 1; u <= n; u++)
                if (vv[u] == 0 && dfs(n, u))
                    m++;
        return m;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int n_ = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        aa = new ArrayList[n + 1];
        for (int u = 1; u <= n; u++)
            aa[u] = new ArrayList<Integer>();
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            aa[u].add(v);
        }
        pw.println(hopcroft_karp(n, n_));
        for (int u = 1; u <= n; u++)
            if (vv[u] != 0)
                pw.println(u + " " + vv[u]);
        pw.close();
    }
}
