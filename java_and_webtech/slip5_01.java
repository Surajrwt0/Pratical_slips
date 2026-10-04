import java.util.Scanner;
class slip5_01 {
    static Scanner sc = new Scanner(System.in);
    static void accept(int[][] a) {
        for (int i = 0; i < a.length; i++)
            for (int j = 0; j < a[0].length; j++)
                a[i][j] = sc.nextInt();
    }
    static void display(int[][] a) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++)
                System.out.print(a[i][j] + " ");
            System.out.println();
        }
    }
    static void addition() {
        System.out.print("Enter rows and columns: ");
        int r = sc.nextInt(), c = sc.nextInt();
        int[][] a = new int[r][c];
        int[][] b = new int[r][c];
        int[][] sum = new int[r][c];
        System.out.println("Enter first matrix:");
        accept(a);
        System.out.println("Enter second matrix:");
        accept(b);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                sum[i][j] = a[i][j] + b[i][j];
        System.out.println("Addition:");
        display(sum);
    }
    static void multiplication() {
        System.out.print("Enter rows and columns of first matrix: ");
        int r1 = sc.nextInt(), c1 = sc.nextInt();
        System.out.print("Enter rows and columns of second matrix: ");
        int r2 = sc.nextInt(), c2 = sc.nextInt();
        if (c1 != r2) {
            System.out.println("Multiplication not possible");
            return;
        }
        int[][] a = new int[r1][c1];
        int[][] b = new int[r2][c2];
        int[][] p = new int[r1][c2];
        System.out.println("Enter first matrix:");
        accept(a);
        System.out.println("Enter second matrix:");
        accept(b);
        for (int i = 0; i < r1; i++)
            for (int j = 0; j < c2; j++)
                for (int k = 0; k < c1; k++)
                    p[i][j] += a[i][k] * b[k][j];

        System.out.println("Multiplication:");
        display(p);
    }
    static void transpose() {
        System.out.print("Enter rows and columns: ");
        int r = sc.nextInt(), c = sc.nextInt();

        int[][] a = new int[r][c];

        System.out.println("Enter matrix:");
        accept(a);

        System.out.println("Transpose:");
        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r; i++)
                System.out.print(a[i][j] + " ");
            System.out.println();
        }
    }
    public static void main(String[] args) {
        int ch;
        do {
            System.out.println("\n1.Addition");
            System.out.println("2.Multiplication");
            System.out.println("3.Transpose");
            System.out.println("4.Exit");
            System.out.print("Enter choice: ");
            ch = sc.nextInt();
            switch (ch) {
                case 1: addition(); break;
                case 2: multiplication(); break;
                case 3: transpose(); break;
                case 4: System.out.println("Exit"); break;
                default: System.out.println("Invalid choice");
            }
        } while (ch != 4);
    }
}