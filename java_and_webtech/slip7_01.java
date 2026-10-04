/*Write a class Driver with attributes license_no, name, address and age. 
Initialize values through the parameterized constructor. If age of Driver 
is less than 18 then user-defined exception should be generated —Age 
is below 18 years—8*/
import java.util.*;
class ageException extends Exception{
      ageException(String msg){
            super(msg);
      }
}
class  Driver{
      int license_no;
      String name ;
      String Address;
      int age;
      Driver(int lno , String name, String add,int age){
            this.license_no = lno;
            this.name = name;
            this.Address = add;
            this.age = age;
      }
}
public class slip7_01 {
      public static void main(String args[]){
            Scanner sc = new Scanner(System.in);
            System.out.println("enter license number");
            int lno = sc.nextInt();
            System.out.println("enter name");
            String name = sc.next();
            System.out.println("enter Address");
            String Address = sc.next();
            System.out.println("enter age");
            int age= sc.nextInt();
            Driver d = new Driver(lno,name,Address,age);
            try{
                  if(d.age<18){
                        throw new ageException("age is less than 18");
                  }
                  System.out.println("lno ="+d.license_no);
                  System.out.println("name ="+d.name);
                  System.out.println("Address ="+d.Address);
                  System.out.println("age ="+d.age);
            }
            catch(ageException e){
                  System.out.print(e.getMessage());
            }
      }      
}