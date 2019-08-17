// https://cses.fi/problemset/task/1110
// Minimal Rotation
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1110 {
    // https://en.wikipedia.org/wiki/Lexicographically_minimal_string_rotation
    static String booth(char[] bb) {
        int n = bb.length;
        bb = Arrays.copyOf(bb, n + n);
        for (int i = 0; i < n; i++)
            bb[n + i] = bb[i];
        int[] ff = new int[n + n];
        Arrays.fill(ff, -1);
        int k = 0;
        for (int j = 1; j < n + n; j++) {
            int i = ff[j - k - 1] + 1;
            while (bb[j] != bb[i + k]) {
                if (bb[j] < bb[i + k])
                    k = j - i;
                if (i == 0) {
                    i--;
                    break;
                }
                i = ff[i - 1] + 1;
            }
            ff[j - k] = i;
        }
        return new String(bb, k, n);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] cc = br.readLine().toCharArray();
        System.out.println(booth(cc));
    }
}
