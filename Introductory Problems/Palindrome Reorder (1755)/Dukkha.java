// https://cses.fi/problemset/task/1755
// Palindrome Reorder
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1755 {
    static final int A = 26;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] cc = br.readLine().toCharArray();
        int[] kk = new int[A];
        int n = cc.length;
        for (int i = 0; i < n; i++) {
            int a = cc[i] - 'A';
            kk[a]++;
        }
        int odd = -1;
        for (int a = 0; a < A; a++)
            if (kk[a] % 2 == 1) {
                if (odd == -1)
                    odd = a;
                else {
                    System.out.println("NO SOLUTION");
                    return;
                }
            }
        n = 0;
        int k;
        char c;
        for (int a = 0; a < A; a++) {
            if (a == odd)
                continue;
            k = kk[a] / 2;
            c = (char) (a + 'A');
            while (k-- > 0)
                cc[n++] = c;
        }
        if (odd != -1) {
            k = kk[odd];
            c = (char) (odd + 'A');
            while (k-- > 0)
                cc[n++] = c;
        }
        for (int a = A - 1; a >= 0; a--) {
            if (a == odd)
                continue;
            k = kk[a] / 2;
            c = (char) (a + 'A');
            while (k-- > 0)
                cc[n++] = c;
        }
        System.out.println(cc);
    }
}
