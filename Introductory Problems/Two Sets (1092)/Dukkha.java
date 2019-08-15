// https://cses.fi/problemset/task/1092
// Two Sets
import java.io.*;
import java.util.*;

public class CSES1092 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n % 4 == 1 || n % 4 == 2) {
            System.out.println("NO");
            return;
        }
        System.out.println("YES");
        StringBuilder sb1 = new StringBuilder();
        StringBuilder sb2 = new StringBuilder();
        if (n % 4 == 0) {
            for (int i = 1; i < n + 1 - i; i += 2)
                sb1.append(i + " " + (n + 1 - i) + " ");
            for (int i = 2; i < n + 1 - i; i += 2)
                sb2.append(i + " " + (n + 1 - i) + " ");
        } else {
            sb1.append("1 2 ");
            sb2.append("3 ");
            for (int i = 4; i < n + 4 - i; i += 2)
                sb1.append(i + " " + (n + 4 - i) + " ");
            for (int i = 5; i < n + 4 - i; i += 2)
                sb2.append(i + " " + (n + 4 - i) + " ");
        }
        System.out.println((n + 1) / 2);
        System.out.println(sb1);
        System.out.println(n / 2);
        System.out.println(sb2);
    }
}
