// https://cses.fi/problemset/task/1695
// Police Chase
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1695 {
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
                    int j = i ^ ij[h >> 2];
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
                int j = i ^ ij[h >> 2];
                if (dd[j] == d && dfs(n, j, t)) {
                    cc[h]--;
                    cc[h ^ 1]++;
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
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        aa = new ArrayList[n];
        for (int i = 0; i < n; i++)
            aa[i] = new ArrayList<Integer>();
        ij = new int[m];
        cc = new int[m * 4];
        for (int h = 0; h < m; h++) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken()) - 1;
            int j = Integer.parseInt(st.nextToken()) - 1;
            ij[h] = i ^ j;
            cc[h * 4 + 0] = 1;
            cc[h * 4 + 2] = 1;
            aa[i].add(h * 4 + 0);
            aa[j].add(h * 4 + 1);
            aa[j].add(h * 4 + 2);
            aa[i].add(h * 4 + 3);
        }
        pw.println(dinic(n, 0, n - 1));
        for (int i = 0; i < n; i++)
            if (dd[i] < n) {
                ArrayList<Integer> adj = aa[i];
                for (int h : adj) {
                    int j = i ^ ij[h >> 2];
                    if (dd[j] == n && (h & 1) == 0)
                        pw.println((i + 1) + " " + (j + 1));
                }
            }
        pw.close();
    }
}
