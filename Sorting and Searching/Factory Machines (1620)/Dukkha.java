// https://cses.fi/problemset/task/1620
// Factory Machines
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1620 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] aa = new int[n];
        for (int i = 0; i < n; i++)
            aa[i] = Integer.parseInt(st.nextToken());
        long lower = 0, upper = (long) 2e18;
        while (upper - lower > 1) {
            long t = (lower + upper) / 2;
            long m = 0;
            for (int i = 0; i < n; i++)
                if ((m += t / aa[i]) >= k)
                    break;
            if (m >= k)
                upper = t;
            else
                lower = t;
        }
        System.out.println(upper);
    }
}
