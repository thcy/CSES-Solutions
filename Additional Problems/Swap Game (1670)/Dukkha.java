// https://cses.fi/problemset/task/1670
// Swap Game
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1670 extends PrintWriter {
    CSES1670() {
        super(System.out, true);
        try { _bb = System.in.readAllBytes(); } catch (IOException e) {}
    }
    byte[] _bb; int _i;
    byte getc() {
        int n = _bb.length;
        while (_i < n && _bb[_i] < 33) _i++;
        return _bb[_i++];
    }
    public static void main(String[] __) { new CSES1670().main(); }
    
    int[] ff = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
    byte[] cc = new byte[9];
    int rank() {
        int k = 0;
        for (int i = 0; i < 9; i++) {
            int l = 0;
            for (int j = i + 1; j < 9; j++)
                if (cc[j] < cc[i])
                    l++;
            k += l * ff[8 - i];
        }
        return k;
    }
    void inc() {
        int i = 7;
        while (cc[i] > cc[i + 1])
            i--;
        int j = i + 1;
        while (j + 1 < 9 && cc[j + 1] > cc[i])
            j++;
        byte tmp = cc[i]; cc[i] = cc[j]; cc[j] = tmp;
        for (i++, j = 8; i < j; i++, j--) {
            tmp = cc[i]; cc[i] = cc[j]; cc[j] = tmp;
        }
    }
    int[][] aa;
    void link(int i, int h, int u, int v) {
        byte tmp;
        tmp = cc[u]; cc[u] = cc[v]; cc[v] = tmp;
        aa[i][h] = rank();
        tmp = cc[u]; cc[u] = cc[v]; cc[v] = tmp;
    }
    void main() {
        for (int h = 0; h < 9; h++)
            cc[h] = (byte) (getc() - '1');
        int t = rank();
        if (t == 0) {
            println(0);
            return;
        }
        for (int h = 0; h < 9; h++)
            cc[h] = (byte) h;
        int n = ff[9];
        aa = new int[n][12];
        for (int i = 0; i < n; i++) {
            int h = 0;
            for (int r = 0; r < 3; r++)
                for (int c = 0; c < 3; c++) {
                    int u = r * 3 + c;
                    if (r < 2)
                        link(i, h++, u, u + 3);
                    if (c < 2)
                        link(i, h++, u, u + 1);
                }
            if (i + 1 < n)
                inc();
        }
        int[] dd = new int[n];
        Arrays.fill(dd, n);
        dd[0] = 0;
        int[] qq = new int[n];
        int head = 0, cnt = 0;
        qq[head + cnt++] = 0;
        while (cnt > 0) {
            int i = qq[head++]; cnt--;
            int d = dd[i] + 1;
            for (int h = 0; h < 12; h++) {
                int j = aa[i][h];
                if (dd[j] > d) {
                    dd[j] = d;
                    if (j == t) {
                        println(d);
                        return;
                    }
                    qq[head + cnt++] = j;
                }
            }
        }
    }
}
