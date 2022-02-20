//
//  ExactSplit.hpp
//  SplitWiseBillSharingApp
//
//  Created by khkumari on 16/02/22.
//

#ifndef ExactSplit_hpp
#define ExactSplit_hpp

#include "Split.hpp"
#include <stdio.h>
class ExactSplit : public Split{
public:
    ExactSplit(shared_ptr<User> user, double amount) : Split(user){
        this->amount = amount;
    }
    ~ExactSplit(){
        
    }
};
#endif /* ExactSplit_hpp */
