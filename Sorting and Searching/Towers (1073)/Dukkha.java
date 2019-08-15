// https://cses.fi/problemset/task/1073
// Towers
import java.io.*;
import java.util.*;

public class CSES1073 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(st.nextToken());
            Map.Entry<Integer, Integer> entry = mp.higherEntry(a);
            if (entry == null)
                cnt++;
            else {
                int key = entry.getKey();
                int val = entry.getValue();
                if (val == 1)
                    mp.remove(key);
                else
                    mp.put(key, val - 1);
            }
            mp.put(a, mp.getOrDefault(a, 0) + 1);
        }
        System.out.println(cnt);
    }
}
