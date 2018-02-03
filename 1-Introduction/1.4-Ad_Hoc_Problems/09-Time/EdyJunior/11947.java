import java.util.*;

public class Main {

    public static void main(String[] args) {

        String[] signs = { "Aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo",
                           "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn" };

        int[][] dates = { {0, 21, 1, 19}, {1, 20, 2, 20},  {2, 21, 3, 20},   {3, 21, 4, 21},
                          {4, 22, 5, 21}, {5, 22, 6, 22},  {6, 23, 7, 21},   {7, 22, 8, 23},
                          {8, 24, 9, 23}, {9, 24, 10, 22}, {10, 23, 11, 22}, {11, 23, 0, 20} };

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), count = 1;

        while (n-- > 0) {
            String line = sc.next();
            int month   = Integer.parseInt(line.substring(0, 2)) - 1;
            int day     = Integer.parseInt(line.substring(2, 4));
            int year    = Integer.parseInt(line.substring(4));
            Calendar d  = new GregorianCalendar(year, month, day);
            
            d.add(d.DATE, 280);
            
            for (int i = 0; i < 12; i++) {
                int[] date = dates[i];
                Calendar start = new GregorianCalendar(d.get(d.YEAR), date[0], date[1]);
                Calendar end   = new GregorianCalendar(d.get(d.YEAR), date[2], date[3]);
                Calendar anotherEnd = end;
                Calendar anotherStart = start;
                if (i == 11) { 
                    anotherEnd.add(anotherEnd.YEAR, 1); 
                    anotherStart.add(anotherStart.YEAR, -1); 
                }
                if ((d.after(start) && d.before(end)) || d.equals(start) || d.equals(end) ||
                    (d.after(start) && d.before(anotherEnd)) || (d.after(anotherStart) && d.before(end))) {
                    System.out.printf("%d %02d/%02d/%d %s\n", count++, d.get(d.MONTH) + 1,
                                                          d.get(d.DAY_OF_MONTH), d.get(d.YEAR),
                                                          signs[i].toLowerCase());
                    break;
                }
            }
        }
    }
}