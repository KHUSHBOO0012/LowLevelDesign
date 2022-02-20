//
//  EqualExpense.hpp
//  SplitWiseBillSharingApp
//
//  Created by khkumari on 16/02/22.
//

#ifndef EqualExpense_hpp
#define EqualExpense_hpp
#include "Expense.hpp"
#include "EqualSplit.hpp"
#include <stdio.h>
class EqualExpense : public Expense{
public:
    EqualExpense(double amount, shared_ptr<User> paidBy, vector<shared_ptr<Split> > splits, shared_ptr<ExpenseMetaData> metadata) : Expense(amount, paidBy, splits, metadata){
        
    }
    bool validate(){
        for(shared_ptr<Split> split: getSplits()){
            if(!dynamic_pointer_cast<EqualSplit> (split)){
                return false;
            }
        }
        return true;
    }
};
#endif /* EqualExpense_hpp */
