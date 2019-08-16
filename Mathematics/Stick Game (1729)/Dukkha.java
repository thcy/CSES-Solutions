// https://cses.fi/problemset/task/1729
// Stick Game
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1729 {
    public static void main(String[] __) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out, true);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[] pp = new int[k];
        st = new StringTokenizer(br.readLine());
        for (int h = 0; h < k; h++)
            pp[h] = Integer.parseInt(st.nextToken());
        pp = Arrays.stream(pp).boxed().sorted().mapToInt(i->i).toArray();
        byte[] aa = new byte[n + 1];
        Arrays.fill(aa, (byte) 'L');
        for (int i = 0; i < n; i++)
            if (aa[i] == 'L')
                for (int h = 0, j; h < k && (j = i + pp[h]) <= n; h++)
                    aa[j] = 'W';
        pw.println(new String(aa, 1, n));
    }
}
