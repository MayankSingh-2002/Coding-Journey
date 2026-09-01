import java.util.*;

public class StrRevUsingTwoPtr {
    static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value of string: ");
        String str = sc.nextLine();

        char[] ch = str.toCharArray();
        int start = 0, end = ch.length-1;

        while(start < end) {
            char temp = ch[start];
            ch[start] = ch[end];
            ch[end] = temp;
            start++; end--;
        }

        System.out.println("Reverse of string is: " + new String(ch));
    }
}
