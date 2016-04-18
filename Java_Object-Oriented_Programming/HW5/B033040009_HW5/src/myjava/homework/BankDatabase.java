package myjava.homework;
/*
import org.omg.CORBA.PUBLIC_MEMBER;

import com.sun.org.apache.xml.internal.resolver.helpers.PublicId;
*/
// Represents the bank account information database

public class BankDatabase {
	
	private Account[] accounts; // array of Accounts
	public static final int accountQuantity = 2;
    // no-argument BankDatabase constructor initializes accounts
	public BankDatabase () {
		accounts = new Account[accountQuantity];  // just 2 accounts for testing
		accounts[0] = new Account(12345, 54321, 1000);
		accounts[1] = new Account(67890, 98765, 100);
	}
	
	public boolean authenticateUser(int account, int pin) {
		for(int i = 0 ; i < accountQuantity ; ++i) {
			if(accounts[i].validateAccount(account)  && accounts[i].validatePin(pin) )
				return true;
		}
		return false;
	}
	
	public int getTotalBalance(int account) {
		for(int i = 0 ; i < accountQuantity ; ++i) {
			if(accounts[i].validateAccount(account))
				return accounts[i].getTotalBalance();
		}		
		return -1;
	}
	
	public void credit (int account, int money) { //add (an amount of money) to an account:
		for(int i = 0 ; i < accountQuantity ; ++i) {
			if(accounts[i].validateAccount(account))
				accounts[i].credit(money);
		}		
	}
	
	public int debit(int account,int money) { //remove an amount of money from (a bank account):
		for(int i = 0 ; i < accountQuantity ; ++i) {
			if(accounts[i].validateAccount(account) && accounts[i].isFundSufficient(money)) {
				accounts[i].debit(money);
				return 1;
			}
			else if(accounts[i].validateAccount(account) && accounts[i].isFundSufficient(money) == false) {
				return 0;
			}
		}	
		return -1;
	}
}
