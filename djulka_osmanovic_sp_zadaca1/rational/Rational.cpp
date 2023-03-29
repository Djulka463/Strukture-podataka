#include "Rational.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cmath>
#include <sstream>



Rational::Rational(int numerator, int denominator) : numerator_{numerator}, denominator_{denominator}{
  if(denominator == 0) throw std::invalid_argument("Nevalidan argument");
}

Rational::Rational(const char* rational){
  std::string s{rational};
  bool ispravno = true;
  std::istringstream my_stream(s);
  char c;
  int num;
  int denom;
  int counter = 0;
  if(my_stream >> num){
    numerator_ = num;
    while(my_stream >> c){
      ++counter;
      if(my_stream >> denom){
        denominator_ = denom;
        ispravno = (c == '/') && (denom != 0);
      }else {
        ispravno = false;
      }
    }
  } else{
    throw std::invalid_argument("Pogresan unos");
  }
  if (!ispravno || counter > 1) throw std::invalid_argument("Pogresan unos");
}

Rational::Rational(const std::string& s){
   bool ispravno = true;
  std::istringstream my_stream(s);
  char c;
  int num;
  int denom;
  int counter = 0;
  if(my_stream >> num){
    numerator_ = num;
    while(my_stream >> c){
      ++counter;
      if(my_stream >> denom){
        denominator_ = denom;
        ispravno = (c == '/') && (denom != 0);
      }else {
        ispravno = false;
      }
    }
  } else{
    throw std::invalid_argument("Pogresan unos");
  }
  if (!ispravno || counter > 1) throw std::invalid_argument("Pogresan unos");
}

Rational::Rational(const Rational& rational) : numerator_{rational.numerator_}, denominator_{rational.denominator_}{}

Rational::Rational(Rational&& rational) : numerator_{rational.numerator_}, denominator_{rational.denominator_} {
  rational.numerator_ = 0;
  rational.denominator_ = 1;
}

Rational& Rational::operator=(const Rational& rational){
  numerator_ = rational.numerator_;
  denominator_ = rational.denominator_;
  return *this;
}

Rational& Rational::operator=(Rational&& rational){
  numerator_ = rational.numerator_;
  denominator_ = rational.denominator_;
  rational.numerator_ = 0;
  rational.denominator_ = 1;
  return *this;
}

Rational Rational::operator+(const Rational& rational) const {
  int num = rational.denominator_*numerator_ + rational.numerator_*denominator_;
  int denom = rational.denominator_ * denominator_;
  int n = gcd(num, denom);
  if(n == 0) throw std::invalid_argument("Ne moze se dijeliti sa nulom");
  return Rational{num/n, denom/n};
}

Rational Rational::operator-(const Rational& rational) const {
  int num = rational.denominator_*numerator_ - rational.numerator_*denominator_;
  int denom = rational.denominator_ * denominator_;
  int n = gcd(num, denom);
  if(n == 0) throw std::invalid_argument("Ne moze se dijeliti sa nulom");
  return Rational{num/n, denom/n};
}

Rational Rational::operator+(int numerator) const {
  int num = numerator_ + numerator*denominator_;
  int denom = denominator_;
  int n = gcd(num, denom);
  if(n == 0) throw std::invalid_argument("Ne moze se dijeliti sa nulom");
  return Rational{num/n, denom/n};
}

Rational Rational::operator-(int numerator) const {
  int num = numerator_ - numerator*denominator_;
  int denom = denominator_;
  int n = gcd(num, denom);
  if(n == 0) throw std::invalid_argument("Ne moze se dijeliti sa nulom");
  return Rational{num/n, denom/n};
}

Rational Rational::operator*(const Rational& rational) const {
  int num = numerator_*rational.numerator_;
  int denom = denominator_*rational.denominator_;
  int n = gcd(num, denom);
  if(n == 0) throw std::invalid_argument("Ne moze se dijeliti sa nulom");
  return Rational{num/n, denom/n};
}

Rational Rational::operator*(int numerator) const {
  int num = numerator_*numerator;
  int denom = denominator_;
  int n = gcd(num, denom);
  if(n == 0) throw std::invalid_argument("Ne moze se dijeliti sa nulom");
  return Rational{num/n, denom/n};
}

Rational Rational::operator/(const Rational& rational) const {
  int num = numerator_*rational.denominator_;
  int denom = denominator_*rational.numerator_;
  int n = gcd(num, denom);
  if(n == 0) throw std::invalid_argument("Ne moze se dijeliti sa nulom");
  return Rational{num/n, denom/n};
}

Rational Rational::operator/(int numerator) const {
  if(numerator==0) throw std::invalid_argument("Ne moze se dijeliti sa nulom");
  int num = numerator_;
  int denom = denominator_*numerator;
  int n = gcd(num, denom);
  if(n == 0) throw std::invalid_argument("Ne moze se dijeliti sa nulom");
  return Rational{num/n, denom/n};
}

Rational Rational::operator^(int step) const {
  int num = std::pow(numerator_, step);
  int denom = std::pow(denominator_, step);
  int n = gcd(num, denom);
  if(n == 0) throw std::invalid_argument("Ne moze se dijeliti sa nulom");
  return Rational{num/n, denom/n};
}

Rational& Rational::operator++(){
  *this = *this + 1; 
  return *this;
}

Rational Rational::operator++(int){
  Rational temp{*this};
  *this = *this + 1; 
  return temp;
}

Rational& Rational::operator--(){
  *this = *this - 1; 
  return *this;
}

Rational Rational::operator--(int){
  Rational temp{*this};
  *this = *this - 1; 
  return temp;
}

bool Rational::operator==(const Rational& rational) const {
  int m = gcd(numerator_, denominator_);
  int n = gcd(rational.numerator_, rational.denominator_);
  if(n == 0 || m == 0) throw std::invalid_argument("Ne moze se dijeliti sa nulom");
  return numerator_/m==rational.numerator_/n && denominator_/m==rational.denominator_/n;
}

bool Rational::operator==(const char* ration) const {
  Rational rational{ration};
  int m = gcd(numerator_, denominator_);
  int n = gcd(rational.numerator_, rational.denominator_);
  if(n == 0 || m == 0) throw std::invalid_argument("Ne moze se dijeliti sa nulom");
  return numerator_/m==rational.numerator_/n && denominator_/m==rational.denominator_/n;
}

bool Rational::operator!=(const Rational& rational) const {
  return !(*this == rational);
}

bool Rational::operator!=(const char* ration) const {
  Rational rational{ration};
  return !(*this == rational);
}

std::ostream& operator<<(std::ostream& os, const Rational& rational){
  int n = gcd(rational.numerator(), rational.denominator());
  os << rational.numerator()/n;
  if(rational.denominator()/n != 1){
  os << '/' << rational.denominator()/n;
  }
  return os;
}

int gcd(const int num, const int denom){
  int numerator = num;
  int denominator = denom;
  int shift;
  
  if(numerator == 0) return denominator;
  if(numerator < 0) numerator = 0 - numerator;
  if(denominator < 0) denominator = 0 - denominator;

  for(shift = 0; ((numerator | denominator) & 1) == 0; ++shift){
    numerator >>= 1;
    denominator >>= 1;
  }
  while((numerator & 1) == 0){
    numerator >>= 1;
  }
  while(denominator != 0){
    while((denominator & 1) == 0){
      denominator >>= 1;
    }
    if(numerator > denominator){
      std::swap(numerator, denominator);
    }
    denominator -= numerator;
  }

  return numerator << shift;
}
