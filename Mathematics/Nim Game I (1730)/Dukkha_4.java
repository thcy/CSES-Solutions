// https://cses.fi/problemset/task/1730
// Nim Game I
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1730 {
    public static void main(String[] __) {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int x = 0;
            while (n-- > 0)
                x ^= sc.nextInt();
            pw.println(x == 0 ? "second" : "first");
        }
        pw.close();
    }
}
