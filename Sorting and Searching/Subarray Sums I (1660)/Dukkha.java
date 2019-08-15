// https://cses.fi/problemset/task/1660
// Subarray Sums I
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1660 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] aa = new int[n];
        for (int i = 0; i < n; i++)
            aa[i] = Integer.parseInt(st.nextToken());
        int cnt = 0;
        for (int i = 0, j = 0, a = 0; i < n; i++) {
            while (j < n && a < x)
                a += aa[j++];
            if (a == x)
                cnt++;
            a -= aa[i];
        }
        System.out.println(cnt);
    }
}
