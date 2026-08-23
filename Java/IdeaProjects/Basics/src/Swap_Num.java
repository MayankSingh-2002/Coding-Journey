import java.util.*;
public class Swap_Num {
    static void main() {
        int a = 10, b = 15 , temp;
        System.out.println("Before swaping a = " + a + " and b = " + b);
        temp = a;
        a = b;
        b = temp;
        System.out.println("After swaping a = " + a + " and b = " + b);
    }
}
