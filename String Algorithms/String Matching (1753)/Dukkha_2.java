// https://cses.fi/problemset/task/1753
// String Matching
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1753 extends PrintWriter {
    CSES1753() {
        super(System.out, true);
        try { _bb = System.in.readAllBytes(); } catch (IOException e) {}
    }
    byte[] _bb; int _i;
    byte[] scan() {
        int n = _bb.length;
        while (_i < n && _bb[_i] < 33) _i++; int i = _i;
        while (_i < n && _bb[_i] > 32) _i++;
        return Arrays.copyOfRange(_bb, i, _i);
    }
    public static void main(String[] __) { new CSES1753().main(); }
    
    final int A = 26;
    void main() {
        byte[] aa = scan();
        byte[] bb = scan();
        int n = aa.length;
        int m = bb.length;
        byte[] cc = Arrays.copyOf(bb, m + 1 + n);
        for (int i = 0; i < n; i++)
            cc[m + 1 + i] = aa[i];
        int[] ff = new int[m + 1 + n];
        ff[0] = -1;
        int cnt = 0;
        for (int j = 1; j < m + 1 + n; j++) {
            int i = ff[j - 1] + 1;
            while (cc[i] != cc[j]) {
                if (i == 0) {
                    i = -1;
                    break;
                }
                i = ff[i - 1] + 1;
            }
            ff[j] = i;
            if (i + 1 == m)
                cnt++;
        }
        println(cnt);
    }
}
