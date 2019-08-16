// https://cses.fi/problemset/task/1689
// Knight's Tour
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1689 {
    static int[][] aa = new int[8][8];
    static int[][][] hh = new int[8][8][8];
    static int[][] kk = new int[8][8];
    static int[] di = new int[] { -2, -2, -1, -1, 1, 1, 2, 2 };
    static int[] dj = new int[] { -1, 1, -2, 2, -2, 2, -1, 1 };
    static Random rand = new Random();
    static int count(int i, int j) {
        int k = 0;
        for (int h = 0; h < 8; h++) {
            int i_ = i + di[h];
            int j_ = j + dj[h];
            if (i_ >= 0 && i_ < 8 && j_ >= 0 && j_ < 8)
                k++;
        }
        return k;
    }
    static void init() {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                kk[i][j] = count(i, j);
        int[] dd = new int[8];
        Integer[] hh_ = new Integer[8];
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++) {
                int k = 0;
                for (int h = 0; h < 8; h++) {
                    int i_ = i + di[h];
                    int j_ = j + dj[h];
                    if (i_ >= 0 && i_ < 8 && j_ >= 0 && j_ < 8) {
                        dd[h] = kk[i_][j_];
                        hh_[k++] = h;
                    }
                }
                for (int h = 1; h < k; h++) {
                    int h_ = rand.nextInt(h + 1);
                    int tmp = hh_[h_]; hh_[h_] = hh_[h]; hh_[h] = tmp;
                }
                Arrays.sort(hh_, 0, k, (u, v) -> dd[u] - dd[v]);
                for (int h = 0; h < k; h++)
                    hh[i][j][h] = hh_[h];
            }
    }
    static boolean solve(int i, int j, int m) {
        aa[i][j] = m;
        if (m == 64)
            return true;
        m++;
        int[] hh_ = hh[i][j];
        int k = kk[i][j];
        for (int h = 0; h < k; h++) {
            int i_ = i + di[hh_[h]];
            int j_ = j + dj[hh_[h]];
            if (aa[i_][j_] == 0 && solve(i_, j_, m))
                return true;
        }
        aa[i][j] = 0;
        return false;
    }
    public static void main(String[] args) throws IOException {
        init();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int j1 = Integer.parseInt(st.nextToken()) - 1;
        int i1 = Integer.parseInt(st.nextToken()) - 1;
        solve(i1, j1, 1);
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++)
                pw.print(aa[i][j] + " ");
            pw.println();
        }
        pw.close();
    }
}
