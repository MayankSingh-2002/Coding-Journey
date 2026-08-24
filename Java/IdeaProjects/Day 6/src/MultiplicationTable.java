//#13 Multiplication Table
import java.util.*;
public class MultiplicationTable {
    static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the digit to print table: ");
        int num = sc.nextInt();

        for (int i=1; i <=10 ; i++) {
            System.out.println(num+" "+" X "+i+" " +" = "+" "+num*i);
        }
    }
}
