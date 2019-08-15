// https://cses.fi/problemset/task/1069
// Repetitions
import java.io.*;

public class CSES1069 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] cc = br.readLine().toCharArray();
        int n = cc.length;
        int ans = 1, cnt = 1;
        for (int i = 1; i < n; i++) {
            if (cc[i] == cc[i - 1])
                cnt++;
            else
                cnt = 1;
            if (ans < cnt)
                ans = cnt;
        }
        System.out.println(ans);
    }
}
