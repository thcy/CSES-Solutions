// https://cses.fi/problemset/task/1145
// Increasing Subsequence
import java.io.*;
import java.util.*;

public class CSES1145 {
    static int[] tt;
    static void update(int i, int n, int x) {
        while (i < n) {
            tt[i] = Math.max(tt[i], x);
            i |= i + 1;
        }
    }
    static int query(int i) {
        int ans = 0;
        while (i >= 0) {
            ans = Math.max(ans, tt[i]);
            i &= i + 1;
            i--;
        }
        return ans;
    }
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
        Arrays.sort(ii, (i, j) -> aa[i] != aa[j] ? aa[i] - aa[j] : j - i);
        tt = new int[n];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = query(ii[i]) + 1;
            ans = Math.max(ans, cnt);
            update(ii[i], n, cnt);
        }
        System.out.println(ans);
    }
}
