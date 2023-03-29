#include "Rational.hpp"
#include <vector>
#include <iostream>

int main(int argc, char* argv[]) {
  std::vector<std::string> stringovi;

  try {
    std::string s;
    std::cout << "Unos: " << std::endl;
    while(std::cin >> s) stringovi.push_back(s);

    std::cout << "\nDefault konstruktor" << std::endl;
    Rational r1;
    std::cout << r1 << std::endl;  
    
    std::cout << "\nKonstruktor parametriziran sa dva cijela broja" << std::endl;
    Rational r2{1, 2};
    std::cout << "Rational(1/2): " << r2 << std::endl;
  
    std::cout << "\nKonstruktor parametriziran sa nizom karaktera" << std::endl;
    Rational r3{"2/1"};
    std::cout << "Rational(2/1): " << r3 << std::endl;
  
    std::cout << "\nKonstruktor parametriziran sa std::string" << std::endl;
    Rational r4{std::string{"6/4"}};
    std::cout << "Rational(6/4): " << r4 << std::endl;
  
    std::cout << "\nCopy konstruktor" << std::endl;
    Rational r5{r4};
    std::cout << "Rational(6/4): " << r5 << std::endl;
    std::cout << "Rational(6/4): " << r4 << std::endl;

    std::cout << "\nMove konstruktor" << std::endl;
    Rational r6{std::move(r4)};
    std::cout << "Rational(6/4): " << r6 << std::endl;
    std::cout << "Rational(moved): " << r4 << std::endl;

    std::cout << "\nOperator =" << std::endl;
    Rational ls{9, 3};
    Rational rs{7, 2};
    ls = rs;
    std::cout << "ls{9, 3} = rs{7, 2}" << std::endl;
    std::cout << "ls: " << ls << std::endl;
    std::cout << "rs: " << rs << std::endl;

    std::cout << "\nMove operator =" << std::endl;
    ls = std::move(rs);
    std::cout << "ls{9, 3} = std::move(rs{7, 1})" << std::endl;
    std::cout << "ls: " << ls << std::endl;
    std::cout << "rs: " << rs << std::endl;
    
    rs = Rational{11, 5};
    std::cout << "\nrs{11, 5}" << std::endl;
    std::cout << "ls + rs" << std::endl;
    std::cout << ls + rs << std::endl;
    
    std::cout << "\nls - rs" << std::endl;
    std::cout << ls - rs << std::endl;
    
    std::cout << "\nls * rs" << std::endl;
    std::cout << ls * rs << std::endl;
    
    std::cout << "\nls / rs" << std::endl;
    std::cout << ls / rs << std::endl;
    
    std::cout << "\nls + 5" << std::endl;
    std::cout << ls + 5 << std::endl;

    std::cout << "\nls - 5" << std::endl;
    std::cout << ls - 5 << std::endl;

    std::cout << "\nls * 5" << std::endl;
    std::cout << ls * 5 << std::endl;

    std::cout << "\nls / 5" << std::endl;
    std::cout << ls / 5 << std::endl;

    std::cout << "\nls ^ 2" << std::endl;
    std::cout << ls.operator^(2) << std::endl;

    std::cout << "\nls++" << std::endl;
    std::cout << ls++ << std::endl;

    std::cout << "\n++ls" << std::endl;
    std::cout << ++ls << std::endl;

    std::cout << "\nls--" << std::endl;
    std::cout << ls-- << std::endl;

    std::cout << "\n--ls" << std::endl;
    std::cout << --ls << std::endl;

    std::cout << "\nls == rs" << std::endl;
    std::cout << ls.operator==(rs) << std::endl;

    std::cout << "\nls == ls" << std::endl;
    std::cout << ls.operator==(ls) << std::endl;

    std::cout << "\nls == 7/2" << std::endl;
    std::cout << ls.operator==("7/2") << std::endl;

    std::cout << "\nls == 8/2" << std::endl;
    std::cout << ls.operator==("8/2") << std::endl;

    std::cout << "\nls != rs" << std::endl;
    std::cout << ls.operator!=(rs) << std::endl;

    std::cout << "\nls != ls" << std::endl;
    std::cout << ls.operator!=(ls) << std::endl;

    std::cout << "\nls != 7/2" << std::endl;
    std::cout << ls.operator!=("7/2") << std::endl;
    
    std::cout << "\nls != 8/2" << std::endl;
    std::cout << ls.operator!=("8/2") << std::endl;
    
    std::cout << "\nls.numerator()" << std::endl;
    std::cout << ls.numerator() << std::endl;

    std::cout << "\nls.denominator()" << std::endl;
    std::cout << ls.denominator() << std::endl;

    std::cout << "\nIspis unesenih vrijednosti: " << std::endl;
    for(int i = 0; i < stringovi.size(); ++i)
    std::cout << Rational{stringovi[i]} << std::endl;

  }
  catch(std::invalid_argument& err){
    std::cout << err.what() << std::endl;
  }
  catch(...){
    std::cout << "Exception" << std::endl;
  }

  return 0;
}
