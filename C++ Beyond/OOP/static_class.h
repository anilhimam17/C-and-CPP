#ifndef _STATIC_CLASS_H_
#define _STATIC_CLASS_H_

#include <string>

class StaticClass {
    static int num_obj;
    std::string name;
    public:
        static int get_num_obj();
        StaticClass(std::string name);
        ~StaticClass();
};

#endif
