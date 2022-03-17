#include <bits/stdc++.h>
using namespace std;

enum Car_Type
{
   HATCHBACK,
   SUV,
   SEDAN,
   THREEWHEELER,
   TRUCK,
   VAN,
   MOTORCYCLE
};
enum Sort_By
{
   PRICE_LOW_TO_HIGH,
   PRICE_HIGH_TO_LOW,
   DURATION,
   START_TIME
};
class Vehicle
{
   public:
   string vehicle_id;
   Car_Type car_type;
   string plate_number;
   string car_model;
};
map<string, Vehicle>vehicles; // DB Table
class User
{
   public:
   string user_id;
   string name;
   int age;
   string aadhar_number;
   map<string, Vehicle>vehicles;
};
map<string, User>users;
struct Time
{
   int dd;
   int month;
   int yyyy;
   int hh;
   int minute;
   int ss;
};
class Ride
{
   public:
   string ride_id;
   string user_id;
   string vehicle_id;
   string start_location;
   string end_location;
   Time start_time;
   int duration;              // in hours
   int price;
};
map<string, Ride>rides;
map<string, Vehicle> vehicleRegister(Car_Type car_type, string plate_number, string car_model, map<string, Vehicle>& userVehicles)
{
   for(auto v:vehicles)
   {
      if(plate_number==v.second.plate_number)
      {
         cout<<"No 2 vehicles should have same plate_number";
         return {};
      }
   }
   Vehicle vehicle;
   vehicle.car_type=car_type;
   vehicle.plate_number=plate_number;
   vehicle.car_model=car_model;
   vehicle.vehicle_id=vehicles.size()+1;
   userVehicles[vehicle.vehicle_id]=vehicle;
   vehicles[vehicle.vehicle_id]=vehicle;
   return userVehicles;
}
void userRegister(string name, int age, string aadhar_number, map<string, Vehicle>vehicles)
{
   for(auto u:users)
   {
      if(aadhar_number==u.second.aadhar_number)
      {
         cout<<"No 2 users should have same aadhar number";
         return;
      }
   }
   User user;
   user.name=name;
   user.age=age;
   user.aadhar_number=aadhar_number;
   user.vehicles=vehicles;
   user.user_id=users.size()+1;
   users[user.user_id]=user;
}
void createRide(string user_id, string vehicle_id, string start_location, string end_location, Time start_time, int duration, int price)
{
   if(users.find(user_id)==users.end() || vehicles.find(vehicle_id)==vehicles.end())
   {
      cout<<"Vehicle_id and user_id should be valid";
      return;
   }
   
   if(users[user_id].vehicles.find(vehicle_id)==users[user_id].vehicles.end())
   {
      cout<<"vehicle id given in request should belong to the given user only";
      return;
   }
   Ride ride;
   ride.user_id=user_id;
   ride.vehicle_id=vehicle_id;
   ride.start_location=start_location;
   ride.end_location=end_location;
   ride.start_time=start_time;
   ride.duration=duration;
   ride.price=price;
   ride.ride_id=rides.size()+1;
   rides[ride.ride_id]=ride;
}
void fetchRides(string start_location, string end_location, Sort_By sort_by)
{
   switch(sort_by)
   {
      case PRICE_LOW_TO_HIGH:
      
         vector< pair<int, Ride> >temp ;
         for(auto ride:rides)
         {
            temp.push_back({(ride.second).price, ride.second});
         }
         sort(temp.begin(), temp.end());
         for(auto t:temp)
         {
            if( (start_location!="" && end_location!="") )
            {
               if(t.second.start_location==start_location && t.second.end_location==end_location)
               {
                  cout<<"ride_id:"<<t.second.ride_id<<endl;
                  cout<<"start_location:"<<t.second.start_location<<endl;
                  cout<<"end_location:"<<t.second.end_location<<endl;
                  //cout<<"start_time:"<<t.second.start_time.dd<<"-"<<t.start_time.month<<"-"<<t.start_time.yyyy<<" "<<t.start_time.hh<<":"<<t.start_time.minute<<":"<<t.start_time.ss<<endl;
                  cout<<"expected_duration:"<<t.second.duration<<endl;
                  cout<<"price:"<<t.second.price<<endl;
               }
            }
            else if(start_location!="" && end_location=="")
            {
               
            }
            else if(start_location=="" && end_location!="")
            {
               
            }
            else
            {
               cout<<"ride_id:"<<t.second.ride_id<<endl;
               cout<<"start_location:"<<t.second.start_location<<endl;
               cout<<"end_location:"<<t.second.end_location<<endl;
               //cout<<"start_time:"<<t.second.start_time.dd<<"-"<<t.start_time.month<<"-"<<t.start_time.yyyy<<" "<<t.start_time.hh<<":"<<t.start_time.minute<<":"<<t.start_time.ss<<endl;
               cout<<"expected_duration:"<<t.second.duration<<endl;
               cout<<"price:"<<t.second.price<<endl;
            }
         }
      
         break;
      
      case PRICE_HIGH_TO_LOW:
      
         break;
         
      case DURATION:
      
         break;
         
      case START_TIME:
      
         break;
         
      default:
            
            for(auto t:temp)
            {
               cout<<"ride_id:"<<t.second.ride_id<<endl;
               cout<<"start_location:"<<t.second.start_location<<endl;
               cout<<"end_location:"<<t.second.end_location<<endl;
               //cout<<"start_time:"<<t.second.start_time.dd<<"-"<<t.start_time.month<<"-"<<t.start_time.yyyy<<" "<<t.start_time.hh<<":"<<t.start_time.minute<<":"<<t.start_time.ss<<endl;
               cout<<"expected_duration:"<<t.second.duration<<endl;
               cout<<"price:"<<t.second.price<<endl;
            }
            
         break;
   }
}
int main() {
	string name;
   int age;
   string aadhar_number;
	
	return 0;
}
