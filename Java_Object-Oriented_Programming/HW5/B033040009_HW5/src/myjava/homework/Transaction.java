package myjava.homework;

// Abstract superclass Transaction represents an ATM transaction

public abstract class Transaction {
	private int accountNumber;
	
	public int getAccountNumber() {
		return accountNumber;
	}
	
	public void setAccountNumber(int account) {
		accountNumber = account;
	}
	
	public abstract void execute(BankDatabase db) ;
	public abstract void setAmount(int money);
}
