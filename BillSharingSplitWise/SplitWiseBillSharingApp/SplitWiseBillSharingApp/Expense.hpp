//
//  Expense.hpp
//  SplitWiseBillSharingApp
//
//  Created by khkumari on 16/02/22.
//

#ifndef Expense_hpp
#define Expense_hpp
#include "Split.hpp"
#include "ExpenseMetaData.hpp"
#include "User.hpp"
#include <stdio.h>
#include <vector>
enum ExpenseType{
    EQUAL, EXACT, PERCENT
};
class Expense{
private:
    string id;
    shared_ptr<User> paidBy;
    vector<shared_ptr<Split> > splits;
    double amount;
    shared_ptr<ExpenseMetaData> metadata;
    
public:
    Expense(double amount, shared_ptr<User> paidBy, vector<shared_ptr<Split> > splits, shared_ptr<ExpenseMetaData> metadata)  : amount(amount), paidBy(paidBy), splits(splits), metadata(metadata){
        
    }
    virtual ~Expense()=0;
    string getId() const{
        return id;
    }
    double getAmount() const{
        return amount;
    }
    void setId(string id){
        this->id = id;
    }
    vector<shared_ptr<Split> > getSplits(){
        return splits;
    }
};
#endif /* Expense_hpp */
