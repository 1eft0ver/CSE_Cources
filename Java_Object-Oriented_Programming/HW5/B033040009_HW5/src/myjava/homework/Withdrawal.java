package myjava.homework;

// Represents a withdrawal ATM transaction

public class Withdrawal extends Transaction{
	private int  amount;
	public Withdrawal() {
		amount = 0;
	}
	public Withdrawal(int money) {
		amount = money;
	}
	public void setAmount(int money) {
		amount = money;
	}
	public void execute(BankDatabase db) {
		int result = db.debit(this.getAccountNumber(), amount);
		Screen output = new Screen();
		if(result == 0) {
			output.displayMessageLine("Insufficient funds in your account!");
			output.displayMessageLine("");
		}
		
		else if(result == -1) {
			output.displayMessageLine("Unexpected error!");
			output.displayMessageLine("");
		}
		
		else {
			output.displayMessageLine("Success!");
			output.displayMessageLine("");
		}
	}
}
