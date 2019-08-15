// https://cses.fi/problemset/task/1625
// Grid Paths
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1625 {
    static boolean[][] used = new boolean[9][9];
    static {
        for (int i = 0; i <= 8; i += 8)
            for (int j = 0; j <= 8; j++)
                used[i][j] = true;
                for (int j = 0; j <= 8; j += 8)
                    for (int i = 0; i <= 8; i++)
                        used[i][j] = true;
                        }
    static char[] path;
    static int cnt;
    static boolean only(int i, int j) {
        if (i == 7 && j == 1)
            return false;
        int k = 0;
        if (!used[i - 1][j])
            k++;
        if (!used[i + 1][j])
            k++;
        if (!used[i][j - 1])
            k++;
        if (!used[i][j + 1])
            k++;
        return k == 1;
    }
    static void solve(int i, int j, int h) {
        if (h == 48 || i == 7 && j == 1) {
            if (h == 48)
                cnt++;
            return;
        }
        boolean u = !used[i - 1][j];
        boolean d = !used[i + 1][j];
        boolean l = !used[i][j - 1];
        boolean r = !used[i][j + 1];
        if (u && d && !l && !r || !u && !d && l && r)
            return;
        used[i][j] = true;
        char p = path[h++];
        if (u && only(i - 1, j)) {
            if (p == 'U' || p == '?')
                solve(i - 1, j, h);
            used[i][j] = false;
            return;
        }
        if (d && only(i + 1, j)) {
            if (p == 'D' || p == '?')
                solve(i + 1, j, h);
            used[i][j] = false;
            return;
        }
        if (l && only(i, j - 1)) {
            if (p == 'L' || p == '?')
                solve(i, j - 1, h);
            used[i][j] = false;
            return;
        }
        if (r && only(i, j + 1)) {
            if (p == 'R' || p == '?')
                solve(i, j + 1, h);
            used[i][j] = false;
            return;
        }
        if (u && (p == 'U' || p == '?'))
            solve(i - 1, j, h);
        if (d && (p == 'D' || p == '?'))
            solve(i + 1, j, h);
        if (l && (p == 'L' || p == '?'))
            solve(i, j - 1, h);
        if (r && (p == 'R' || p == '?'))
            solve(i, j + 1, h);
        used[i][j] = false;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        path = br.readLine().toCharArray();
        solve(1, 1, 0);
        System.out.println(cnt);
    }
}
