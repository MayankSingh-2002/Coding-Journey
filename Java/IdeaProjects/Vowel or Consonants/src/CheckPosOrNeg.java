import java.util.*;
public class CheckPosOrNeg {
    static void main() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number: ");
        int num = sc.nextInt();
        if (num == 0) {
            System.out.println("The number is zero.");
        } else if (num > 0) {
            System.out.println("The number is positive.");
        } else {
            System.out.println("The number is negative");
        }
    }
}
