//
//  main.cpp
//  SplitWiseBillSharingApp
//
//  Created by khkumari on 16/02/22.
//

#include <iostream>
#include "ExpenseManager.hpp"
#include "Utility.hpp"
#include "UnitTest.hpp"

enum commandtype{
    SHOW, EXPENSE
};
//1 u1 1250 2 u2 u3 1 370 880
int main(int argc, const char * argv[]) {
    // insert code here...
    testing::InitGoogleTest();
    cout<<"test result"<<RUN_ALL_TESTS();
    
    shared_ptr<ExpenseManager> expenseManager = shared_ptr<ExpenseManager> (new ExpenseManager());
    expenseManager->addUser(shared_ptr<User> (new User("u1", "User1", "gaurav@gmail.com", "9876543210")));
    expenseManager->addUser(shared_ptr<User> (new User("u2", "User2", "sagar@gmail.com", "9876543210")));
    expenseManager->addUser(shared_ptr<User> (new User("u3", "User3", "hi@gmail.com", "9876543210")));
    expenseManager->addUser(shared_ptr<User> (new User("u4", "User4", "mock-interviews@gmail.com", "9876543210")));
    
    while (true) {
        string command;
        getline(cin, command);
        vector<string> commands = Utility::split(command, ' ');
        string commandType = commands[0];
        commandtype commType = static_cast<commandtype>(stoi(commandType));
        
        switch (commType) {
            case SHOW:
                if (commands.size() == 1) {
                    expenseManager->showBalances();
                } else {
                    expenseManager->showBalance(commands[1]);
                }
                break;
            case EXPENSE:
                string paidBy = commands[1];
                double amount = stod(commands[2]);
                int noOfUsers = stoi(commands[3]);
                int expenseType = stoi(commands[4 + noOfUsers]);
                ExpenseType inExpenseType = static_cast<ExpenseType>(expenseType);
                vector<shared_ptr<Split> > splits;
                switch (inExpenseType) {
                    case EQUAL:
                        for (int i = 0; i < noOfUsers; i++) {
                            splits.push_back(shared_ptr<Split> (new EqualSplit(expenseManager->userMap[commands[4 + i]])));
                        }
                        expenseManager->addExpense(EQUAL, amount, paidBy, splits, NULL);
                        break;
                    case EXACT:
                        cout<<"here in exact\n";
                        for (int i = 0; i < noOfUsers; i++) {
                            splits.push_back(shared_ptr<Split> (new ExactSplit(expenseManager->userMap[commands[4 + i]], stod(commands[5 + noOfUsers + i]))));
                        }
                        expenseManager->addExpense(EXACT, amount, paidBy, splits, NULL);
                        
                        break;
                    case PERCENT:
                        for (int i = 0; i < noOfUsers; i++) {
                            splits.push_back(shared_ptr<Split> (new PercentSplit(expenseManager->userMap[commands[4 + i]], stod(commands[5 + noOfUsers + i]))));
                        }
                        expenseManager->addExpense(PERCENT, amount, paidBy, splits, NULL);
                        break;
                }
                cout<<"after expense type\n";
                break;
                
        }
    }
    return 0;
}
