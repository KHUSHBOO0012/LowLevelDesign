//
//  PercentSplit.hpp
//  SplitWiseBillSharingApp
//
//  Created by khkumari on 16/02/22.
//

#ifndef PercentSplit_hpp
#define PercentSplit_hpp

#include <stdio.h>
#include "Split.hpp"

class PercentSplit: public Split{
public:
    double percent;
    PercentSplit(shared_ptr<User> user, double percent) : Split(user), percent(percent){
        
    }
    double getPercent(){
        return percent;
    }
    ~PercentSplit(){
        
    }
};
#endif /* PercentSplit_hpp */
