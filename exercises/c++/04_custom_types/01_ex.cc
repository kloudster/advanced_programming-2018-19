#include <array>
#include <iostream>
#include <vector>


enum class Month { Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

class date {
  int ay, ear;
  Month onth;
  
public:
  date (const int a, const Month b, const int c) : ay{a}, onth{b}, ear{c} {}
  int day () const {return ay;}
  int month () const {return int(onth);}
  int year () const { return ear;}
  
  void print_date() const {
    std::cout << day() << " " << month() << " " << year() << std::endl;
  }  

  void add_days (const unsigned int a){
    ay+=a;
    while (check_date());
  }
  bool check_date();

};   

bool operator == (const date& a, const date& b);
bool operator != (const date a, const date b);  


int main() {
  date oggi{25, Month::Oct, 2018}, noggi{24, Month::Oct, 2020};

  oggi.print_date();
  std::cout <<"Dovrebbe dare false " << (oggi==noggi)<< std::endl;
  oggi.add_days(730);
  oggi.print_date();
  std::cout <<"Dovrebbe dare true " << (oggi==noggi)<< std::endl;
}



bool date::check_date(){
  switch (month()){
  case 1: case 3: case 5:
  case 7: case 8: case 10:
  case 12:
    if (day()<=31) {
      return 0;
    } 
    else {
      if (month()==12) {
	onth=Month::Jan;
	ear++;
      } 
      else {
	onth=static_cast<Month>(month()+1);
      }
      ay-=31;
      return 1;
    }
    break;
    
  case 4: case 6: case 9:
  case 11:
    if (day()<=30) {
      return 0;
    } 
    else {
	onth=static_cast<Month>(month()+1);
	ay-=30;
	return 1;
    }
    
    break;
  default:
    if (year()%4==0) {
      if (day()<=29){
	return 0;
      } 
      else {
	onth=static_cast<Month>(month()+1);
	ay-=29;
	return 1;
      }
    }
    else{
      if (day()<=28){
	return 0;
      } 
      else {
	onth=static_cast<Month>(month()+1);
	ay-=28;
	return 1;
      }
    }
    
    break;
  }
}


bool operator == (const date& a, const date& b)  {
  return ((a.day()==b.day())&&(a.month()==b.month())&&(a.year()==b.year()));
}

bool operator != (const date a, const date b)  {
  return ! (a==b);
}
