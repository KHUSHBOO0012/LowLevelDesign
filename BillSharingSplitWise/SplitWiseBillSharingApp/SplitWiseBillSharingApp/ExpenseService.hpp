//
//  ExpenseService.hpp
//  SplitWiseBillSharingApp
//
//  Created by khkumari on 16/02/22.
//

#ifndef ExpenseService_hpp
#define ExpenseService_hpp
#include "Expense.hpp"
#include "PercentSplit.hpp"
#include "ExactExpense.hpp"
#include "PercentExpense.hpp"
#include "EqualExpense.hpp"
#include <stdio.h>
#include <math.h>
class ExpenseService{
public:
    static shared_ptr<Expense> createExpense(ExpenseType expenseType, double amount, shared_ptr<User> paidBy, vector<shared_ptr<Split> > splits, shared_ptr<ExpenseMetaData> expenseMetadata){
        switch (expenseType) {
            case EXACT:
                return shared_ptr<Expense> (new ExactExpense(amount, paidBy, splits, expenseMetadata));
            case PERCENT:
                for (shared_ptr<Split> split : splits) {
                    shared_ptr<PercentSplit> percentSplit = dynamic_pointer_cast<PercentSplit> (split);
                    split->setAmount((amount*percentSplit->getPercent())/100.0);
                }
                return shared_ptr<Expense> (new PercentExpense(amount, paidBy, splits, expenseMetadata));
            case EQUAL:
                int totalSplits = (int) splits.size();
                double splitAmount = ((double) round(amount*100/totalSplits))/100.0;
                for (shared_ptr<Split> split : splits) {
                    split->setAmount(splitAmount);
                }
                splits[0]->setAmount(splitAmount + (amount - splitAmount*totalSplits));
                return shared_ptr<Expense> (new EqualExpense(amount, paidBy, splits, expenseMetadata));
        }
    }

};
#endif /* ExpenseService_hpp */
