// https://cses.fi/problemset/task/1094
// Increasing Array
import java.io.*;
import java.util.*;

public class CSES1094 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        long ans = 0;
        for (int i = 1; i < n; i++) {
            int b = Integer.parseInt(st.nextToken());
            a = Math.max(a, b);
            ans += a - b;
        }
        System.out.println(ans);
    }
}
