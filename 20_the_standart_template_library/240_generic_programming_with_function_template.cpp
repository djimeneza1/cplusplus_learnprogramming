/*
&&&&&&&&&&&&&&&&&&&&&&&&
&&&&& standart template library
&&&&&&&&&&&&&&&&&&&&&&&&
% generic programming with function templates
% what is a c++ template ?
    - blueprint 
    - function and class template
    - allow plugging-in any data type
    - compiler generates the appropiate function/class from blueprint
    - generic programming / meta programming

% max function as a template function
    - we can replace type we want to generalize with a name, say T
    - but now this won't compile

        T max (T a, T b){
            return (a>b) ? a : b;
        }

    - we need to tell the compiler this is a template function
    - we also need to tell it that T is the template parameter

        template <typename T>
        T max (T a, T b){
            return (a>b) ? a : b;
        }

% multiple types as template parameters
    - we can have multiple template parameters
    - and their types can be different

    template <typename T1, typename T2>
    void func(T1 a, T2 b){
        std::cout<<a<<" "<<b;
    }


*/

#include <iostream>
#include <string>

//template function
template <typename T>
T min(T a, T b){
    return (a<b)? a : b;
}

template <typename T1, typename T2>
void func(T1 a, T2 b){
    std::cout<<a<<" "<<b<<std::endl;
}

struct Person {
    std::string name;
    int age;
    bool operator < (const Person &rhs) const {
        return this->age<rhs.age;
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p){
    os<<p.name;
    return os;
}

template <typename T>
void my_swap( T &a, T &b ){
    int temp = a;
    a=b;
    b=temp;
}

int main(){

    int x {100};
    int y {200};
    std::cout<<x<<", "<<y<<std::endl;
    my_swap(x,y);
    std::cout<<x<<", "<<y<<std::endl;

    Person p1 {"curly",50};
    Person p2 {"moe",30};

    Person p3 = min(p1,p2);
    std::cout<<p3.name<<" is younger "<<std::endl;

    func(p1,p2);

    std::cout<<min<int>(2,3)<<std::endl;
    std::cout<<min(2,3)<<std::endl;
    std::cout<<min('A','B')<<std::endl;
    std::cout<<min(12.5,9.2)<<std::endl;
    std::cout<<min(5+2*2,7+40)<<std::endl;

    func<int,int>(10,20);
    func(10,20);
    func<char,double>('A',12.4);
    func(1000,"Testing");
    func(2000,std::string{"Frank"});

    return 0;

}