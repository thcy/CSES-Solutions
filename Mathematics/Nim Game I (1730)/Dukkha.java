// https://cses.fi/problemset/task/1730
// Nim Game I
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1730 {
    public static void main(String[] __) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            int x = 0;
            while (n-- > 0)
                x ^= Integer.parseInt(st.nextToken());
            pw.println(x == 0 ? "second" : "first");
        }
        pw.close();
    }
}
