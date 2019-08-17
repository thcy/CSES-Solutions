// https://cses.fi/problemset/task/1134
// Prüfer Code
// practice with rainboy
import java.io.*;
import java.util.*;

public class CSES1134 {
    public static void main(String[] args) throws IOException {
        _Scanner sc = new _Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int[] aa = new int[n - 2];
        for (int i = 0; i < n - 2; i++)
            aa[i] = sc.nextInt() - 1;
        int[] last = new int[n];
        Arrays.fill(last, -1);
        for (int i = 0; i < n - 2; i++)
            last[aa[i]] = i;
        TreeSet<Integer> pq = new TreeSet<>();
        for (int a = 0; a < n; a++)
            if (last[a] == -1)
                pq.add(a);
        for (int i = 0; i < n - 2; i++) {
            int a = aa[i];
            int b = pq.pollFirst();
            pw.println((a + 1) + " " + (b + 1));
            if (last[a] == i)
                pq.add(a);
        }
        int a = pq.pollFirst();
        int b = pq.pollFirst();
        pw.println((a + 1) + " " + (b + 1));
        pw.close();
    }
    static class _Scanner {
        InputStream is;
        _Scanner(InputStream is) {
            this.is = is;
        }
        byte[] bb = new byte[1 << 15];
        int k, l;
        byte getc() throws IOException {
            if (k >= l) {
                k = 0;
                l = is.read(bb); //if (l < 0) return -1;
            }
            return bb[k++];
        }
        byte skip() throws IOException {
            byte b;
            while ((b = getc()) <= 32)
                ;
            return b;
        }
        String next() throws IOException {
            StringBuilder sb = new StringBuilder();
            for (byte b = skip(); b > 32; b = getc())
                sb.append((char) b);
            return sb.toString();
        }
        int nextInt() throws IOException {
            int n = 0;
            for (byte b = skip(); b > 32; b = getc())
                n = n * 10 + b - '0';
            return n;
        }
    }
}
