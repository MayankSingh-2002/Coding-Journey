//#14
import java.util.*;
public class KilometersToMiles {
    static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter distance in Kilometers: ");
        double KMS = sc.nextDouble();

        double Miles = KMS * 0.621371;

        System.out.println("Distance in miles: " + Miles);

        sc.close();
    }
}
