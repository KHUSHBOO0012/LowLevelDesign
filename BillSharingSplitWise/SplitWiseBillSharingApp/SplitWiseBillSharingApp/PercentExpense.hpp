//
//  PercentExpense.hpp
//  SplitWiseBillSharingApp
//
//  Created by khkumari on 16/02/22.
//

#ifndef PercentExpense_hpp
#define PercentExpense_hpp
#include "Expense.hpp"
#include "PercentSplit.hpp"
#include <stdio.h>
class PercentExpense : public Expense{
public:
    PercentExpense(double amount, shared_ptr<User> paidBy, vector<shared_ptr<Split> > splits, shared_ptr<ExpenseMetaData> metadata) : Expense(amount, paidBy, splits, metadata){

    }
    bool validate(){
        for(shared_ptr<Split> split: getSplits()){
            if(!dynamic_pointer_cast<PercentSplit> (split)){
                return false;
            }
        }
        
        double totalPercent = getAmount();
        double sumSplitPercent = 0;
        for(shared_ptr<Split> split: getSplits()){
            shared_ptr<PercentSplit> exactSplit = dynamic_pointer_cast<PercentSplit> (split);
            sumSplitPercent += exactSplit->getPercent();
        }
        if(totalPercent != sumSplitPercent){
            return false;
        }
        return true;
    }
};
#endif /* PercentExpense_hpp */
