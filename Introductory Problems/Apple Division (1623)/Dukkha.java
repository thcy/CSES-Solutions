// https://cses.fi/problemset/task/1623
// Apple Division
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1623 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] aa = new int[n];
        long sum = 0;
        for (int i = 0; i < n; i++)
            sum += aa[i] = Integer.parseInt(st.nextToken());
        long d_ = sum;
        for (int b = 1; b < 1 << n; b += 2) {
            long a = 0;
            for (int i = 0; i < n; i++)
                if ((b & 1 << i) != 0)
                    a += aa[i];
            long d = Math.abs(sum - a - a);
            if (d_ > d)
                d_ = d;
        }
        System.out.println(d_);
    }
}
