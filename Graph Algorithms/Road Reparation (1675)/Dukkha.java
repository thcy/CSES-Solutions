// https://cses.fi/problemset/task/1675
// Road Reparation
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1675 {
    static class E {
        int i, j, w;
        E(int i, int j, int w) {
            this.i = i; this.j = j; this.w = w;
        }
    }
    static int[] dsu;
    static int find(int i) {
        return dsu[i] < 0 ? i : (dsu[i] = find(dsu[i]));
    }
    static boolean join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j)
            return false;
        if (dsu[i] > dsu[j])
            dsu[i] = j;
        else {
            if (dsu[i] == dsu[j])
                dsu[i]--;
            dsu[j] = i;
        }
        return true;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        dsu = new int[n];
        Arrays.fill(dsu, -1);
        E[] ee = new E[m];
        for (int h = 0; h < m; h++) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken()) - 1;
            int j = Integer.parseInt(st.nextToken()) - 1;
            int w = Integer.parseInt(st.nextToken());
            ee[h] = new E(i, j, w);
        }
        Arrays.sort(ee, (e, f) -> e.w - f.w);
        long w = 0;
        for (int h = 0; h < m && n > 1; h++) {
            E e = ee[h];
            if (join(e.i, e.j)) {
                w += e.w;
                n--;
            }
        }
        System.out.println(n == 1 ? w : "IMPOSSIBLE");
    }
}
