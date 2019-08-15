// https://cses.fi/problemset/task/1754
// Coin Piles
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1754 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            pw.println((a + b) % 3 == 0 && a <= b * 2 && b <= a * 2 ? "YES" : "NO");
        }
        pw.close();
    }
}
