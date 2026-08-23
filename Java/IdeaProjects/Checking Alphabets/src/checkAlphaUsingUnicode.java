import java.util.*;
public class checkAlphaUsingUnicode {
    static void main() {
        char ch = 'S';
        int code = (int) ch;
        if ((code >=65 && code<=90) || (code >= 97 && code <= 122)) {
            System.out.println("Given " + ch + " is an alphabet.");
        } else {
            System.out.println("Given " + ch + " is not an alphabet.");
        }
    }
}
