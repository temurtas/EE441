#include "ee.h"
using namespace std;

/// Methods of EECapsule Class
EECapsule::EECapsule(string name_,int cid_,float latitude_,float longitude_){
    name=name_;
    cid=cid_;
    latitude=latitude_;
    longitude=longitude_;
    pre=this;
    next=this;

}


void printEqualSign(int n) {
    for(int i=0;i<n;i++) {
        cout<<"=";
    }
    cout<<endl;
}

void EECapsule::showInfo(int s){
    printEqualSign(s);
    cout<<"Name       :"<<name<<endl;
    cout<<"CID        :"<<cid<<endl;
    cout<<"Destination:"<<latitude<<","<<longitude<<endl;
    printEqualSign(s);
}
float EECapsule::getLongitude(){
    return longitude;
}
EECapsule* EECapsule::getNext(){
    return next;
}
EECapsule* EECapsule::getPrev(){
    return pre;
}
void EECapsule::setNext(EECapsule *p) {
    next=p;
}
void EECapsule::setPrev(EECapsule *p) {
    pre=p;
}
/// methods of EEAircraft class
EEAircraft::EEAircraft(int direction_,float latitude_,float longitude_) {
    direction=direction_;
    latitude=latitude_;
    longitude=longitude_;
    first=NULL;
    last=NULL;
}

bool EEAircraft::hasCapsule() {

    // if pointers are null then no capsule exists
    if(first==NULL) {
            return 0;
    }

    else {
        return 1;
    }
}

/// find place of aircraft starting point, recursively
// start from least
EECapsule* findAircraft(EECapsule* currentCapsule,const float longitude,const EECapsule* first) {
    float currentCapsuleLongitude=currentCapsule->getLongitude();
    float nextCapsuleLongitude=currentCapsule->getNext()->getLongitude();
    float prevCapsuleLongitude=currentCapsule->getPrev()->getLongitude();
    //cout <<"Longitude:"<<longitude<<" Current:"<<currentCapsuleLongitude<<endl;

    // we reached end point
    if(currentCapsule==first) return currentCapsule;
    else {
        // contunie

        if(currentCapsule->getLongitude()>=longitude) return currentCapsule;
        else return findAircraft(currentCapsule->getNext(),longitude,first);
    }
}

void EEAircraft::setStarting() {
    starting=findAircraft(first->getNext(),longitude,first);
    //cout<<"starting:"<<starting->getLongitude()<<endl;
}

string EECapsule::getName() {
    return name;
}

/// Add the capsule after given capsule
EECapsule* addAfter(EECapsule* currentCapsule,EECapsule* newCapsule) {
    EECapsule* dummyNext;
    dummyNext=currentCapsule->getNext();
    currentCapsule->setNext(newCapsule);
    newCapsule->setPrev(currentCapsule);
    newCapsule->setNext(dummyNext);
    dummyNext->setPrev(newCapsule);
    //cout<<"New capsule Added after:"<<currentCapsule<<" Longitude: "<<(newCapsule->getLongitude())<<endl;
    //cout<<"\t Next:"<<newCapsule->getNext()<<" Pre:"<<newCapsule->getPrev()<<endl;
    return currentCapsule;
}
/// This function add new capsule to the given capsule cycle, recursively
//  Returns the capsule added after
EECapsule* addNewCapsule(EECapsule* currentCapsule,EECapsule* newCapsule,const EECapsule* first) {
    EECapsule* nextCapsule;
    nextCapsule=currentCapsule->getNext();
    float currentCapsuleLongitude=currentCapsule->getLongitude();
    float nextCapsuleLongitude=nextCapsule->getLongitude();
    float newCapsuleLongitude=newCapsule->getLongitude();
    //cout<<"new:"<<newCapsuleLongitude<<" current:"<<currentCapsuleLongitude<<" next:"<<nextCapsuleLongitude<<endl;

    if(newCapsuleLongitude>=currentCapsuleLongitude) {
            //cout<<"greater"<<endl;
        // new capsule longitude is greater than current one
        if(nextCapsuleLongitude<=currentCapsuleLongitude) {
            //cout<<"top"<<endl;
            // current capsule is at top position
            // add new capsule here
            return addAfter(currentCapsule,newCapsule);
        }
        else {
            //cout<<"not top"<<endl;
            // current capsule is not at top
            if(newCapsuleLongitude<=nextCapsuleLongitude) {
                // new capsule is between next and current
                //cout<<"between"<<endl;
                return addAfter(currentCapsule,newCapsule);
            }
            else {

                //cout<<"New capsule will be Added after:"<<currentCapsule->getNext();
                addNewCapsule(currentCapsule->getNext(),newCapsule,first);
            }
        }
    }
    else {
        if(currentCapsule->getPrev()==first) {
            // bottom capsule
            return addAfter(currentCapsule->getPrev(),newCapsule);
        }
        else {
            // new capsule longitude is smaller than current one, add before
            //cout<<"New capsule will be before:"<<currentCapsule->getPrev();

            addNewCapsule(currentCapsule->getPrev(),newCapsule,first);
        }

    }
}


void EEAircraft::integrate(EECapsule* capsule_ ) {
    int sizeString=strlen(capsule_->getName().c_str());
    if(sizeString>(max_string-12)) max_string=sizeString+12;
    if(!hasCapsule()) {
        // No capsule defined yet.
        first=capsule_;
        capsule_->setNext(capsule_);
        capsule_->setPrev(capsule_);
        //cout <<"Added capsule0:"<<capsule_<<endl;
    }
    else {
        //cout <<"Added capsule1:"<<capsule_<<endl;
        EECapsule* addedAfter;
        addedAfter=addNewCapsule(first,capsule_,first);
        if (addedAfter==first && (capsule_->getLongitude()>=first->getLongitude())) {
                first=capsule_;
                //cout<<"First is updated:"<<capsule_<<" Longitude: "<<capsule_->getLongitude()<<endl;
        }
        /*
        if(longitude<=capsule_->getLongitude() && capsule_->getLongitude()>=(first->getPrev()->getLongitude())) {
            first=capsule_;
        }*/
    }
}


void EEAircraft::showInfo(){
    printEqualSign(max_string);
    cout<<"EEAircraft "<<endl;
    cout<<"Destination:"<<latitude<<","<<longitude<<endl;
    cout<<"Direction  :"<<direction<<endl;
    printEqualSign(max_string);
}
/// Drops the capsule depending on direction
EECapsule* EEAircraft::drop() {
    EECapsule* nextCapsule;
    EECapsule* prevCapsule;
    EECapsule* droppedCapsule;
    if(direction==1) {
        droppedCapsule=starting;
        nextCapsule=starting->getNext();
        prevCapsule=starting->getPrev();
        if(nextCapsule!=first || starting!=first) {
            prevCapsule->setNext(nextCapsule);
            nextCapsule->setPrev(prevCapsule);
            starting=nextCapsule;
            if(droppedCapsule==first) first=starting;
        }
        else {
            first=NULL;
        }
        return droppedCapsule;
    }

    else {
    // to the east
        droppedCapsule=starting->getPrev();
        nextCapsule=droppedCapsule->getNext();
        prevCapsule=droppedCapsule->getPrev();
        if(droppedCapsule!=starting) {
            prevCapsule->setNext(starting);
            starting->setPrev(prevCapsule);
            if(droppedCapsule==first) first=nextCapsule;
        }
        else {
            first=NULL;
            starting=NULL;
        }


    return droppedCapsule;
    }

}
