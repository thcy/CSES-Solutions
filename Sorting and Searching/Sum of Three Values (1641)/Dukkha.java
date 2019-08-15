// https://cses.fi/problemset/task/1641
// Sum of Three Values
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1641 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] aa = new int[n];
        Integer[] ii = new Integer[n];
        for (int i = 0; i < n; i++) {
            aa[i] = Integer.parseInt(st.nextToken());
            ii[i] = i;
        }
        Arrays.sort(ii, (i, j) -> aa[i] - aa[j]);
        for (int k = 2; k < n; k++)
            for (int i = 0, j = k - 1; i < j; i++) {
                long a = 0, b = aa[ii[k]];
                while (i < j && (a = aa[ii[i]] + aa[ii[j]] + b) > x)
                    j--;
                if (i < j && a == x) {
                    System.out.println((ii[i] + 1) + " " + (ii[j] + 1) + " " + (ii[k] + 1));
                    return;
                }
            }
        System.out.println("IMPOSSIBLE");
    }
}
