// https://cses.fi/problemset/task/1731
// Word Combinations
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1731 {
    static Random rand = new Random();
    static final int MD = 1000000007;
    static final int P = rand.nextInt(MD - 2) + 2;
    static final int Q = rand.nextInt(MD - 2) + 2;
    static long hash(byte[] cc, int n) {
        long x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            x = (x * P + cc[i]) % MD;
            y = (y * Q + cc[i]) % MD;
        }
        return x * MD + y;
    }
    static int[] aa, bb, pp, qq;
    static long hash2(int i, int j) {
        long x = (aa[j] - (long) aa[i - 1] * pp[j - i + 1]) % MD;
        long y = (bb[j] - (long) bb[i - 1] * qq[j - i + 1]) % MD;
        if (x < 0)
            x += MD;
        if (y < 0)
            y += MD;
        return x * MD + y;
    }
    public static void main(String[] __) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        byte[] cc = br.readLine().getBytes();
        int n = cc.length;
        aa = new int[n + 1];
        bb = new int[n + 1];
        pp = new int[n + 1];
        qq = new int[n + 1];
        aa[0] = bb[0] = 0;
        pp[0] = qq[0] = 1;
        for (int i = 0; i < n; i++) {
            aa[i + 1] = (int) (((long) aa[i] * P + cc[i]) % MD);
            bb[i + 1] = (int) (((long) bb[i] * Q + cc[i]) % MD);
            pp[i + 1] = (int) ((long) pp[i] * P % MD);
            qq[i + 1] = (int) ((long) qq[i] * Q % MD);
        }
        StringTokenizer st = new StringTokenizer(br.readLine());
        HashSet<Integer> hl = new HashSet<>();
        HashSet<Long> hs = new HashSet<>();
        int k = Integer.parseInt(st.nextToken());
        while (k-- > 0) {
            cc = br.readLine().getBytes();
            int l = cc.length;
            if (l <= n) {
                hl.add(l);
                hs.add(hash(cc, l));
            }
        }
        int m = hl.size();
        int[] ll = new int[m];
        m = 0;
        for (Integer l : hl)
            ll[m++] = l;
        Arrays.sort(ll);
        int[] dp = new int[n + 1];
        dp[0] = 1;
        for (int i = 0, j; i < n; i++) {
            int x = dp[i];
            if (x == 0)
                continue;
            for (int h = 0; h < m && (j = i + ll[h]) <= n; h++)
                if (hs.contains(hash2(i + 1, j)))
                    dp[j] = (dp[j] + x) % MD;
        }
        pw.println(dp[n]);
        pw.close();
    }
}
