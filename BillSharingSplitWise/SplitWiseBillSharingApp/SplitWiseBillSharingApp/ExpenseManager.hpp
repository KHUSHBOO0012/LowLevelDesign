//
//  ExpenseManager.hpp
//  SplitWiseBillSharingApp
//
//  Created by khkumari on 16/02/22.
//

#ifndef ExpenseManager_hpp
#define ExpenseManager_hpp

#include <stdio.h>
#include <iostream>
#include "ExpenseService.hpp"
#include <unordered_map>
class ExpenseManager{
public:
    vector<shared_ptr<Expense>> expenses;
    unordered_map<string, shared_ptr<User>> userMap;
    unordered_map<string, unordered_map<string, double> > balanceSheet;
    
    void addUser(shared_ptr<User> user){
        userMap[user->getId()] = user;
    }
    void addExpense(ExpenseType expenseType, double amount, string paidBy, vector<shared_ptr<Split> > splits, shared_ptr<ExpenseMetaData> expenseMetadata) {
        shared_ptr<Expense> expense = ExpenseService::createExpense(expenseType, amount, userMap[paidBy], splits, expenseMetadata);
        expenses.push_back(expense);
        for (shared_ptr<Split> split : expense->getSplits()) {
            string paidTo = split->getUser()->getId();
            unordered_map<string, double> balances = balanceSheet[paidBy];
           
            if (!balances.count(paidTo)) {
                balances[paidTo] = 0.0;
            }
            balances[paidTo] = balances[paidTo] + split->getAmount();
            balanceSheet[paidBy] = balances;

            balances = balanceSheet[paidTo];
            if (!balances.count(paidBy)) {
                balances[paidBy] = 0.0;
            }
            balances[paidBy] = balances[paidBy] - split->getAmount();
            balanceSheet[paidTo] = balances;
        }
    }

    void showBalance(string userId) {
            bool isEmpty = true;
            for (auto userBalance : balanceSheet[userId]) {
                if (userBalance.second != 0) {
                    isEmpty = false;
                    printBalance(userId, userBalance.first, userBalance.second);
                }
            }

            if (isEmpty) {
                cout<<"No balances\n";
            }
        }
    
    void showBalances() {
        bool isEmpty = true;
//        for (auto allBalances = balanceSheet.begin(); allBalances!=balanceSheet.end(); allBalances++) {
        for (auto allBalances : balanceSheet) {
            for (auto userBalance : allBalances.second) {
                if (userBalance.second > 0) {
                    isEmpty = false;
                    printBalance(allBalances.first, userBalance.first, userBalance.second);
                }
            }
        }

        if (isEmpty) {
            cout<<"No balances\n";
        }
    }
    
    void printBalance(string user1, string user2, double amount) {
        string user1Name = userMap[user1]->getName();
        string user2Name = userMap[user2]->getName();
        
        if (amount < 0) {
            cout<<user1Name<<" owes "<<user2Name<<": "<<abs(amount)<<"\n";
        } else if (amount > 0) {
            cout<<user2Name<<" owes "<<user1Name<<": "<<abs(amount)<<"\n";
        }
    }
};
#endif /* ExpenseManager_hpp */
