#include "./View/directory.h"
#include "./Repository/ProjectsRepository.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Directory w;
    w.show();
    ProjectsRepository repo;
//    Project p3(3, "p3", "2021-05-31", "2021-05-31");
//    repo.updateProject(p3);
    foreach (Project project, repo.getProjects()) {
        std::cout << project.get_id() << " " << project.get_name() << std::endl;
    }
    return a.exec();
}
