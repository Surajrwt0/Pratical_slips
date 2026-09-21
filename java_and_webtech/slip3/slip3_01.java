package java_and_webtech.slip3;
import java_and_webtech.slip3.StringOperation.comp;
import java_and_webtech.slip3.StringOperation.coon;
import java.util.Scanner;
public class slip3_01 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter first string: ");
        String s1 = sc.nextLine();

        System.out.print("Enter second string: ");
        String s2 = sc.nextLine();

        coon c = new coon();
        comp cp = new comp();

        System.out.println("\n--- String Operations ---");

        c.concatenate(s1, s2);
        cp.compare(s1, s2);

        sc.close();
    }
}