package java_and_webtech;
import java.util.Scanner;
public class slip2_01 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int start, end;
        System.out.print("Enter starting range: ");
        start = sc.nextInt();
        System.out.print("Enter ending range: ");
        end = sc.nextInt();
        System.out.println("Armstrong numbers between " + start + " and " + end + ":");
        for (int num = start; num <= end; num++) {
            int n = num;
            int sum = 0;
            int digits = String.valueOf(num).length();
            while (n > 0) {
                int digit = n % 10;
                sum += Math.pow(digit, digits);
                n = n / 10;
            }
            if (sum == num) {
                System.out.print(num + " ");
            }
        }
        sc.close();
    }
}