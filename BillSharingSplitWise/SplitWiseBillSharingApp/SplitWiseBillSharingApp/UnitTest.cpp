//
//  UnitTest.cpp
//  SplitWiseBillSharingApp
//
//  Created by khkumari on 17/02/22.
//

#include "UnitTest.hpp"
#include "ExpenseManager.hpp"
TEST(UnitTest, addUserTest){
    shared_ptr<ExpenseManager> expenseManager = shared_ptr<ExpenseManager> (new ExpenseManager());
    
    ASSERT_EQ(expenseManager->userMap.size(), 0);
    
    expenseManager->addUser(shared_ptr<User> (new User("u1", "User1", "gaurav@gmail.com", "9876543210")));
    expenseManager->addUser(shared_ptr<User> (new User("u2", "User2", "sagar@gmail.com", "9876543210")));
    expenseManager->addUser(shared_ptr<User> (new User("u3", "User3", "hi@gmail.com", "9876543210")));
    expenseManager->addUser(shared_ptr<User> (new User("u4", "User4", "mock-interviews@gmail.com", "9876543210")));
    
    ASSERT_EQ(expenseManager->userMap.size(), 4);
}

TEST(UnitTest, showBalanceTest){
    unique_ptr<ExpenseManager> expenseManager = unique_ptr<ExpenseManager> (new ExpenseManager());
    expenseManager->addUser(shared_ptr<User> (new User("u1", "User1", "gaurav@gmail.com", "9876543210")));
    expenseManager->addUser(shared_ptr<User> (new User("u2", "User2", "sagar@gmail.com", "9876543210")));
    expenseManager->addUser(shared_ptr<User> (new User("u3", "User3", "hi@gmail.com", "9876543210")));
    expenseManager->addUser(shared_ptr<User> (new User("u4", "User4", "mock-interviews@gmail.com", "9876543210")));
    
    string users[2] = {"u2", "u3"};
    string amounts[2] = {"370", "880"};
    vector<shared_ptr<Split> > splits;
    for (int i = 0; i < 2; i++) {
        splits.push_back(shared_ptr<Split> (new ExactSplit(expenseManager->userMap[users[i]], stod(amounts[i]))));
    }
    expenseManager->addExpense(EXACT, 1250, "u1", splits, NULL);
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    
    expenseManager->showBalances();
    
    std::cout.rdbuf(p_cout_streambuf);
    
    ASSERT_EQ(oss.str(), "User3 owes User1: 880\nUser2 owes User1: 370\n");
    
    ASSERT_EQ(expenseManager->userMap.size(), 4);
}
