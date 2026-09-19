//Write  a  Java  program  to  print  the  sum  of  elements  of  the  array.  Also 
//display array elements in ascending order.
package java_and_webtech;
import java.util.Scanner;
public class slip1_01{
      public static void main(String[] args){
            Scanner sc = new Scanner(System.in);
            int sum = 0;
            int n , i ,j;
            System.out.println("enter the number of element");
            n = sc.nextInt();
            int arr[] = new int[n];
            for(i=0;i<n;i++){
                  arr[i] = sc.nextInt();
            }
            for (i = 0; i < n; i++) {
                  sum = sum + arr[i];
            }
            System.out.println("sum of array is "+sum);

            System.out.println("array element in ascending order");
              for (i = 0; i < n; i++) {
                  for(j = 0;j<n-1;j++){
                        if(arr[j]>arr[j+1]){
                              int temp = arr[j];
                              arr[j] = arr[j+1];
                              arr[j+1] = temp;
                        }
                  }
            }
                    for (i = 0; i < n; i++) {
                        System.out.print(arr[i]+" ");
            }
            
      }
}
