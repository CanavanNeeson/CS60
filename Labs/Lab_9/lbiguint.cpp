 #include "lbiguint.h"

#include <cassert>
#include <iostream>
#include <sstream>
#include <istream>

lbiguint::lbiguint()
{
	head = tail = new node(0, nullptr);
}

lbiguint::lbiguint (const std::string & s)
{
	if (s.length() > 0) {
		head = tail = new node(s[0] - '0', nullptr);
		for (int i = 1; i < s.length(); i++) {
			head = new node(s[i] - '0', head);
		}
	} else {
		std::cout << "Error! String has zero length.\n";
	}
}

lbiguint::~lbiguint()
{
	node *temp;
	while (head != nullptr) {
		head->set_data(0);
		temp = head->link();
		delete head;
		head = temp;
	}
	tail = nullptr;
}

std::size_t lbiguint::size() const {
	std::size_t count = 1;
	node * temp = head;
	while (temp->link() != nullptr) {
		count++;
		temp = temp->link();
	}
	return count;
}



node::value_type lbiguint::operator [](std::size_t pos) const
{
	//if (pos == 0) return head->data();
	
	std::size_t count = 0;
	node *temp = head;
	while (count < pos) {
		if (temp == nullptr) return 0;
		count++;
		temp = temp -> link();
	}
	return temp->data();
}
// 
// 
// 
//  int biguint::compare(const biguint & b) const{
//      for(std::size_t i =CAPACITY-1; i>=0; --i){
//          if(_data[i]>b._data[i])
//              return 1;
//          else if (_data[i]<b._data[i])
//              return -1;
// 
//      }
//      return 0;
//  }
// 
// 
// 
//  void biguint::operator += (const biguint & b){
//      int carry = 0;
//      int next = 0;
//      for(std::size_t i=0; i<CAPACITY; ++i){
//          next = carry+_data[i]+b._data[i];
//          _data[i]=next%10;
//         carry=next/10;
//      }
//  }
//  std::string biguint::toStdString() const
//  {
//      std::stringstream ss;
//      ss << *this;
//      return ss.str();
//  }//We haven't talked about stringstreams; just ignore this, I was being lazy.
std::ostream& operator << (std::ostream& os, const lbiguint & b)
{
	node *temp = b.head;
	while (temp != nullptr) {
		os << temp->data();
		temp = temp->link();
	}
	return os;
}

// void lbiguint::operator =(const lbiguint& l)
// {
// 	this->~lbiguint;
// 	
// 	head = tail = l.head;
// 	node * temp = l.head;
// 	while (temp != nullptr) {
// 		temp->set_link(new node(
// }


// 
//  std::istream & operator >> (std::istream & is, biguint & b)
//  {
//      std::string s;
//      is >> s;
//      b = biguint(s);
//      return is;
// 
// 
//  }
// 
//  bool operator <(const biguint& a, const biguint& b){
//      return (a.compare(b)==-1);
//  }
// 
//  bool operator <= (const biguint & b1, const biguint & b2)
//  {
//      return (b1.compare(b2) <= 0);
//  }
// 
//  bool operator == (const biguint & b1, const biguint & b2)
//  {
//      return (b1.compare(b2) == 0);
//  }
// 
//  bool operator != (const biguint & b1, const biguint & b2)
//  {
//      return (b1.compare(b2) != 0);
//  }
// 
// //You do > and >=
