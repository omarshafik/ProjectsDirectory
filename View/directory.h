#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <QMainWindow>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLayoutItem>

#include "../Model/project.h"
#include "../Repository/ProjectsRepository.h"

class Directory : public QMainWindow
{
    Q_OBJECT

public:
    Directory(QWidget *parent = nullptr);

private:
    QWidget *centralwidget;
    QGridLayout *mainGrid;
    QPushButton *addProjectButton;
    ProjectsRepository repo;

    void addProjectToLayout(Project &projectToAdd);
    void setupUI();
};
#endif // DIRECTORY_H
