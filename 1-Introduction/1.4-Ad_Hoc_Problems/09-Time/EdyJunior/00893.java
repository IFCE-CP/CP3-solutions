import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        boolean flag = true;

        while (flag) {
            int[] d = new int[4];
            for (int i = 0; i < 4; i++) { d[i] = sc.nextInt(); }

            if (d[0] + d[1] + d[2] + d[3] == 0) { flag = false; }
            else {
                Calendar gc = new GregorianCalendar(d[3], d[2] - 1, d[1]);
                gc.add(gc.DAY_OF_MONTH, d[0]);
                System.out.printf("%d %d %d\n", gc.get(gc.DAY_OF_MONTH), gc.get(gc.MONTH) + 1, gc.get(gc.YEAR));
            }
        }
    }
}