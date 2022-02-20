//
//  ExactExpense.hpp
//  SplitWiseBillSharingApp
//
//  Created by khkumari on 16/02/22.
//

#ifndef ExactExpense_hpp
#define ExactExpense_hpp
#include "Expense.hpp"
#include "ExactSplit.hpp"
#include <stdio.h>
#include <math.h>
class ExactExpense : public Expense{
public:
    ExactExpense(double amount, shared_ptr<User> paidBy, vector<shared_ptr<Split> > splits, shared_ptr<ExpenseMetaData> metadata);
    bool validate(){
        for(shared_ptr<Split> split: getSplits()){
            if(!dynamic_pointer_cast<ExactSplit> (split)){
                return false;
            }
        }
        
        double totalAmount = getAmount();
        double sumSplitAmount = 0;
        for(shared_ptr<Split> split: getSplits()){
            shared_ptr<ExactSplit> exactSplit = dynamic_pointer_cast<ExactSplit> (split);
            sumSplitAmount += exactSplit->getAmount();
        }
        if(totalAmount != sumSplitAmount){
            return false;
        }
        return true;
    }
};
#endif /* ExactExpense_hpp */
