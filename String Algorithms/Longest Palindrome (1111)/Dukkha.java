// https://cses.fi/problemset/task/1111
// Longest Palindrome
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1111 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] cc = br.readLine().toCharArray();
        int n = cc.length;
        int m = n * 2 + 1;
        char[] aa = new char[m];
        Arrays.fill(aa, '_');
        for (int i = 0; i < n; i++)
            aa[i * 2 + 1] = cc[i];
        int[] rr = new int[m];
        int o = 0, x = 1;
        rr[0] = x - o;
        for (int i = 1; i < m; i++)
            if (o + o - i >= 0 && rr[o + o - i] < x - i)
                rr[i] = rr[o + o - i];
            else {
                o = i;
                if (x < i + 1)
                    x = i + 1;
                while (x < m && o + o - x >= 0 && aa[o + o - x] == aa[x])
                    x++;
                rr[i] = x - o;
            }
        int i_ = 0;
        for (int i = 1; i < m; i++)
            if (rr[i_] < rr[i])
                i_ = i;
        int r_ = rr[i_];
        StringBuilder sb = new StringBuilder();
        for (int i = i_ - r_ + 2; i <= i_ + r_ - 2; i += 2)
            sb.append(aa[i]);
        System.out.println(sb);
    }
}
