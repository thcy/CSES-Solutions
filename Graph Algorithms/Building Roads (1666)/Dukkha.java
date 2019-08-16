// https://cses.fi/problemset/task/1666
// Building Roads
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1666 {
    static ArrayList[] aa;
    static int[] cc;
    static void dfs(int i, int c) {
        cc[i] = c;
        ArrayList<Integer> adj = aa[i];
        for (int j : adj)
            if (cc[j] == -1)
                dfs(j, c);
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
        Arrays.fill(cc, -1);
        for (int i = 0; i < n; i++)
            if (cc[i] == -1)
                dfs(i, i);
        int k = 0;
        for (int i = 0; i < n; i++)
            if (cc[i] == i)
                cc[k++] = i + 1;
        pw.println(k - 1);
        for (int i = 1; i < k; i++)
            pw.println(cc[i - 1] + " " + cc[i]);
        pw.close();
    }
}
