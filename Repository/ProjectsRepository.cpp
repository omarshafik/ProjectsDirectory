#include "ProjectsRepository.h"

ProjectsRepository::ProjectsRepository()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(HOST_NAME);
    db.setDatabaseName(DB_NAME);
    db.setUserName(USER_NAME);
    db.setPassword(PASSWORD);
    this->isOpen = db.open();
}

bool ProjectsRepository::getIsOpen() {
    return this->isOpen;
}

std::vector<Project> ProjectsRepository::getProjects() {
    std::vector<Project> projectsInDB;
    if (this->getIsOpen()) {
        QSqlQuery query(QSqlDatabase::database());
        query.exec("SELECT p_id, name, registration_date, start_date FROM projects ORDER BY registration_date");
        while (query.next()) {
            projectsInDB.push_back(Project(
                                       query.value(0).toInt(),
                                       query.value(1).toString().toStdString(),
                                       query.value(2).toString().toStdString(),
                                       query.value(3).toString().toStdString()));
        }
    }
    return projectsInDB;
}

Project ProjectsRepository::addProject(Project &projectToAdd) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO projects (name, registration_date, start_date) "
                      "VALUES (:id, :registration_date, :start_date)");
    query.bindValue(":name", QString::fromStdString(projectToAdd.Project::get_name()));
    query.bindValue(":registration_date", QString::fromStdString(projectToAdd.Project::get_registration_date()));
    query.bindValue(":start_date", QString::fromStdString(projectToAdd.Project::get_start_date()));
    query.exec();
    if (query.next()) {
        return Project(
                    query.value(0).toInt(),
                    query.value(1).toString().toStdString(),
                    query.value(2).toString().toStdString(),
                    query.value(3).toString().toStdString());
    }
    return Project();
}

Project ProjectsRepository::updateProject(Project &projectToUpdate) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("UPDATE projects SET name = :name, registration_date = :registration_date, start_date = :start_date "
                      "WHERE id = :id");
    query.bindValue(":id", projectToUpdate.Project::get_id());
    query.bindValue(":name", QString::fromStdString(projectToUpdate.Project::get_name()));
    query.bindValue(":registration_date", QString::fromStdString(projectToUpdate.Project::get_registration_date()));
    query.bindValue(":start_date", QString::fromStdString(projectToUpdate.Project::get_start_date()));
    query.exec();
    if (query.next()) {
        return Project(
                    query.value(0).toInt(),
                    query.value(1).toString().toStdString(),
                    query.value(2).toString().toStdString(),
                    query.value(3).toString().toStdString());
    }
    return Project();
}
