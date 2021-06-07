#include"mystring.h"



Mstring::mystring::mystring() {
    this->length = 1;
    this->str = new char('\0');
}

Mstring::mystring::mystring(const char* msg) {
    this->length = (strlen(msg)+1); // + 1 for '\0' char because strlen() does not count it  
    this->str = new char[this->length];
    strcpy_s(str, length, msg);
}

Mstring::mystring::mystring(const Mstring::mystring& rhs) {
    this->length = rhs.length;
    this->str = new char[this->length];
    strcpy_s(this->str,this->length,rhs.str);
}


Mstring::mystring::~mystring() {
    delete[] str;
    length=0;
}



Mstring::mystring& Mstring::mystring::operator=(const mystring& rhs) {

    if (this == &rhs)return *this;
    length = rhs.length;
    delete[] str;
    str = new char[length];
    strcpy_s(str, length, rhs.str);
    return *this;
}

char& Mstring::mystring::operator[](int position) {
    try {

        if (position >= length) // if a user tries to access '\0' it will throw an exception too 
            throw(mystring("Exception: out of boundaries"));

        return *(str + position);
    }
    catch (mystring & str) {
        std::cerr << str;
        exit (-1);
    }   
}

Mstring::mystring Mstring::operator+(const mystring& lhs, const mystring& rhs){
    auto size = lhs.size() + rhs.size();
    char* p = new char[size];
    strcpy_s(p, size, lhs.str);
    strcat_s(p, size, rhs.str);
    Mstring::mystring temp(p);
    delete[] p;
    return  temp;
}

 