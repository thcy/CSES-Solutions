// https://cses.fi/problemset/task/1084
// Apartments
import java.io.*;
import java.util.*;

public class CSES1084 {
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
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] aa = new int[n];
        for (int i = 0; i < n; i++)
            aa[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] bb = new int[m];
        for (int j = 0; j < m; j++)
            bb[j] = Integer.parseInt(st.nextToken());
        shuffle(aa, n);
        Arrays.sort(aa);
        shuffle(bb, m);
        Arrays.sort(bb);
        int cnt = 0;
        for (int i = 0, j = 0; i < n && j < m; )
            if (aa[i] >= bb[j] - k && aa[i] <= bb[j] + k) {
                cnt++;
                i++;
                j++;
            } else if (aa[i] < bb[j] - k)
                i++;
            else
                j++;
        System.out.println(cnt);
    }
}
