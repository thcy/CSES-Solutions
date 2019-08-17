// https://cses.fi/problemset/task/1113
// String Transform
// practice with rainboy
import java.io.*;

public class CSES1113 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] cc = br.readLine().toCharArray();
        int[] kk = new int[26];
        int n = cc.length - 1;
        for (int i = 0; i <= n; i++)
            if (cc[i] != '#')
                kk[cc[i] - 'a']++;
        for (int c = 1; c < 26; c++)
            kk[c] += kk[c - 1];
        for (int c = 25; c > 0; c--)
            kk[c] = kk[c - 1];
        kk[0] = 0;
        int[] pp = new int[n + 1];
        for (int i = 0; i <= n; i++)
            if (cc[i] != '#')
                pp[i] = ++kk[cc[i] - 'a'];
        int[] ii = new int[n + 1];
        for (int i = 0; i <= n; i++)
            ii[pp[i]] = i;
        StringBuilder sb = new StringBuilder();
        for (int i = ii[0]; i != 0; i = ii[i])
            sb.append(cc[ii[i]]);
        System.out.println(sb);
    }
}
