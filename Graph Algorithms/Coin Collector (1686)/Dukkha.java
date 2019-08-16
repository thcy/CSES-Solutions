// https://cses.fi/problemset/task/1686
// Coin Collector
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1686 {
    static ArrayList[] aa, bb;
    static int[] cc, qq;
    static int cnt;
    static void dfs1(int i) {
        if (cc[i] != 0)
            return;
        cc[i] = 1;
        ArrayList<Integer> adj = aa[i];
        for (int j : adj)
            dfs1(j);
        qq[cnt++] = i;
    }
    static void dfs2(int j, int c) {
        if (cc[j] != 0)
            return;
        cc[j] = c;
        ArrayList<Integer> adj = bb[j];
        for (int i : adj)
            dfs2(i, c);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        aa = new ArrayList[n];
        bb = new ArrayList[n];
        int[] ww = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            aa[i] = new ArrayList<Integer>();
            bb[i] = new ArrayList<Integer>();
            ww[i] = Integer.parseInt(st.nextToken());
        }
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken()) - 1;
            int j = Integer.parseInt(st.nextToken()) - 1;
            aa[i].add(j);
            bb[j].add(i);
        }
        cc = new int[n];
        qq = new int[n];
        for (int i = 0; i < n; i++)
            if (cc[i] == 0)
                dfs1(i);
        Arrays.fill(cc, 0);
        int c = 0;
        for (int h = n - 1; h >= 0; h--) {
            int j = qq[h];
            if (cc[j] == 0)
                dfs2(j, ++c);
        }
        for (int i = 0; i < n; i++)
            cc[i]--;
        long[] ww_ = new long[c];
        for (int i = 0; i < n; i++)
            ww_[cc[i]] += ww[i];
        HashSet[] bb_ = new HashSet[c];
        for (int cj = 0; cj < c; cj++)
            bb_[cj] = new HashSet<Integer>();
        for (int j = 0; j < n; j++) {
            int cj = cc[j];
            ArrayList<Integer> adj = bb[j];
            for (int i : adj) {
                int ci = cc[i];
                if (ci < cj)
                    bb_[cj].add(ci);
            }
        }
        long[] dp = new long[c];
        long ans = 0;
        for (int cj = 0; cj < c; cj++) {
            long x = 0;
            HashSet<Integer> adj = bb_[cj];
            for (int ci : adj)
                x = Math.max(x, dp[ci]);
            ans = Math.max(ans, dp[cj] = x + ww_[cj]);
        }
        System.out.println(ans);
    }
}
