// https://cses.fi/problemset/task/1621
// Distinct Numbers
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1621 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        Integer[] aa = new Integer[n];
        for (int i = 0; i < n; i++)
            aa[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(aa);
        int cnt = 1;
        for (int i = 1; i < n; i++)
            if ((int) aa[i] != aa[i - 1])
                cnt++;
        System.out.println(cnt);
    }
}
