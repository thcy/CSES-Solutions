// https://cses.fi/problemset/task/1652
// Forest Queries
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1652 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        char[][] cc = new char[n][n];
        for (int i = 0; i < n; i++)
            br.readLine().getChars(0, n, cc[i], 0);
        int[][] aa = new int[n + 1][n + 1];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (cc[i][j] == '*')
                    aa[i + 1][j + 1]++;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                aa[i][j] += aa[i][j - 1];
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= n; i++)
                aa[i][j] += aa[i - 1][j];
        while (q-- > 0) {
            st = new StringTokenizer(br.readLine());
            int il = Integer.parseInt(st.nextToken());
            int jl = Integer.parseInt(st.nextToken());
            int ir = Integer.parseInt(st.nextToken());
            int jr = Integer.parseInt(st.nextToken());
            pw.println(aa[ir][jr] - aa[il - 1][jr] - aa[ir][jl - 1] + aa[il - 1][jl - 1]);
        }
        pw.close();
    }
}
