// https://cses.fi/problemset/task/1072
// Two Knights
import java.io.*;

public class CSES1072 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = Integer.parseInt(br.readLine());
        for (int k = 1; k <= n; k++) {
            int k2 = k * k;
            pw.println((long) k2 * (k2 - 1) / 2 - (k - 1) * (k - 2) * 4);
        }
        pw.close();
    }
}
