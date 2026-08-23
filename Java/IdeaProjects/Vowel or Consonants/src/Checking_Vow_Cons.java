import java.util.Scanner;

public class Checking_Vow_Cons {
    static void main() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter an alphabet: ");
        char ch = sc.next().charAt(0);

        if ( ch == 'a' || ch == 'e' || ch == 'i' ||
                ch == 'o' || ch == 'u' || ch == 'A' ||
                ch == 'E' || ch == 'I' || ch == 'O' ||
                ch == 'U') {
            System.out.println("Vowel");
        } else {
            System.out.println("Consonant");
        }

        sc.close();
    }
}
