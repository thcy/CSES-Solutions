// https://cses.fi/problemset/task/1618
// Trailing Zeros
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1618 {
    static int solve(int n) {
        return n < 5 ? 0 : solve(n / 5) + n / 5;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        System.out.println(solve(n));
    }
}
