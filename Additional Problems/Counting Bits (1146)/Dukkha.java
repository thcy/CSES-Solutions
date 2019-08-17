// https://cses.fi/problemset/task/1146
// Counting Bits
import java.io.*;

public class CSES1146 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());
        long cnt = 0;
        for (int i = 0; 1L << i <= n; i++) {
            cnt += n >> i + 1 << i;
            if ((n & 1L << i) != 0)
                cnt += (n & (1L << i) - 1) + 1;
        }
        System.out.println(cnt);
    }
}
