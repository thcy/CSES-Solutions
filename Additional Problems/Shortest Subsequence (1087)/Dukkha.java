// https://cses.fi/problemset/task/1087
// Subsequence
import java.io.*;

public class CSES1087 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] cc = br.readLine().toCharArray();
        int n = cc.length, k = 0, a, c, g, t;
        char x;
        a = c = g = t = -1;
        for (int i = 0; i < n; i++) {
            x = cc[i];
            if (x == 'A')
                a = i;
            else if (x == 'C')
                c = i;
            else if (x == 'G')
                g = i;
            else
                t = i;
            if (a != -1 && c != -1 && g != -1 && t != -1) {
                cc[k++] = x;
                a = c = g = t = -1;
            }
        }
        if (a == -1)
            x = 'A';
        else if (c == -1)
            x = 'C';
        else if (g == -1)
            x = 'G';
        else
            x = 'T';
        cc[k++] = x;
        System.out.println(new String(cc, 0, k));
    }
}
