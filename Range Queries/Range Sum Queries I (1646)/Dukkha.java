// https://cses.fi/problemset/task/1646
// Range Sum Queries I
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1646 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long[] aa = new long[n];
        long a = 0;
        for (int i = 0; i < n; i++)
            aa[i] = a += Integer.parseInt(st.nextToken());
        while (q-- > 0) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken()) - 1;
            int r = Integer.parseInt(st.nextToken()) - 1;
            pw.println(aa[r] - (l == 0 ? 0 : aa[l - 1]));
        }
        pw.close();
    }
}
