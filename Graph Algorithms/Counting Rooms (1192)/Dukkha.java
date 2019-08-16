// practice with rainboy
// https://cses.fi/problemset/task/1192
// Counting Rooms
import java.io.*;
import java.util.*;

public class CSES1192 {
    static int[] dsu;
    static int find(int i) {
        return dsu[i] < 0 ? i : (dsu[i] = find(dsu[i]));
    }
    static void join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j)
            return;
        if (dsu[i] > dsu[j])
            dsu[i] = j;
        else {
            if (dsu[i] == dsu[j])
                dsu[i]--;
            dsu[j] = i;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        char[][] cc = new char[n][m];
        for (int i = 0; i < n; i++)
            br.readLine().getChars(0, m, cc[i], 0);
        dsu = new int[n * m];
        Arrays.fill(dsu, -1);
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                if (cc[i][j - 1] == '.' && cc[i][j] == '.')
                    join(i * m + j - 1, i * m + j);
        for (int i = 1; i < n; i++)
            for (int j = 0; j < m; j++)
                if (cc[i - 1][j] == '.' && cc[i][j] == '.')
                    join((i - 1) * m + j, i * m + j);
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (cc[i][j] == '.' && dsu[i * m + j] < 0)
                    cnt++;
        System.out.println(cnt);
    }
}
