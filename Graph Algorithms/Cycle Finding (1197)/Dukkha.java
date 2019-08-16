//https://cses.fi/problemset/task/1197
//Cycle Finding
//practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1197 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] aa = new int[m];
        int[] bb = new int[m];
        int[] cc = new int[m];
        for (int h = 0; h < m; h++) {
            st = new StringTokenizer(br.readLine());
            aa[h] = Integer.parseInt(st.nextToken()) - 1;
            bb[h] = Integer.parseInt(st.nextToken()) - 1;
            cc[h] = Integer.parseInt(st.nextToken());
        }
        long[] dd = new long[n];
        int[] pp = new int[n];
        boolean[] used = new boolean[n];
        for (int r = 0; r < n; r++)
            for (int h = 0; h < m; h++) {
                int a = aa[h], b = bb[h], c = cc[h];
                long d = dd[a] + c;
                if (dd[b] > d) {
                    dd[b] = d;
                    pp[b] = a;
                    if (r == n - 1) {
                        while (!used[b]) {
                            used[b] = true;
                            b = pp[b];
                        }
                        System.out.println("YES");
                        ArrayList<Integer> list = new ArrayList<>();
                        while (used[b]) {
                            used[b] = false;
                            list.add(b);
                            b = pp[b];
                        }
                        list.add(b);
                        StringBuilder sb = new StringBuilder();
                        for (int i = list.size() - 1; i >= 0; i--)
                            sb.append((list.get(i) + 1) + " ");
                        System.out.println(sb);
                        return;
                    }
                }
            }
        System.out.println("NO");
    }
}
