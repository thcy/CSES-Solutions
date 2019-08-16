// https://cses.fi/problemset/task/1668
// Building Teams
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1668 {
    static ArrayList[] aa;
    static int[] cc;
    static boolean dfs(int i, int c) {
        if (cc[i] != 0)
            return cc[i] == c;
        cc[i] = c;
        ArrayList<Integer> adj = aa[i];
        for (int j : adj)
            if (!dfs(j, 3 - c))
                return false;
        return true;
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
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken()) - 1;
            int j = Integer.parseInt(st.nextToken()) - 1;
            aa[i].add(j);
            aa[j].add(i);
        }
        cc = new int[n];
        boolean yes = true;
        for (int i = 0; i < n; i++)
            if (cc[i] == 0 && !dfs(i, 1)) {
                yes = false;
                break;
            }
        if (yes) {
            for (int i = 0; i < n; i++)
                pw.print(cc[i] + " ");
            pw.println();
        } else
            pw.println("IMPOSSIBLE");
        pw.close();
    }
}
