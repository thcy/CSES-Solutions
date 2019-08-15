// https://cses.fi/problemset/task/1644
// Maximum Subarray Sum II
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1644 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long[] xx = new long[n + 1];
        long x = 0;
        for (int i = 1; i <= n; i++)
            xx[i] = x += Integer.parseInt(st.nextToken());
        int[] qq = new int[n];
        int head = 0, cnt = 0;
        x = (long) -3e14;
        for (int i = a; i <= n; i++) {
            while (cnt > 0 && xx[qq[head + cnt - 1]] >= xx[i - a])
                cnt--;
            qq[head + cnt++] = i - a;
            x = Math.max(x, xx[i] - xx[qq[head]]);
            if (qq[head] == i - b) {
                head++; cnt--;
            }
        }
        System.out.println(x);
    }
}
