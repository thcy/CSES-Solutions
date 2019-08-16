// https://cses.fi/problemset/task/1678
// Round Trip II
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1678 {
    static ArrayList[] aa;
    static int[] pp, qq;
    static int cnt;
    static boolean[] instack;
    static boolean dfs(int i) {
        instack[i] = true;
        ArrayList<Integer> adj = aa[i];
        for (int j : adj)
            if (pp[j] == -1) {
                pp[j] = i;
                if (dfs(j))
                    return true;
            } else if (instack[j]) {
                cnt = 0;
                qq[cnt++] = j;
                while (i != j) {
                    qq[cnt++] = i;
                    i = pp[i];
                }
                qq[cnt++] = j;
                return true;
            }
        instack[i] = false;
        return false;
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
        }
        instack = new boolean[n];
        pp = new int[n];
        Arrays.fill(pp, -1);
        qq = new int[n + 1];
        for (int i = 0; i < n; i++)
            if (pp[i] == -1) {
                pp[i] = i;
                if (dfs(i))
                    break;
            }
        if (cnt == 0)
            pw.println("IMPOSSIBLE");
        else {
            pw.println(cnt);
            while (cnt-- > 0)
                pw.print(qq[cnt] + 1 + " ");
            pw.println();
        }
        pw.close();
    }
}
