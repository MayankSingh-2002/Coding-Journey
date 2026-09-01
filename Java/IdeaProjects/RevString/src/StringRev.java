import java.util.*;

public class StringRev {
    static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the string to reverse: ");
        String str = sc.nextLine();
        char[] ch = str.toCharArray();
        String rev = "";

        for( int i = ch.length-1; i >= 0; i--) {
            rev += ch[i];
        }

        System.out.println("Reverse string is: " + rev);

    }
}
