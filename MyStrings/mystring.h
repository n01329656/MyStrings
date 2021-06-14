


#ifndef MYSTRING
#define MYSTRING
#include <iostream>
#include <string.h>
const int SIZE = 256;
namespace Mstring {

    class mystring {
    public:
        mystring();
        mystring(const char* msg);
        mystring(const mystring & rhs);
        ~mystring();
        inline unsigned int size()const {return length;}
        mystring& operator=(const mystring& rhs);
        char& operator[](int position);
        inline  char*  begin()const { return str; }
        inline  char*  end()const { return str + length - 1; }
        friend mystring operator+(const mystring& lhs, const mystring& rhs);
        friend std::ostream& operator<<(std::ostream& out, const mystring& rhs) {
            if (rhs.str == nullptr) return out;
            out << rhs.str;
            return out;
        }
        friend std::istream& operator>>(std::istream& in, mystring& rhs) {
            char buf[SIZE];
            std::cin >> buf;
            rhs = buf;
            return in;
        }
        mystring(mystring&& rhs) noexcept;
        mystring& operator=(mystring&& rhs)noexcept;



    private:
        char* str;
        int length;
    };

}




#endif // !MYSTRING


