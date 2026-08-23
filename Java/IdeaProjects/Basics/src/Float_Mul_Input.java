import java.util.*;
public class Float_Mul_Input {
    static void main() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter first number: ");
        float n1 = sc.nextFloat();
        System.out.println("Enter second number: ");
        float n2 = sc.nextFloat();

        float result = n1 * n2;
        System.out.println("The result of multiplication of number " + n1 + " and " + n2 + " is " + result);
    }

}
