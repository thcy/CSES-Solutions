// https://cses.fi/problemset/task/1666
// Building Roads
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1666 {
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
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        dsu = new int[n];
        Arrays.fill(dsu, -1);
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken()) - 1;
            int j = Integer.parseInt(st.nextToken()) - 1;
            join(i, j);
        }
        int k = 0;
        for (int i = 0; i < n; i++)
            if (dsu[i] < 0)
                dsu[k++] = i + 1;
        pw.println(k - 1);
        for (int i = 1; i < k; i++)
            pw.println(dsu[i - 1] + " " + dsu[i]);
        pw.close();
    }
}
