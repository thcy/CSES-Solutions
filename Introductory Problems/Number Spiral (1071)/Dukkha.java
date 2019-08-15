// https://cses.fi/problemset/task/1071
// Number Spiral
import java.io.*;
import java.util.*;

public class CSES1071 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken());
            int j = Integer.parseInt(st.nextToken());
            int a = Math.max(i, j);
            long n;
            if (a % 2 == 1)
                n = (long) a * a - (i - 1) - (a - j);
            else
                n = (long) (a - 1) * (a - 1) + (i - 0) + (a - j);
            pw.println(n);
        }
        pw.close();
    }
}
