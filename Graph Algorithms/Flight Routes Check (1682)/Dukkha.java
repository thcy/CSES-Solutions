// https://cses.fi/problemset/task/1682
// Flight Routes Check
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1682 {
    static ArrayList[] aa, bb, cc;
    static boolean[] visited;
    static void dfs(int i) {
        if (visited[i])
            return;
        visited[i] = true;
        ArrayList<Integer> adj = cc[i];
        for (int j : adj)
            dfs(j);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        aa = new ArrayList[n];
        bb = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            aa[i] = new ArrayList<Integer>();
            bb[i] = new ArrayList<Integer>();
        }
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken()) - 1;
            int j = Integer.parseInt(st.nextToken()) - 1;
            aa[i].add(j);
            bb[j].add(i);
        }
        visited = new boolean[n];
        cc = aa;
        dfs(0);
        for (int i = 0; i < n; i++)
            if (!visited[i]) {
                System.out.println("NO");
                System.out.println("1 " + (i + 1));
                return;
            }
        Arrays.fill(visited, false);
        cc = bb;
        dfs(0);
        for (int i = 0; i < n; i++)
            if (!visited[i]) {
                System.out.println("NO");
                System.out.println((i + 1) + " 1");
                return;
            }
        System.out.println("YES");
    }
}
