#include <iostream>
#include "eeAircraft.h"
using namespace std;

eeAircraft::eeAircraft(int Lattitude,int Longitude,int Direction)
{
    //ctor
    lattitude=Lattitude;
    longitude=Longitude;
    direction=Direction;
    head=NULL;
}

void eeAircraft::Integrate(eeCapsule* obj)
{

    if(head==NULL) //list is empty
    {
        head=obj;
        return;
    }
    else if (head->next==head) // there exists only one item in list
    {
        head->next=obj;
        head->prev=obj;
        obj->prev=head;
        obj->next=head;
        if(head->Getlongitude() > obj->Getlongitude()) head=obj;
        return;
    }
    else    //there exists 2 or more item in list so insert them with order
    {
        if(obj->Getlongitude() > head->Getlongitude() ) // no need to modify head
        {
            eeCapsule* temp=head;
            while(temp->next->Getlongitude() < obj->Getlongitude())
            {
                if(temp->next == head) // condition for not being infinite loop (assume we insert max input of list)
                {
                    break;
                }
                else
                {
                    temp=temp->next;
                }
            }
            obj->next=temp->next; // INSERTING OBJECT IN LIST
            temp->next=obj;
            obj->next->prev=obj;
            obj->prev=temp;
        }
        else //  HAVE TO MODIFY THE HEAD POINTER SINCE MINIMUM INPUT IS COMMING
        {
            obj->prev=head->prev;
            head->prev=obj;
            obj->prev->next=obj;
            obj->next=head;
            head=obj;

        }
    }
};

void eeAircraft::Updatehead()
{   if(head != NULL)
    {
        if(direction==1)
        {
            while (head->Getlongitude()<longitude)
            {
                head=head->next;
            }
        }
        else if (direction==-1)
        {
            head=head->prev;
            while(head->Getlongitude()>longitude)
            {
                head=head->prev;
            }
        }
    }
};

eeCapsule* eeAircraft::Drop()
{   eeCapsule* temp=head;
    if(head==NULL)
    {
        return NULL;

    }
    else if (temp->next==temp)
    {
        head=NULL;
        return temp;
    }
    else
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        if(direction==1)
        head=temp->next;
        else if (direction==-1)
        head=temp->prev;
        temp->next=temp;
        temp->prev=temp;
        return temp;
    }

};

void eeAircraft::displayflight()
{
  cout<<"Current Aircraft:"<<endl;
  cout<<"EEAircraft"<<endl;
  cout<<"Departure:"<<"    "<<(lattitude>90 ? lattitude-180:lattitude)<<" "<<(longitude>180 ? longitude-360:longitude)<<endl;
  cout<<"Direction:"<<"    "<<direction<<endl;
if(head !=NULL)
{
  eeCapsule* temp=head;

  if(direction==1)
  {
      temp->displaycapsule();
      temp=temp->next;
      while(temp != head)
      {
          temp->displaycapsule();
          temp=temp->next;
      }

  }
  else if (direction==-1)
  {
      temp->displaycapsule();
      temp=temp->prev;
      while(temp != head)
      {
          temp->displaycapsule();
          temp=temp->prev;
      }
  }

}

};
