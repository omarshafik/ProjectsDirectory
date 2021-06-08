#include "directory.h"

Directory::Directory(QWidget *parent)
    : QMainWindow(parent)
{
    this->setupUI();
}

void Directory::retrieveAndRenderProjects() {
    projects = repo.getProjects();
    Project newProject;
    addProjectToLayout(newProject);
    for(Project project: projects) {
        addProjectToLayout(project);
    }
}

void Directory::setupUI() {
    if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("Directory"));
    this->resize(800, 600);
    this->setMinimumSize(QSize(160, 160));

    centralWidget = new QWidget(this);
    centralWidget->setObjectName(QString::fromUtf8("centralwidget"));
    outerLayout = new QVBoxLayout(centralWidget);
    mainScrollArea = new QScrollArea(centralWidget);
    mainScrollArea->setWidgetResizable(true);
    mainScrollAreaContentWidget = new QWidget();
    mainScrollAreaContentWidget->setGeometry(QRect(0, 0, 780, 536));
    mainLayout = new QVBoxLayout(mainScrollAreaContentWidget);
    mainLayout->setAlignment(Qt::AlignLeft|Qt::AlignTop);
    mainLayout->setSpacing(12);
    mainLayout->setObjectName(QString::fromUtf8("gridLayout"));
    mainLayout->setContentsMargins(80, 80, 80, 80);
    mainScrollArea->setWidget(mainScrollAreaContentWidget);

    outerLayout->addWidget(mainScrollArea);
    setCentralWidget(centralWidget);

    retrieveAndRenderProjects();
}

void Directory::addProjectToLayout(Project &projectToAdd) {
    bool isNew = projectToAdd.get_id() == 0;
    QString projectWidgetIdentifier = isNew ?
                QString::fromUtf8(projectToAdd.get_name() + "_" + std::to_string(projectToAdd.get_id()))
              : "new_project";
    QGridLayout *widgetGrid = new QGridLayout;
    widgetGrid->setObjectName(projectWidgetIdentifier + "_grid");

    QLabel *nameLabel = new QLabel;
    nameLabel->setObjectName(projectWidgetIdentifier + "_name_label");
    nameLabel->setText(QString::fromUtf8("Name"));

    widgetGrid->addWidget(nameLabel, 0, 0, 1, 1);

    QLineEdit *nameInput = new QLineEdit;
    nameInput->setObjectName(projectWidgetIdentifier + "_name_input");
    nameInput->setText(QString::fromUtf8(projectToAdd.get_name()));

    widgetGrid->addWidget(nameInput, 0, 1, 1, 1);

    QLabel *regDateLabel = new QLabel;
    regDateLabel->setObjectName(projectWidgetIdentifier + "_reg_date_label");
    regDateLabel->setText(QString::fromUtf8("Registration Date"));

    widgetGrid->addWidget(regDateLabel, 1, 0, 1, 1);

    QLineEdit *regDateInput = new QLineEdit;
    regDateInput->setObjectName(projectWidgetIdentifier + "_reg_date_input");
    regDateInput->setText(QString::fromUtf8(projectToAdd.get_registration_date()));

    widgetGrid->addWidget(regDateInput, 1, 1, 1, 1);

    QLabel *startDateLabel = new QLabel;
    startDateLabel->setObjectName(projectWidgetIdentifier + "_start_date_label");
    startDateLabel->setText(QString::fromUtf8("Start Date"));

    widgetGrid->addWidget(startDateLabel, 2, 0, 1, 1);

    QLineEdit *startDateInput = new QLineEdit;
    startDateInput->setObjectName(projectWidgetIdentifier + "_start_date_input");
    startDateInput->setText(QString::fromUtf8(projectToAdd.get_start_date()));

    widgetGrid->addWidget(startDateInput, 2, 1, 1, 1);

    if (isNew) {
        addProjectButton = new QPushButton;
        addProjectButton->setObjectName(QString::fromUtf8("addProjectButton"));
        addProjectButton->setText(QString::fromUtf8("Add Project"));

        widgetGrid->addWidget(addProjectButton, 3, 0, 1, 2);
        connect(addProjectButton, &QPushButton::clicked,
                this, [this, nameInput, regDateInput, startDateInput](bool) {
            Project newProjectToAdd;
            newProjectToAdd.set_name(nameInput->text().toStdString());
            newProjectToAdd.set_registration_date(regDateInput->text().toStdString());
            newProjectToAdd.set_start_date(startDateInput->text().toStdString());
            Project addedProject = repo.addProject(newProjectToAdd);
            nameInput->setText("");
            regDateInput->setText("");
            startDateInput->setText("");
            addProjectToLayout(addedProject);
        });
    }
    QWidget *widget = new QWidget;
    widget->setLayout(widgetGrid);
    mainLayout->addWidget(widget);
    if (!isNew) {
        connect(nameInput, &QLineEdit::textEdited,
                this, [projectToAdd, this](const QString &text) {
            Project projectToEdit {projectToAdd};
            projectToEdit.set_name(text.toStdString());
            repo.updateProject(projectToEdit);
        });
        connect(regDateInput, &QLineEdit::textEdited,
                this, [projectToAdd, this](const QString &text) {
            Project projectToEdit {projectToAdd};
            projectToEdit.set_registration_date(text.toStdString());
            repo.updateProject(projectToEdit);
        });
        connect(startDateInput, &QLineEdit::textEdited,
                this, [projectToAdd, this](const QString &text) {
            Project projectToEdit {projectToAdd};
            projectToEdit.set_start_date(text.toStdString());
            repo.updateProject(projectToEdit);
        });
    }
}
