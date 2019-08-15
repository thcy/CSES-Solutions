// https://cses.fi/problemset/task/1085
// Array Division
import java.io.*;
import java.util.*;

public class CSES1085 {
    static int count(int[] aa, int n, long x) {
        long a = 0;
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (a + aa[i] > x) {
                a = 0;
                k++;
            }
            a += aa[i];
        }
        return k + 1;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] aa = new int[n];
        int max = 0;
        long sum = 0;
        for (int i = 0; i < n; i++) {
            aa[i] = Integer.parseInt(st.nextToken());
            max = Math.max(max, aa[i]);
            sum += aa[i];
        }
        long lower = max - 1, upper = sum;
        while (upper - lower > 1) {
            long x = (lower + upper) / 2;
            if (count(aa, n, x) <= k)
                upper = x;
            else
                lower = x;
        }
        System.out.println(upper);
    }
}
