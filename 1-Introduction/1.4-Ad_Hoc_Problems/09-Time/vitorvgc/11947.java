import java.util.*;

class Main {

    static String sign(Calendar c) {
        
        int y = c.get(Calendar.YEAR);

        String signs[] = {
            "aquarius", "pisces", "aries", "taurus",
            "gemini", "cancer", "leo", "virgo",
            "libra", "scorpio", "sagittarius", "capricorn"
        };

        Calendar dates[] = {
            new GregorianCalendar(y, 0, 21),  new GregorianCalendar(y, 1, 20),
            new GregorianCalendar(y, 2, 21),  new GregorianCalendar(y, 3, 21),
            new GregorianCalendar(y, 4, 22),  new GregorianCalendar(y, 5, 22),
            new GregorianCalendar(y, 6, 23),  new GregorianCalendar(y, 7, 22),
            new GregorianCalendar(y, 8, 24),  new GregorianCalendar(y, 9, 24),
            new GregorianCalendar(y, 10, 23), new GregorianCalendar(y, 11, 23)
        };

        for(int i = 0; i < 11; ++i)
            if(c.compareTo(dates[i]) >= 0 && c.compareTo(dates[i+1]) < 0)
                return signs[i];

        return signs[11];
    }

    public static void main(String[] args) {
       
        Scanner in = new Scanner(System.in);
        int t = in.nextInt(); 
        for(int i = 1; i <= t; ++i) {
            String s = in.next();
            int m = Integer.parseInt(s.substring(0,2)) - 1;
            int d = Integer.parseInt(s.substring(2,4));
            int y = Integer.parseInt(s.substring(4));

            Calendar c = new GregorianCalendar(y, m, d);
            c.add(Calendar.WEEK_OF_YEAR, 40);

            System.out.printf("%d %02d/%02d/%04d ", i, c.get(Calendar.MONTH) + 1, c.get(Calendar.DAY_OF_MONTH), c.get(Calendar.YEAR));
            System.out.println(sign(c));
        }

    }

}
