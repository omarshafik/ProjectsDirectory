#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <QMainWindow>
#include <QtCore/QVariant>
#include <QtWidgets>

#include "../Model/project.h"
#include "../Repository/ProjectsRepository.h"

class Directory : public QMainWindow
{
    Q_OBJECT

public:
    Directory(QWidget *parent = nullptr);

private:
    QWidget *centralWidget;
    QVBoxLayout *outerLayout;
    QVBoxLayout *mainLayout;
    QScrollArea *mainScrollArea;
    QWidget *mainScrollAreaContentWidget;
    QPushButton *addProjectButton;
    ProjectsRepository repo;
    std::vector<Project> projects;

    void addProjectToLayout(Project &projectToAdd);
    void setupUI();
    void retrieveAndRenderProjects();
};
#endif // DIRECTORY_H
