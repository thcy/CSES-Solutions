// https://cses.fi/problemset/task/1090
// Ferris Wheel
import java.io.*;
import java.util.*;

public class CSES1090 {
    static Random rand = new Random();
    static void shuffle(int[] aa, int n) {
        for (int i = 1; i < n; i++) {
            int j = rand.nextInt(i + 1);
            int tmp = aa[i]; aa[i] = aa[j]; aa[j] = tmp;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] aa = new int[n];
        for (int i = 0; i < n; i++)
            aa[i] = Integer.parseInt(st.nextToken());
        shuffle(aa, n);
        Arrays.sort(aa);
        int ans = n;
        for (int i = 0, j = n - 1; i < j; i++) {
            while (i < j && aa[i] + aa[j] > x)
                j--;
            if (i < j) {
                j--;
                ans--;
            }
        }
        System.out.println(ans);
    }
}
