import java.util.*;
public class checkAlphaUsingExp {
    static void main() {
        char ch = 'i';

        if(String.valueOf(ch).matches("[a-zA-Z]")) {
            System.out.println("Given " + ch + " is an alphabet.");
        } else {
            System.out.println("Given " + ch + " is not an alphabet.");
        }
    }
}
