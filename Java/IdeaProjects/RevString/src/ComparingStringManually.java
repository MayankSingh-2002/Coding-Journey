import java.util.*;

public class ComparingStringManually {
    static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the first string.");
        String str1 = sc.nextLine();
        System.out.println("Enter the second string.");
        String str2 = sc.nextLine();
        boolean match = true;

        if(str1.length() != str2.length()) {
            match = false;
        } else {
            for(int i = 0; i < str1.length(); i++) {
                if(str1.charAt(i) != str2.charAt(i)){
                    match = false;
                    break;
                }
            }
        }

        System.out.println(match ? "Strings are equal." : "Strings are not equal.");

    }
}
