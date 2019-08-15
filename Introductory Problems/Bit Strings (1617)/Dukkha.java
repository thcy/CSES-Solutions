// https://cses.fi/problemset/task/1617
// Bit Strings
// practice with rainboy
import java.io.*;

public class CSES1617 {
    static final int MD = 1000000007;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int a = 1;
        while (n-- > 0)
            a = a * 2 % MD;
        System.out.println(a);
    }
}
