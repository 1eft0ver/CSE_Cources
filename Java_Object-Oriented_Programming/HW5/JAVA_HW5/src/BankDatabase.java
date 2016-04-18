// Represents the bank account information database

public class BankDatabase {
	
	private Account[] accounts; // array of Accounts
	
    // no-argument BankDatabase constructor initializes accounts
	public BankDatabase () {
		accounts = new Account[2];  // just 2 accounts for testing
		accounts[0] = new Account(12345, 54321, 1000);
		accounts[1] = new Account(67890, 98765, 100);
	}
	
	/* Fill your code here */
	
}
