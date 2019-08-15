// https://cses.fi/problemset/task/1141
// Playlist
import java.io.*;
import java.util.*;

public class CSES1141 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] aa = new int[n];
        for (int i = 0; i < n; i++)
            aa[i] = Integer.parseInt(st.nextToken());
        Integer[] ii = new Integer[n];
        for (int i = 0; i < n; i++)
            ii[i] = i;
        Arrays.sort(ii, (i, j) -> aa[i] - aa[j] != 0 ? aa[i] - aa[j] : i - j);
        int[] pp = new int[n];
        Arrays.fill(pp, -1);
        for (int i = 1; i < n; i++)
            if (aa[ii[i]] == aa[ii[i - 1]])
                pp[ii[i]] = ii[i - 1];
        int p = -1, ans = 0;
        for (int i = 0; i < n; i++) {
            if (pp[i] != -1)
                p = Math.max(p, pp[i]);
            ans = Math.max(ans, i - p);
        }
        System.out.println(ans);
    }
}
