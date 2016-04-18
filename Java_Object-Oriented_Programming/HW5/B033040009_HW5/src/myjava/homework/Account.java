package myjava.homework;

//Represents a bank account

public class Account {
	private int accountNumber;
	private int pin;
	private int totalBalance;
	
	public Account(){
		accountNumber = 0;
		pin = 0;
		totalBalance = 0;
	}
	
	public Account(int _accountNumber, int _pin, int _totalBalance) {
		accountNumber = _accountNumber;
		pin = _pin;
		totalBalance = _totalBalance;
	}
	
	public boolean validatePin(int inputPin) {
		if(inputPin == pin) 
			return true;
		else
			return false;
	}
	
	public boolean validateAccount(int inputAccount) {
		if(inputAccount == accountNumber) 
			return true;
		else
			return false;
	}
	
	public int getTotalBalance() {
		return totalBalance;
	}
	
	public boolean isFundSufficient(int money) {
		if(totalBalance < money)
			return false;
		else
			return true;
	}
	
	public void credit(int money) { //add (an amount of money) to an account
		totalBalance = totalBalance + money;
	}
	
	public void debit(int money) { //remove an amount of money from (a bank account)
		totalBalance = totalBalance - money;
	}
}
