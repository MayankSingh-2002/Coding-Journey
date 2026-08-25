import java.util.*;

public class LeftHalfPyramid {
    static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the rows for the pyramid: ");

        int n = sc.nextInt();

        for (int i = 1; i <= n; i++) {
            for (int j = n-i; j >= 1; j--)
                System.out.print(" ");
            for (int k = 1; k <= i; k++)
                System.out.print("*");
            System.out.println();
        }
    }
}
