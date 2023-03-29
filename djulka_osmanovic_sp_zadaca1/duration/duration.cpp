#include<iostream>
#include "duration.hpp"

Duration::Duration() {};
Duration::Duration(int sec){
  s_ = sec%60;
  m_ = sec/60;
  while(m_>=60) {
    m_ = m_ - 60;
    h_++;
  }
}

Duration::Duration(int h, int m, int s) : s_{s}, m_{m}, h_{h} {
  if(m >= 60 || s >= 60 || h_ < 0 || m_ < 0 || s_ < 0) throw std::out_of_range("Izvan granica!");
}

Duration::Duration(const std::string& s){
  h_ = (s[0] - '0')*10 + s[1] - '0';
  m_ = (s[3] - '0')*10 + s[4] - '0';
  s_ = (s[6] - '0')*10 + s[7] - '0';
}

Duration::Duration(const Duration& o) : s_{o.s_}, m_{o.m_}, h_{o.h_} {}

Duration::Duration(Duration&& o) : s_{o.s_}, m_{o.m_}, h_{o.h_} {
  o.s_ = 0;
  o.m_ = 0;
  o.h_ = 0;
}

Duration& Duration::operator=(const Duration& o){
  s_ = o.s_;
  m_ = o.m_;
  h_ = o.h_;
  return *this;
}

Duration& Duration::operator=(Duration&& o){
  s_ = o.s_;
  m_ = o.m_;
  h_ = o.h_;
  o.s_ = 0;
  o.m_ = 0;
  o.h_ = 0;
  return *this;
}

Duration& Duration::set_s(int s){
  if(s >= 60 || s < 0) throw std::out_of_range("Izvan granica");
  s_ = s;
  return *this;
}

Duration& Duration::set_m(int m){
  if(m >= 60 || m < 0) throw std::out_of_range("Izvan granica!");
  m_ = m;
  return *this;
}

Duration& Duration::set_h(int h){
  if(h < 0) throw std::out_of_range("Izvan granica!");
  h_ = h;
  return *this;
}

bool Duration::operator==(const Duration& o) const {
  return s_==o.s_ && m_==o.m_ && h_==o.h_;
}

bool Duration::operator!=(const Duration& o) const {
  return !(*this == o);
}

bool Duration::operator<(const Duration& o) const {
  if(h_ < o.h_){
    return true;
  } else if(h_ > o.h_){
    return false;
  } else {
    if(m_ < o.m_){
      return true;
      } else if(m_ > o.m_){
      return false;
      } else{
        return s_ < o.s_;
      }
    }
}

bool Duration::operator>(const Duration& o) const {
  return !(*this < o) && *this!=o;
}

bool Duration::operator<=(const Duration& o) const {
  return *this < o || *this == o;
}

bool Duration::operator>=(const Duration& o) const {
  return *this > o || *this == o;
}

Duration::operator bool() const {
  return s_!=0 || m_!=0 || h_!=0;
}

bool Duration::operator!() const {
  return !(bool(*this));
}

Duration Duration::operator+(const Duration& o) const {
  int seconds = s_ + o.s_ + (m_ + o.m_)*60 + (h_ + o.h_)*3600;
  return Duration{seconds};
}

Duration Duration::operator-(const Duration& o) const {
  if(o > *this) throw std::out_of_range("Ne moze se oduzimati veci broj od manjeg!");
  int seconds = s_ - o.s_ + (m_ - o.m_)*60 + (h_ - o.h_)*3600;
  return Duration{seconds};
}

Duration Duration::operator*(int n) const {
  int seconds = s_*n + m_*n*60 + h_*n*3600;
  return Duration{seconds};
}

Duration Duration::operator/(int n) const {
  int seconds = s_/n + m_*60/n + h_*3600/n;
  return Duration{seconds};
}

Duration& Duration::operator+=(const Duration& o){
  int seconds = s_ + o.s_ + (m_ + o.m_)*60 + (h_ + o.h_)*3600;
  *this = Duration{seconds};
  return *this;
}

Duration& Duration::operator-=(const Duration& o){
  if(o > *this) throw std::out_of_range("Ne moze se oduzimati veci broj od manjeg!");
  int seconds = s_ - o.s_ + (m_ - o.m_)*60 + (h_ - o.h_)*3600;
  *this = Duration{seconds};
  return *this;
}

Duration& Duration::operator*=(int n){
  int seconds = s_*n + m_*n*60 + h_*n*3600;
  *this = Duration{seconds};
  return *this;
}

Duration& Duration::operator/=(int n){
  int seconds = s_/n + m_*60/n + h_*3600/n;
  *this = Duration{seconds};
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Duration& o){
  if(o.get_h() < 10) os << "0";
  os << o.get_h() << ":";
  if(o.get_m() < 10) os << "0";
  os << o.get_m() << ":";
  if(o.get_s() < 10) os << "0";
  os << o.get_s();
  return os;
}

std::istream& operator>>(std::istream& is, Duration& o){
  std::string s;
  is >> s;
  if(s.size() != 8) throw std::invalid_argument("Nepravilan unos");
  o.set_h(10*(s[0] - '0') + s[1] - '0');
  o.set_m(10*(s[3] - '0') + s[4] - '0');
  o.set_s(10*(s[6] - '0') + s[7] - '0');
  return is;
}
