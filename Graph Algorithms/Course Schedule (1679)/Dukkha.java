// https://cses.fi/problemset/task/1679
// Course Schedule
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1679 {
    static ArrayList[] aa;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        aa = new ArrayList[n];
        for (int i = 0; i < n; i++)
            aa[i] = new ArrayList<Integer>();
        int[] dd = new int[n];
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken()) - 1;
            int j = Integer.parseInt(st.nextToken()) - 1;
            aa[i].add(j);
            dd[j]++;
        }
        int[] qq = new int[n];
        int head = 0, cnt = 0;
        for (int i = 0; i < n; i++)
            if (dd[i] == 0)
                qq[head + cnt++] = i;
        while (cnt > 0) {
            int i = qq[head++]; cnt--;
            ArrayList<Integer> adj = aa[i];
            for (int j : adj)
                if (--dd[j] == 0)
                    qq[head + cnt++] = j;
        }
        if (head == n) {
            for (int i = 0; i < n; i++)
                pw.print(qq[i] + 1 + " ");
            pw.println();
        } else
            pw.println("IMPOSSIBLE");
        pw.close();
    }
}
