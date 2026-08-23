import java.util.*;
public class CheckingEvenOdd {
    static void main() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number: ");
        int num = sc.nextInt();
        if ( num % 2 == 0) {
            System.out.println("The number " + num + " is Even.");
        } else {
            System.out.println("The number " + num + " is Odd.");
        }
    }
}
