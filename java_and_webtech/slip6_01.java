/*Write  a  program  to  define  a  class  Account  having  members  custname, 
accno.  Define  default  and  parameterized  constructor.  Create  a  subclass 
called SavingAccount with members savingbal, minbal. Create a derived 
class AccountDetail that extends the class SavingAccount with members, 
depositamt  and  withdrawalamt.  Write  a  appropriate  method  to  display 
customer details.*/
class Account{
      String custname;
      int accno;
      Account(){
            custname = "";
            accno = 0;
      }
      Account(String name , int no){
            this.custname = name;
            this.accno = no;
      }
}
class SavingAccount extends Account{
      double savingbal ;
      double minbal;
      SavingAccount(String name , int no , double sav,double min){
            super(name,no);
            this.savingbal = sav;
            this.minbal = min;
      }
}
class Accountdetail extends SavingAccount{
      double depositamt;
      double withdrawlamt;
      Accountdetail(String name , int no , double sav,double min,double deposit,double withdrawl){
            super(name,no,sav,min);
            this.depositamt = deposit;
            this.withdrawlamt = withdrawl;
      }
      void display() {
        System.out.println("Customer Name: " + custname);
        System.out.println("Account Number: " + accno);
        System.out.println("Saving Balance: " + savingbal);
        System.out.println("Minimum Balance: " + minbal);
        System.out.println("Deposit Amount: " + depositamt);
        System.out.println("Withdrawal Amount: " + withdrawlamt);

}
}
public class slip6_01 {
      public static void main(String args[]){
            Accountdetail ad = new Accountdetail("suraj", 1, 1500, 500, 300, 50);
            ad.display();
      }
}
