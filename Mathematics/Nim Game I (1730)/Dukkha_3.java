// https://cses.fi/problemset/task/1730
// Nim Game I
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1730 {
    public static void main(String[] __) throws IOException {
        Scanner_ sc = new Scanner_();
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
    static class Scanner_ {
        int k, l;
        byte[] bb = new byte[1 << 15];
        byte read() {
            if (k >= l) {
                k = 0;
                try {
                    if ((l = System.in.read(bb)) < 0)
                        return -1;
                } catch (IOException e) { return -1; }
            }
            return bb[k++];
        }
        int nextInt() {
            byte b = 0;
            while (b <= 32)
                b = read();
            int n = 0;
            while (b > 32) {
                n = n * 10 + b - '0';
                b = read();
            }
            return n;
        }
    }
}
