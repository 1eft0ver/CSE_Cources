package myjava.homework;

// Represents a balance inquiry ATM transaction

public class BalanceInquiry extends Transaction{
	
	public void execute(BankDatabase db) {
		System.out.println("Balance Information:");
		System.out.printf("Total balance: %d\n", db.getTotalBalance( this.getAccountNumber()));
	}
	public void setAmount(int money) {
		System.out.println("There's no need to setAmount during balance inquiry process.");
	}
}
