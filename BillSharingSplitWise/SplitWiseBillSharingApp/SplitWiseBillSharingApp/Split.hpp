//
//  Split.hpp
//  SplitWiseBillSharingApp
//
//  Created by khkumari on 16/02/22.
//

#ifndef Split_hpp
#define Split_hpp
#include "User.hpp"
#include <stdio.h>
#include <memory>

class Split{
private:
    shared_ptr<User> user;
    
public:
    double amount;
    Split(shared_ptr<User> user) : user(user){
        
    }
    virtual ~Split()=0;
    double getAmount() const{
        return amount;
    }
    void setAmount(double amount){
        this->amount = amount;
    }
    shared_ptr<User> getUser() const{
        return user;
    }
    void setUser(shared_ptr<User> user){
        this->user = user;
    }
};

#endif /* Split_hpp */
