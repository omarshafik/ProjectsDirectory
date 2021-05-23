#ifndef PROJECTSREPOSITORY_H
#define PROJECTSREPOSITORY_H

#include <QObject>
#include <QString>
#include <vector>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "db_constants.h"
#include "../Model/project.h"

class ProjectsRepository : QObject
{
    Q_OBJECT
private:
    bool isOpen;
public:
    ProjectsRepository();

    bool getIsOpen();

    std::vector<Project> getProjects();
    Project addProject(Project &projectToAdd);
    Project updateProject(Project &projectToUpdate);
};

#endif // PROJECTSREPOSITORY_H
