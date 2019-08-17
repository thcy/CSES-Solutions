// https://cses.fi/problemset/task/1147
// Building
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1147 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        char[][] cc = new char[n][m];
        for (int i = 0; i < n; i++)
            br.readLine().getChars(0, m, cc[i], 0);
        int[][] ll = new int[n][m];
        int[][] rr = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                if (cc[i][j] == '*')
                    ll[i][j] = 0;
                else
                    ll[i][j] = (j == 0 ? 0 : ll[i][j - 1]) + 1;
            for (int j = m - 1; j >= 0; j--)
                if (cc[i][j] == '*')
                    rr[i][j] = 0;
                else
                    rr[i][j] = (j == m - 1 ? 0 : rr[i][j + 1]) + 1;
        }
        int ans = 0;
        for (int j = 0; j < m; j++) {
            int h = 0, l = m, r = m;
            for (int i = 0; i < n; i++) {
                if (cc[i][j] == '*') {
                    h = 0;
                    l = r = m;
                } else {
                    h++;
                    l = Math.min(l, ll[i][j]);
                    r = Math.min(r, rr[i][j]);
                }
                ans = Math.max(ans, (l + r - 1) * h);
            }
        }
        System.out.println(ans);
    }
}
