// https://cses.fi/problemset/task/1157
// Number Grid
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1157 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        System.out.println(x - 1 ^ y - 1);
    }
}
