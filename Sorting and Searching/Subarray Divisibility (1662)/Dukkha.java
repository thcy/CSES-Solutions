// https://cses.fi/problemset/task/1662
// Subarray Divisibility
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1662 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] kk = new int[n];
        kk[0] = 1;
        st = new StringTokenizer(br.readLine());
        for (int i = 0, a = 0; i < n; i++) {
            a += Integer.parseInt(st.nextToken());
            a %= n;
            if (a < 0)
                a += n;
            kk[a]++;
        }
        long ans = 0;
        for (int a = 0; a < n; a++) {
            int k = kk[a];
            ans += (long) k * (k - 1) / 2;
        }
        System.out.println(ans);
    }
}
