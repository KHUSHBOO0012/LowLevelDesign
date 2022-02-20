//
//  ExpenseMetaData.hpp
//  SplitWiseBillSharingApp
//
//  Created by khkumari on 16/02/22.
//

#ifndef ExpenseMetaData_hpp
#define ExpenseMetaData_hpp

#include <stdio.h>
#include "string"
using namespace std;
class ExpenseMetaData{
private:
    string name;
    string imgUrl;
    string notes;
public:
    ExpenseMetaData(string name, string imgUrl, string notes) : name(name), imgUrl(imgUrl), notes(notes){
        
    }
};
#endif /* ExpenseMetaData_hpp */
