// https://cses.fi/problemset/task/1070
// Permutations
import java.io.*;

public class CSES1070 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n == 2 || n == 3) {
            System.out.println("NO SOLUTION");
            return;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 2; i <= n; i += 2)
            sb.append(i + " ");
        for (int i = 1; i <= n; i += 2)
            sb.append(i + " ");
        System.out.println(sb);
    }
}
