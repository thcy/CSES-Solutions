// https://cses.fi/problemset/task/1756
// Edge Directions
// practice with rainboy
import java.io.*;

public class CSES1756 extends PrintWriter {
    CSES1756() { super(System.out); } byte[] __; int $;
    { try { __ = System.in.readAllBytes(); } catch (IOException e) {} }
    int nextInt() {
        while ($ < __.length && __[$] < 33) $++;
        boolean minus = __[$] == '-'; if (minus) $++;
        int a = 0;
        while ($ < __.length && __[$] > 32) a = a * 10 + __[$++] - '0';
        return minus ? -a : a;
    }
    public static void main(String[] __) { new CSES1756().main(); }
    
    void main() {
        int m = nextInt(); m = nextInt();
        while (m-- > 0) {
            int a = nextInt(), b = nextInt();
            println(a < b ? a + " " + b : b + " " + a);
        }
        flush();
    }
}
