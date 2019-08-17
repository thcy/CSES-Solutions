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
        int[] ff = new int[m];
        ff[0] = -1;
        for (int j = 1; j < m; j++) {
            int i = ff[j - 1] + 1;
            while (bb[i] != bb[j]) {
                if (i == 0) {
                    i = -1;
                    break;
                }
                i = ff[i - 1] + 1;
            }
            ff[j] = i;
        }
        int[][] dd = new int[m + 1][A];
        for (int j = 0; j <= m; j++)
            for (int a = 0; a < A; a++)
                if (j < m && bb[j] == a + 'a')
                    dd[j][a] = j + 1;
                else
                    dd[j][a] = j == 0 ? 0 : dd[ff[j - 1] + 1][a];
        int cnt = 0;
        for (int i = 0, j = 0; i < n; i++) {
            int a = aa[i] - 'a';
            j = dd[j][a];
            if (j == m)
                cnt++;
        }
        println(cnt);
    }
}
