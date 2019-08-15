// https://cses.fi/problemset/task/1645
// Nearest Smaller Values
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1645 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] aa = new int[n + 1];
        for (int i = 1; i <= n; i++)
            aa[i] = Integer.parseInt(st.nextToken());
        int[] stack = new int[n + 1];
        int cnt = 0;
        stack[cnt++] = 0;
        for (int i = 1; i <= n; i++) {
            int h = 0;
            while (aa[h = stack[cnt - 1]] >= aa[i])
                cnt--;
            pw.print(h + " ");
            stack[cnt++] = i;
        }
        pw.println();
        pw.close();
    }
}
