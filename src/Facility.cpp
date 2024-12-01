#include "Facility.h"
#include <string>
#include <sstream>

 
 
// FacilityType Constructor:
// variables: name, category, cost (price), and score values.
 FacilityType::FacilityType(const string &name, const FacilityCategory category, const int price, const int lifeQuality_score, const int economy_score, const int environment_score)
    : name(name), 
    // based on the facility category enum
    category(category),
    // how many time units it takes to make the facility operational 
    price(price), 
    lifeQuality_score(lifeQuality_score), 
    economy_score(economy_score), 
    environment_score(environment_score)
 {}

 // getter for name
const string &FacilityType::getName() const{
        return this->name;
}

// getter for cost, price = cost
int FacilityType::getCost() const{
    return this->price;
}

// getter for life quality score
int  FacilityType::getLifeQualityScore() const{
            return this->lifeQuality_score; 
 }

// getter for environment score
int FacilityType::getEnvironmentScore() const{
    return this->environment_score;
}

// getter for economy score
int FacilityType::getEconomyScore() const{
    return this->economy_score;
}

// getter for category
FacilityCategory FacilityType::getCategory() const{
    return this->category;
}

// facility constructor
// variables: facility type variables + settlement name 
Facility::Facility(const string &name, const string &settlementName, const FacilityCategory category, const int price, const int lifeQuality_score, const int economy_score, const int environment_score)
    : FacilityType(name, category, price, lifeQuality_score, economy_score, environment_score), 
    settlementName(settlementName), status(FacilityStatus::UNDER_CONSTRUCTIONS),

    //since in the inialization the cost of the facility is the time left to make it operational timeleft and price holds the same value
    timeLeft(price)
     {
         // if price <= 0 the facility is operational by defualt.
        if(price > 0) {
            this->status = FacilityStatus::UNDER_CONSTRUCTIONS;
        }
        else {
            this->status = FacilityStatus::OPERATIONAL;
            }
     }

// deep copy constructor of facility type object
// variables facility type object and settlement name
Facility::Facility(const FacilityType &type, const string &settlementName)
    : FacilityType(type.getName(), type.getCategory(), type.getCost(), type.getLifeQualityScore(), 
    type.getEconomyScore(), type.getEnvironmentScore()),  settlementName(settlementName),
    status(FacilityStatus::UNDER_CONSTRUCTIONS),
    //since in the inialization the cost of the facility is the time left to make it operational timeleft and price holds the same value
    timeLeft(price)
    {
     // if price <= 0 the facility is operational by defualt.
        if(price > 0) {
            this->status = FacilityStatus::UNDER_CONSTRUCTIONS;
        }
        else {
            this->status = FacilityStatus::OPERATIONAL;
            }
    }

// getter for settlement name
const string &Facility::getSettlementName() const{
    return this->settlementName;
    
}
// getter for time left        
const int Facility::getTimeLeft() const{
    return this->timeLeft;

}

// a step for facility means subtructing 1 time unit from timeleft and if timeLeft == 0 we finished building so we need to change the status as well
// if the price given was 0 or below the status is operational from the constructure so no need to check it again.
FacilityStatus Facility::step(){
    if(this->timeLeft > 0){
       this->timeLeft =  this->timeLeft - 1;
       if(this->timeLeft == 0){
        setStatus(FacilityStatus::OPERATIONAL); 
       }
    }
    return this->status;
}

// modifyinh the status of the facility
void Facility::setStatus(FacilityStatus status){
    this->status = status;
}

// getter for the facility status
const FacilityStatus& Facility::getStatus() const{
    return this->status;
};

       
 //convert the status enum to viable string for the toString method
 // determaning the string using the case method of enum
std::string statusAsString(const FacilityStatus &status){
    string currStatus = "";
        switch (status)
        {
        case FacilityStatus::UNDER_CONSTRUCTIONS:
            currStatus = "UNDER_CONSTRUCTIONS";
            break;
        case FacilityStatus::OPERATIONAL:
            currStatus = "OPERATIONAL";
            break;
        default:
            currStatus = "Unknown status";
            break;
        }
    return currStatus;
}

 //convert the status enum to viable string for the toString method
 // determaning the string using the case method of enum
std::string categoryAsString(const FacilityCategory &category){
     string currCategory = "";
            switch (category)
            {
            case FacilityCategory::LIFE_QUALITY:
                currCategory = "LIFE_QUALITY";
                break;
            
            case FacilityCategory::ECONOMY:
                currCategory = "ECONOMY";
                break;
            case FacilityCategory::ENVIRONMENT:
                currCategory = "ENVIRONMENT";
                break;
            default:
            currCategory = "Unknown";
            break;
        }
        return currCategory;

}
/*
    consider changing the order of the string
*/
const string Facility::toString() const{
std::ostringstream oss; //will be destroyed automatically when we leave the function since it's local
// using the oss method for an efficient string "combiner"
oss << "facility name: " << this->name 
    << " category " << categoryAsString(category) 
    << " price: " << std::to_string(this->price) 
    << " life quality score: " << std::to_string(this->lifeQuality_score) 
    << " economey score: " << std::to_string(this->economy_score) 
    << " environment score: " << std::to_string(this->environment_score) 
    << " settlement name: " << this->settlementName 
    << " status: " 
    << " time left: " << std::to_string(this->timeLeft);
return  oss.str(); 
}
 
