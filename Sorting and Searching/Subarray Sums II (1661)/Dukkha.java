// https://cses.fi/problemset/task/1661
// Subarray Sums II
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1661 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long[] aa = new long[n + 1];
        Integer[] ii = new Integer[n + 1];
        aa[0] = 0;
        ii[0] = 0;
        for (int i = 1; i <= n; i++) {
            aa[i] = aa[i - 1] + Long.parseLong(st.nextToken());
            ii[i] = i;
        }
        Arrays.sort(ii, (i, j) -> (long) aa[i] == aa[j] ? i - j : aa[i] < aa[j] ? -1 : 1);
        long cnt = 0;
        for (int h = 0, i = 0, j = 0; h <= n; h++) {
            long a = aa[ii[h]] + x;
            while (i <= n && (aa[ii[i]] < a || aa[ii[i]] == a && ii[i] <= ii[h]))
                i++;
            while (j <= n && aa[ii[j]] <= a)
                j++;
            cnt += j - i;
        }
        System.out.println(cnt);
    }
}
