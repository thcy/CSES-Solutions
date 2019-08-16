// https://cses.fi/problemset/task/1684
// Giant Pizza
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1684 {
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
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        aa = new ArrayList[n * 2];
        bb = new ArrayList[n * 2];
        for (int i = 0; i < n * 2; i++) {
            aa[i] = new ArrayList<Integer>();
            bb[i] = new ArrayList<Integer>();
        }
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            boolean uplus = st.nextToken().charAt(0) == '+';
            int u = Integer.parseInt(st.nextToken()) - 1;
            boolean vplus = st.nextToken().charAt(0) == '+';
            int v = Integer.parseInt(st.nextToken()) - 1;
            int up = u * 2 + (uplus ? 1 : 0);
            int um = u * 2 + (uplus ? 0 : 1);
            int vp = v * 2 + (vplus ? 1 : 0);
            int vm = v * 2 + (vplus ? 0 : 1);
            aa[um].add(vp);
            bb[vp].add(um);
            aa[vm].add(up);
            bb[up].add(vm);
        }
        cc = new int[n * 2];
        qq = new int[n * 2];
        for (int i = 0; i < n * 2; i++)
            if (cc[i] == 0)
                dfs1(i);
        Arrays.fill(cc, 0);
        int c = 0;
        for (int h = n * 2 - 1; h >= 0; h--) {
            int j = qq[h];
            if (cc[j] == 0)
                dfs2(j, ++c);
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n * 2; i += 2) {
            if (cc[i] == cc[i + 1]) {
                System.out.println("IMPOSSIBLE");
                return;
            }
            sb.append(cc[i] < cc[i + 1] ? "+ " : "- ");
        }
        System.out.println(sb);
    }
}
