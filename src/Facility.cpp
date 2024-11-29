#include "Facility.h"
#include <string>

 
 
 
 FacilityType::FacilityType(const string &name, const FacilityCategory category, const int price, const int lifeQuality_score, const int economy_score, const int environment_score)
    : name(name), 
    category(category), 
    price(price), 
    lifeQuality_score(lifeQuality_score), 
    economy_score(economy_score), 
    environment_score(environment_score)
 {}

 


const string &FacilityType::getName() const{
        return this->name;
}


int FacilityType::getCost() const{
    return this->price;
}



int  FacilityType::getLifeQualityScore() const{
            return this->lifeQuality_score; 
 }





int FacilityType::getEnvironmentScore() const{
    return this->environment_score;
}



int FacilityType::getEconomyScore() const{
    return this->economy_score;
}


FacilityCategory FacilityType::getCategory() const{
    return this->category;
}





Facility::Facility(const string &name, const string &settlementName, const FacilityCategory category, const int price, const int lifeQuality_score, const int economy_score, const int environment_score)
    : FacilityType(name, category, price, lifeQuality_score, economy_score, environment_score), 
    settlementName(settlementName),
    status(FacilityStatus::UNDER_CONSTRUCTIONS), 
    timeLeft(price){}


Facility::Facility(const FacilityType &type, const string &settlementName)
    : FacilityType(type.getName(), type.getCategory(), type.getCost(), type.getLifeQualityScore(), 
    type.getEconomyScore(), type.getEnvironmentScore()),  settlementName(settlementName),
    status(FacilityStatus::UNDER_CONSTRUCTIONS), timeLeft(price)
{}


const string &Facility::getSettlementName() const{
    return this->settlementName;
    
}
        
const int Facility::getTimeLeft() const{
    return this->timeLeft;

}

FacilityStatus Facility::step(){
    if(this->timeLeft > 0){
       this->timeLeft =  this->timeLeft - 1;
       if(this->timeLeft == 0){
        setStatus(FacilityStatus::OPERATIONAL); 
       }
    }
    return this->status;
}

void Facility::setStatus(FacilityStatus status){
    this->status = status;
}


const FacilityStatus& Facility::getStatus() const{
    return this->status;
};

//need to finish toString
        const string Facility::toString() const{
            string category1 = "";
            switch (category)
            {
            case FacilityCategory::LIFE_QUALITY:
                category1 = "LIFE_QUALITY";
                break;
            
            case FacilityCategory::ECONOMY:
                category1 = "ECONOMY";
                break;
            case FacilityCategory::ENVIRONMENT:
                category1 = "ENVIRONMENT";
                break;
            return this->name;
        }


 
