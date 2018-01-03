import java.util.Scanner;
import java.util.Calendar;
import java.util.GregorianCalendar;

class Main {

    public static void main(String[] args) {
        
        Scanner in = new Scanner(System.in);
        while(in.hasNext()) {
            int t = in.nextInt();
            int d = in.nextInt();
            int m = in.nextInt();
            int y = in.nextInt();

            if(t + d + m + y == 0) break;

            Calendar c = new GregorianCalendar(y, m-1, d);
            c.add(Calendar.DAY_OF_MONTH, t);

            System.out.printf("%d %d %d\n", c.get(Calendar.DAY_OF_MONTH), c.get(Calendar.MONTH) + 1, c.get(Calendar.YEAR));
        }
    }
}
