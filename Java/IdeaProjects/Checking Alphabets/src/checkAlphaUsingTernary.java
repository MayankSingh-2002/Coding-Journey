import java.util.*;
public class checkAlphaUsingTernary {
    static void main() {
        char ch = 'M';

        String result = ((ch >= 'A' && ch <= 'Z') || (ch >='a' && ch <= 'z')) ? "an alphabet" : "not an alphabet";
        System.out.println("Given " + ch + " is " + result);
    }
}
