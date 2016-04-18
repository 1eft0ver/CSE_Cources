package myjava.homework;

// Represents a deposit ATM transaction

public class Deposit extends Transaction{
	private int  amount;
	public Deposit() {
		amount = 0;
	}
	public Deposit(int money) {
		amount = money;
	}
	public void setAmount(int money) {
		amount = money;
	}
	public void execute(BankDatabase db) {
		Screen output = new Screen();
		db.credit(this.getAccountNumber(), amount);
		output.displayMessageLine("Success!");
		output.displayMessageLine("");
	}
}
