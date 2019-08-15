// https://cses.fi/problemset/task/1643
// Maximum Subarray Sum
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1643 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] aa = new int[n];
        for (int i = 0; i < n; i++)
            aa[i] = Integer.parseInt(st.nextToken());
        long max = Long.MIN_VALUE, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += aa[i];
            if (max < sum)
                max = sum;
            if (sum < 0)
                sum = 0;
        }
        System.out.println(max);
    }
}
