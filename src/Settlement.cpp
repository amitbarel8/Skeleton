#include "Settlement.h"
#include <string>

Settlement::Settlement(const string &name, SettlementType type)
    : name(name), type(type)
{}



const string &Settlement::getName() const {
    return this->name;
}

SettlementType Settlement::getType() const{
    return this->type;
}



 //verify toString       
const string Settlement::toString() const{

//enum class SettlementType {VILLAGE, CITY, METROPOLIS,} ->> reference to the header
    string myType="";
 
    switch(type){
        case SettlementType::VILLAGE: 
            myType = "VILLAGE";
            break;
        case SettlementType::CITY:
            myType = "CITY";
            break;
        case SettlementType::METROPOLIS: 
            myType = "METROPOLIS";
            break;
    }

    return  "name: " + name + "type" + myType;  
}



