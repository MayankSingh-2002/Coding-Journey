//#12
import java.util.*;

public class CheckLeapYear {
    static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Year: ");
        int year = sc.nextInt();

        if ( year % 100 == 0) {
            if ( year % 400 == 0)
                System.out.println("Year " + year + " is a leap year.");
            else
                System.out.println(" Year " + year + " is not a leap year.");
        } else {
            if ( year % 4 == 0)
                System.out.println("Year " + year + " is a leap year.");
            else
                System.out.println("Year " + year + " is not a leap year.");
        }
    }
}
