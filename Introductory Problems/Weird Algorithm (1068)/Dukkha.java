// https://cses.fi/problemset/task/1068
// Weird Algorithm
import java.io.*;

public class CSES1068 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (n != 1) {
            sb.append(n + " ");
            if (n % 2 == 0)
                n /= 2;
            else
                n = n * 3 + 1;
        }
        sb.append(1);
        System.out.println(sb);
    }
}
