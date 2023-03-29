#pragma once
#include<iostream>

class Duration {
  private:
    int s_ = 0;
    int m_ = 0;
    int h_ = 0;

  public:
    Duration();
    Duration(int sec);
    Duration(int h, int m, int s);
    Duration(const std::string& s);
    Duration(const Duration& o);
    Duration(Duration&& o);
    Duration& operator=(const Duration& o);
    Duration& operator=(Duration&& o);

    int get_s() const{ return s_; };
    int get_m() const{ return m_; };
    int get_h() const{ return h_; };

    Duration& set_s(int s);
    Duration& set_m(int m);
    Duration& set_h(int h);

    bool operator==(const Duration& o) const;
    bool operator!=(const Duration& o) const;
    bool operator<(const Duration& o) const;
    bool operator>(const Duration& o) const;
    bool operator<=(const Duration& o) const;
    bool operator>=(const Duration& o) const;

    operator bool() const;
    bool operator!() const;
    
    Duration operator+(const Duration& o) const;
    Duration operator-(const Duration& o) const;
    Duration operator*(int n) const;
    Duration operator/(int n) const;
    Duration& operator+=(const Duration& o);
    Duration& operator-=(const Duration& o);
    Duration& operator*=(int n);
    Duration& operator/=(int n);

};

std::ostream& operator<<(std::ostream& os, const Duration& o);
std::istream& operator>>(std::istream& is, Duration& o);
