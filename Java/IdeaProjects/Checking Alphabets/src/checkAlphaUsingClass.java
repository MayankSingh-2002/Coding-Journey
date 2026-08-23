import java.util.*;
public class checkAlphaUsingClass {
    static void main() {
        char ch = '7';
        if (Character.isLetter(ch)) {
            System.out.println("Given " + ch + " is an alphabet.");
        } else {
            System.out.println("Given " + ch + " is not an alphabet.");
        }
    }
}
