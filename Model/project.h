#ifndef PROJECT_H
#define PROJECT_H

#include <string>

class Project
{
private:
    int id;
    std::string name;
    std::string registration_date;
    std::string start_date;

public:
    Project() : id(0), name(""), registration_date(""), start_date("") {};
    Project(int id, std::string name, std::string registration_date, std::string start_date)
        : id(id), name(name), registration_date(registration_date), start_date(start_date) {};

    void set_id(int id);
    int get_id();

    void set_name(std::string name);
    std::string get_name();

    void set_registration_date(std::string name);
    std::string get_registration_date();

    void set_start_date(std::string name);
    std::string get_start_date();
};

#endif // PROJECT_H
