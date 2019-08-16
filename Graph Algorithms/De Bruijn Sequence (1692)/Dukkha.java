// https://cses.fi/problemset/task/1692
// De Bruijn Sequence
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1692 {
    static class L {
        L next;
        int v;
        L(int v) {
            this.v = v;
        }
    }
    static int mask;
    static char[] hh;
    static void hierholzer(L e) {
        L f = e.next;
        int v = e.v;
        while (hh[v] < 2) {
            v = (v << 1 | hh[v]++) & mask;
            e = e.next = new L(v);
        }
        e.next = f;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int k = Integer.parseInt(br.readLine());
        if (k == 1) {
            System.out.println("01");
            return;
        }
        int n = 1 << k - 1;
        hh = new char[n];
        mask = n - 1;
        L e_ = new L(0);
        char[] aa = new char[k - 1 + (1 << k)];
        int i = 0;
        while (i < k - 2)
            aa[i++] = '0';
        for (L e = e_; e != null; e = e.next) {
            aa[i++] = (char) ('0' + (e.v & 1));
            hierholzer(e);
        }
        System.out.println(aa);
    }
}
