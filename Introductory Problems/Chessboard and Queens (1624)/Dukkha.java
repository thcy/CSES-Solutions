// https://cses.fi/problemset/task/1624
// Chessboard and Queens
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1624 {
    static char[][] cc = new char[8][8];
    static boolean[] col = new boolean[8];
    static boolean[] d1 = new boolean[15];
    static boolean[] d2 = new boolean[15];
    static int cnt = 0;
    static void solve(int i) {
        if (i == 8) {
            cnt++;
            return;
        }
        for (int j = 0; j < 8; j++)
            if (cc[i][j] == '.' && !col[j] && !d1[i + j] && !d2[i - j + 7]) {
                col[j] = d1[i + j] = d2[i - j + 7] = true;
                solve(i + 1);
                col[j] = d1[i + j] = d2[i - j + 7] = false;
            }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 8; i++)
            br.readLine().getChars(0, 8, cc[i], 0);
        solve(0);
        System.out.println(cnt);
    }
}
