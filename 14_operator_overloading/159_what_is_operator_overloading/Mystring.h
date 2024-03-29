#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring {
    private:
        char *str; //pointer to a char[] that holds a C-style string
    public:
        Mystring();  // no-args constructor
        Mystring(const char *s);    //overloaded constructor
        Mystring(const Mystring &source);   //copy constructor
        ~Mystring(); //destructor
        void display() const;
        int get_lenght() const;
        const char *get_str() const;
};

#endif // _Mystring_H_