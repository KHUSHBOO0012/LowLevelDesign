//
//  User.cpp
//  SplitWiseBillSharingApp
//
//  Created by khkumari on 16/02/22.
//

#include "User.hpp"

User::User(const string id, const string name, const string email, const string phone):id(id), name(name), email(email), phone(phone){
    
}
string User::getName() const{
    return name;
}

string User::getId() const{
    return id;
}
