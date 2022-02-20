//
//  User.hpp
//  SplitWiseBillSharingApp
//
//  Created by khkumari on 16/02/22.
//

#ifndef User_hpp
#define User_hpp

#include <stdio.h>
#include <string>
using namespace std;

class User{
private:
    string id;
    string name;
    string email;
    string phone;
public:
    User(const string id, const string name, const string email, const string phone);
    string getName() const;
    string getId() const;
    string getEmail() const;
    string getPhone() const;
    
    void setName(string name);
    void setId(string id);
    void setEmail(string email) ;
    void setPhone(string phone);
};

#endif /* User_hpp */
