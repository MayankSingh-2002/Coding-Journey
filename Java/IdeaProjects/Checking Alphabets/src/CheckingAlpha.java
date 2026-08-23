import java.util.*;
public class CheckingAlpha {
    static void main() {
        char ch = 'R';

        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            System.out.println("Given " + ch + " is an alphabet");
        } else {
            System.out.println("Given " + ch + " is not an alphabet.");
        }
    }
}
