// https://cses.fi/problemset/task/1194
// Monsters
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1194 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        char[][] cc = new char[n][m];
        for (int i = 0; i < n; i++)
            br.readLine().getChars(0, m, cc[i], 0);
        int[] qq = new int[n * m * 2];
        int head = 0, cnt = 0;
        int[][] dd = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dd[i][j] = n * m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (cc[i][j] == 'M') {
                    dd[i][j] = 0;
                    qq[head + cnt++] = i;
                    qq[head + cnt++] = j;
                }
        int[] ii = { -1, 0, 0, 1 };
        int[] jj = { 0, -1, 1, 0 };
        char[] pp = { 'U', 'L', 'R', 'D' };
        while (cnt > 0) {
            int i = qq[head++]; cnt--;
            int j = qq[head++]; cnt--;
            int d = dd[i][j] + 1;
            for (int h = 0; h < 4; h++) {
                int i_ = i + ii[h];
                int j_ = j + jj[h];
                if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && cc[i_][j_] != '#' && dd[i_][j_] > d) {
                    dd[i_][j_] = d;
                    qq[head + cnt++] = i_;
                    qq[head + cnt++] = j_;
                }
            }
        }
        head = cnt = 0;
    out:
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (cc[i][j] == 'A') {
                    dd[i][j] = 0;
                    qq[head + cnt++] = i;
                    qq[head + cnt++] = j;
                    break out;
                }
        int[][] hh = new int[n][m];
        while (cnt > 0) {
            int i = qq[head++]; cnt--;
            int j = qq[head++]; cnt--;
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                System.out.println("YES");
                System.out.println(dd[i][j]);
                StringBuilder sb = new StringBuilder();
                while (dd[i][j] > 0) {
                    int h = hh[i][j];
                    sb.append(pp[h]);
                    i -= ii[h];
                    j -= jj[h];
                }
                System.out.println(sb.reverse().toString());
                return;
            }
            int d = dd[i][j] + 1;
            for (int h = 0; h < 4; h++) {
                int i_ = i + ii[h];
                int j_ = j + jj[h];
                if (cc[i_][j_] != '#' && dd[i_][j_] > d) {
                    dd[i_][j_] = d;
                    hh[i_][j_] = h;
                    qq[head + cnt++] = i_;
                    qq[head + cnt++] = j_;
                }
            }
        }
        System.out.println("NO");
    }
}
