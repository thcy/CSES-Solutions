// https://cses.fi/problemset/task/1751
// Planets Cycles
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1751 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] aa = new int[n];
        for (int i = 0; i < n; i++)
            aa[i] = Integer.parseInt(st.nextToken()) - 1;
        int[] cc = new int[n];
        Arrays.fill(cc, -1);
        int[] dd = new int[n];
        int[] qq = new int[n];
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (cc[i] != -1)
                continue;
            int c, d = 0;
            int j = i;
            while (cc[j] == -1) {
                cc[j] = -2;
                d++;
                j = aa[j];
            }
            if (cc[j] == -2) {
                c = cnt++;
                int q = 0;
                while (cc[j] == -2) {
                    cc[j] = c;
                    q++;
                    j = aa[j];
                }
                qq[c] = q;
                d -= q;
            } else {
                c = cc[j];
                d += dd[j];
            }
            j = i;
            while (cc[j] == -2) {
                cc[j] = c;
                dd[j] = d--;
                j = aa[j];
            }
        }
        for (int i = 0; i < n; i++)
            pw.print(dd[i] + qq[cc[i]] + " ");
        pw.println();
        pw.close();
    }
}
