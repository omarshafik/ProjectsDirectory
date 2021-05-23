#include "directory.h"
#include "./Repository/ProjectsRepository.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Directory w;
    w.show();
    ProjectsRepository repo;
    foreach (Project project, repo.getProjects()) {
        std::cout << project.get_id() << " " << project.get_name() << std::endl;
    }
    return a.exec();
}
