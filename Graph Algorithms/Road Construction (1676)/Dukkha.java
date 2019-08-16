// https://cses.fi/problemset/task/1676
// Road Construction
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1676 {
    static int[] dsu;
    static int find(int i) {
        return dsu[i] < 0 ? i : (dsu[i] = find(dsu[i]));
    }
    static int join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j)
            return 0;
        if (dsu[i] < dsu[j]) {
            int tmp = i; i = j; j = tmp;
        }
        dsu[j] += dsu[i];
        dsu[i] = j;
        return -dsu[j];
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        dsu = new int[n];
        Arrays.fill(dsu, -1);
        int c_ = 1;
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken()) - 1;
            int j = Integer.parseInt(st.nextToken()) - 1;
            int c = join(i, j);
            if (c != 0) {
                n--;
                if (c_ < c)
                    c_ = c;
            }
            pw.println(n + " " + c_);
        }
        pw.close();
    }
}
