// https://cses.fi/problemset/task/1711
// Distinct Routes
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1711 {
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
                if (cc[h] != 0) {
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
    static boolean dfs(int n, int i, int t) {
        if (i == t)
            return true;
        int d = dd[i] + 1;
        ArrayList<Integer> adj = aa[i];
        for (int h : adj)
            if (cc[h] != 0) {
                int j = i ^ ij[h >> 1];
                if (dd[j] == d && dfs(n, j, t)) {
                    cc[h]--; cc[h ^ 1]++;
                    return true;
                }
            }
        dd[i] = n;
        return false;
    }
    static int dinic(int n, int s, int t) {
        dd = new int[n];
        qq = new int[n];
        int f = 0;
        while (bfs(n, s, t))
            while (dfs(n, s, t))
                f++;
        return f;
    }
    static void link(int i, int j, int h, int c) {
        ij[h] = i ^ j;
        cc[h << 1] = c;
        aa[i].add(h << 1);
        aa[j].add(h << 1 ^ 1);
    }
    static int path(int i, int t) {
        int cnt = 0;
        while (i != t) {
            qq[cnt++] = i;
            ArrayList<Integer> adj = aa[i];
            for (int h : adj)
                if ((h & 1) == 0 && cc[h ^ 1] != 0) {
                    cc[h]++; cc[h ^ 1]--;
                    i ^= ij[h >> 1];
                    break;
                }
        }
        qq[cnt++] = t;
        return cnt;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        aa = new ArrayList[n * 2];
        for (int i = 0; i < n * 2; i++)
            aa[i] = new ArrayList<Integer>();
        ij = new int[m + n];
        cc = new int[(m + n) * 2];
        for (int h = 0; h < m; h++) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken()) - 1;
            int j = Integer.parseInt(st.nextToken()) - 1;
            link(i << 1 ^ 1, j << 1, h, 1);
        }
        for (int i = 0; i < n; i++)
            link(i << 1, i << 1 ^ 1, m + i, n);
        int s = 0, t = n - 1 << 1 ^ 1;
        int k = dinic(n * 2, s, t);
        pw.println(k);
        while (k-- > 0) {
            int cnt = path(s, t);
            pw.println(cnt / 2);
            for (int i = 0; i < cnt; i += 2)
                pw.print((qq[i] >> 1) + 1 + " ");
            pw.println();
        }
        pw.close();
    }
}
