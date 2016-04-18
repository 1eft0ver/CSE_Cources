package myjava.homework;

public class ATM {
	private boolean userAuthenticated;
	
	public void run () {
		BankDatabase theDb = new BankDatabase();
		
		while(true) {
			Keypad theKeypad = new Keypad();
			Screen theScreen = new Screen();
			
			int accountNum;
			int PINNum;
			
			theScreen.displayMessageLine("Welcome!");
			theScreen.displayMessage("Please enter your account number: ");
			accountNum = theKeypad.getInput();
			theScreen.displayMessage("Enter your PIN: ");
			PINNum = theKeypad.getInput();
				
			while(accountNum == -1 || PINNum == -1) {
				theScreen.displayMessageLine("Invalid Input. Your account or PIN should only be represented by numbers 0 to 9. Please try again");
				theScreen.displayMessage("Please enter your account number: ");
				accountNum = theKeypad.getInput();
				theScreen.displayMessage("Enter your PIN: ");
				PINNum = theKeypad.getInput();
			}
				
			while(theDb.authenticateUser(accountNum, PINNum) == false) {
				theScreen.displayMessageLine("Invalid account or PIN. Please try again");
				theScreen.displayMessageLine("");
				theScreen.displayMessage("Please enter your account number: ");
				accountNum = theKeypad.getInput();
				theScreen.displayMessage("Enter your PIN: ");
				PINNum = theKeypad.getInput();
			}
			
			int choice;
			theScreen.displayMessageLine("");
			theScreen.displayMessageLine("Main menu:");
			theScreen.displayMessageLine("1. View my balance");
			theScreen.displayMessageLine("2. Withdrawe");
			theScreen.displayMessageLine("3. Deposit");
			theScreen.displayMessageLine("4. Exit");
			theScreen.displayMessageLine("");
			
			
			while(true) {
				theScreen.displayMessage("Enter a choice: ");
				choice = theKeypad.getInput();
				
				while(choice < 1 || choice > 4) {
					theScreen.displayMessageLine("You did not enter a valid selection. Try again.");
					theScreen.displayMessageLine("");
					theScreen.displayMessage("Enter a choice: ");
					choice = theKeypad.getInput();
				}
				
				if(choice == 4) {
					theScreen.displayMessageLine("EXIT.");
					theScreen.displayMessageLine("Thank you! Goodbye!");
					theScreen.displayMessageLine("");
					break;
				}
				
				int money;
				switch (choice) {			
				case 1:
					Transaction view = new BalanceInquiry();
					view.setAccountNumber(accountNum);
					view.execute(theDb);
					theScreen.displayMessageLine("");
					break;
					
				case 2:
					Transaction withdraw = new Withdrawal();				
					theScreen.displayMessage("How much do you want to withdraw: ");
					money = theKeypad.getInput();
					while(money == -1) {
						theScreen.displayMessageLine("You input an unvalid amount. Please input amount only represented by numbers 0 to 9. Please try again.");
						theScreen.displayMessage("How much do you want to withdraw: ");
						money = theKeypad.getInput();
					}
					withdraw.setAccountNumber(accountNum);				
					withdraw.setAmount(money);
					withdraw.execute(theDb);
					break;
					
				case 3:
					Transaction deposit = new Deposit();
					theScreen.displayMessage("How much do you want to deposit: ");
					money = theKeypad.getInput();
					while(money == -1) {
						theScreen.displayMessageLine("You input an unvalid amount. Please input amount only represented by numbers 0 to 9. Please try again.");
						theScreen.displayMessage("How much do you want to deposit: ");
						money = theKeypad.getInput();
					}
					deposit.setAccountNumber(accountNum);				
					deposit.setAmount(money);
					deposit.execute(theDb);
					break;
					
				default:
					theScreen.displayMessageLine("I don't know hy you're here. It's just impossible to get here. There must be something wrong or you're a fucking hacker.");
					break;
				}
			}
			
		}
	}
	
}
