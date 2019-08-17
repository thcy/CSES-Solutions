// https://cses.fi/problemset/task/1142
// Advertisement
import java.io.*;
import java.util.*;

public class CSES1142 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] aa = new int[1 + n + 1];
        for (int i = 1; i <= n; i++)
            aa[i] = Integer.parseInt(st.nextToken());
        int[] stack = new int[1 + n];
        int cnt = 0;
        stack[cnt++] = 0;
        int[] ll = new int[1 + n];
        for (int i = 1; i <= n; i++) {
            while (cnt > 0 && aa[stack[cnt - 1]] >= aa[i])
                cnt--;
            ll[i] = stack[cnt - 1];
            stack[cnt++] = i;
        }
        cnt = 0;
        stack[cnt++] = n + 1;
        int[] rr = new int[1 + n];
        for (int i = n; i >= 1; i--) {
            while (cnt > 0 && aa[stack[cnt - 1]] >= aa[i])
                cnt--;
            rr[i] = stack[cnt - 1];
            stack[cnt++] = i;
        }
        long ans = 0;
        for (int i = 1; i <= n; i++)
            ans = Math.max(ans, (long) (rr[i] - ll[i] - 1) * aa[i]);
        System.out.println(ans);
    }
}
