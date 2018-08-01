//
//  ApiCaller.hpp
//  ParkSuggest
//
//  Created by Spencer Gilbert on 7/29/18.
//

#ifndef ApiCaller_hpp
#define ApiCaller_hpp

#include <stdio.h>
#include <string>
#include <vector>

class ApiCaller {
public:
    //Default constructor
    ApiCaller();
    
    //Vectors for the class
    std::vector<std::string> currentInformation;
    std::vector<std::string> lastCallInformation;
    
    //API call read-in data
    std::vector<std::string> readIn(std::string callType);
    
    //API information retrieval
    std::vector<std::string> getOutput();
};

#endif /* ApiCaller_hpp */
