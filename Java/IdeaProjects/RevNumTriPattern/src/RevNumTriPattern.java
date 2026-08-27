import org.w3c.dom.ls.LSOutput;

import java.util.*;

public class RevNumTriPattern {
    static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the no. of rows for the pattern.");
        int n = sc.nextInt();

        for(int i = 1; i <= n; i++){

            for(int j = 1; j <= i-1; j++) {
                System.out.print(" ");
            }

            for(int j = i; j <= n; j++) {
                System.out.print(j+" ");
            }

            System.out.println();
        }

    }
}
