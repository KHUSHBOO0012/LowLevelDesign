//
//  Utility.hpp
//  SplitWiseBillSharingApp
//
//  Created by khkumari on 16/02/22.
//

#ifndef Utility_hpp
#define Utility_hpp

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
class Utility{
public:
    static vector<string> split(string str, char del){
        // declaring temp string to store the curr "word" upto del
        string temp = "";
        vector<string> ans;
          for(int i=0; i<(int)str.size(); i++){
            // If cur char is not del, then append it to the cur "word", otherwise
              // you have completed the word, print it, and start a new word.
             if(str[i] != del){
                temp += str[i];
            }
              else{
                  ans.push_back(temp);
                  temp = "";
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
#endif /* Utility_hpp */
