// practice with rainboy
// https://cses.fi/problemset/task/1193
// Labyrinth
import java.io.*;
import java.util.*;

public class CSES1193 {
    static int n, m;
    static char[][] cc;
    static int[][] dd, hh;
    static int[] ii = { -1, 0, 0, 1 };
    static int[] jj = { 0, -1, 1, 0 };
    static char[] zz = "ULRD".toCharArray();
    static boolean bfs(int i, int j) {
        int[] qq = new int[n * m * 2];
        int head = 0, cnt = 0;
        dd[i][j] = 0;
        qq[head + cnt++] = i;
        qq[head + cnt++] = j;
        while (cnt > 0) {
            i = qq[head++]; cnt--;
            j = qq[head++]; cnt--;
            int d = dd[i][j] + 1;
            for (int h = 0; h < 4; h++) {
                int i_ = i + ii[h];
                int j_ = j + jj[h];
                if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && cc[i_][j_] != '#' && dd[i_][j_] > d) {
                    dd[i_][j_] = d;
                    hh[i_][j_] = h;
                    if (cc[i_][j_] == 'B')
                        return true;
                    qq[head + cnt++] = i_;
                    qq[head + cnt++] = j_;
                }
            }
        }
        return false;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        cc = new char[n][m];
        for (int i = 0; i < n; i++)
            br.readLine().getChars(0, m, cc[i], 0);
        dd = new int[n][m];
        hh = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dd[i][j] = n * m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (cc[i][j] == 'A') {
                    if (bfs(i, j)) {
                        System.out.println("YES");
                    out:
                        for (i = 0; i < n; i++)
                            for (j = 0; j < m; j++)
                                if (cc[i][j] == 'B')
                                    break out;
                        System.out.println(dd[i][j]);
                        StringBuilder sb = new StringBuilder();
                        for (int d = dd[i][j]; d > 0; d--) {
                            int h = hh[i][j];
                            sb.append(zz[h]);
                            i -= ii[h];
                            j -= jj[h];
                        }
                        System.out.println(sb.reverse().toString());
                        return;
                    }
                }
        System.out.println("NO");
    }
}
