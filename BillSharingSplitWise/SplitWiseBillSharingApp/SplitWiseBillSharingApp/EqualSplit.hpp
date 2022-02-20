//
//  EqualSplit.hpp
//  SplitWiseBillSharingApp
//
//  Created by khkumari on 16/02/22.
//

#ifndef EqualSplit_hpp
#define EqualSplit_hpp
#include "Split.hpp"
#include <stdio.h>
class EqualSplit : public Split{
public:
    EqualSplit(shared_ptr<User> user) : Split(user){
        
    }
    ~EqualSplit(){
        
    }
};
#endif /* EqualSplit_hpp */
