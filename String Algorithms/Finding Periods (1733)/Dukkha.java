// https://cses.fi/problemset/task/1733
// Finding Periods
// practice with rainboy
import java.io.*;

public class CSES1733 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        byte[] cc = br.readLine().getBytes();
        int n = cc.length;
        int[] zz = new int[n];
        for (int i = 1, l = 0, r = 0; i < n; i++)
            if (zz[i - l] < r - i)
                zz[i] = zz[i - l];
            else {
                l = i;
                if (r < l)
                    r = l;
                while (r < n && cc[r] == cc[r - l])
                    r++;
                zz[i] = r - l;
            }
        PrintWriter pw = new PrintWriter(System.out);
        for (int i = 1; i < n; i++)
            if (zz[i] == n - i)
                pw.print(i + " ");
        pw.println(n);
        pw.close();
    }
}
