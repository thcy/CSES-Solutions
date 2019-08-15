// https://cses.fi/problemset/task/1631
// Reading Books
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1631 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        long sum = 0, max = 0;
        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(st.nextToken());
            if (max < a)
                max = a;
            sum += a;
        }
        System.out.println(Math.max(max + max, sum));
    }
}
