#include "project.h"

void Project::set_id(int id) {
    this->id = id;
}
int Project::get_id() {
    return this->id;
}

void Project::set_name(std::string name) {
    this->name = name;
}
std::string Project::get_name() {
    return this->name;
}

void Project::set_registration_date(std::string registration_date) {
    this->registration_date = registration_date;
}
std::string Project::get_registration_date() {
    return registration_date;
}

void Project::set_start_date(std::string start_date) {
    this->start_date = start_date;
}
std::string Project::get_start_date() {
    return this->start_date;
}
