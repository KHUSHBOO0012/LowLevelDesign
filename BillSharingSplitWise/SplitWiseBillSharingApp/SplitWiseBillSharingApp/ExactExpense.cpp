//
//  ExactExpense.cpp
//  SplitWiseBillSharingApp
//
//  Created by khkumari on 16/02/22.
//

#include "ExactExpense.hpp"
ExactExpense::ExactExpense(double amount, shared_ptr<User> paidBy, vector<shared_ptr<Split> > splits, shared_ptr<ExpenseMetaData> metadata) : Expense(amount, paidBy, splits, metadata){

}
