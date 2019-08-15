// https://cses.fi/problemset/task/1074
// Sticks
import java.io.*;
import java.util.*;

public class CSES1074 {
    static Random rand = new Random();
    static void shuffle(int[] aa, int n) {
        for (int i = 1; i < n; i++) {
            int j = rand.nextInt(i + 1);
            int tmp = aa[i]; aa[i] = aa[j]; aa[j] = tmp;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] aa = new int[n];
        for (int i = 0; i < n; i++)
            aa[i] = Integer.parseInt(st.nextToken());
        shuffle(aa, n);
        Arrays.sort(aa);
        int a = aa[n / 2];
        long ans = 0;
        for (int i = 0; i < n; i++)
            ans += Math.abs(aa[i] - a);
        System.out.println(ans);
    }
}
