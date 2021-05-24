#include "directory.h"

Directory::Directory(QWidget *parent)
    : QMainWindow(parent)
{
    this->setupUI();
    // retrieve projects on show/open event

    // render the view with projects
}

void Directory::setupUI() {
    if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("Directory"));
    this->resize(800, 600);
    this->setMinimumSize(QSize(160, 160));

    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);

    centralwidget = new QWidget(this);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    mainGrid = new QGridLayout(centralwidget);
    mainGrid->setObjectName(QString::fromUtf8("mainGrid"));
    mainGrid->setAlignment(Qt::AlignLeft|Qt::AlignTop);
    mainGrid->setSpacing(6);
    mainGrid->setObjectName(QString::fromUtf8("gridLayout"));
    mainGrid->setSizeConstraint(QLayout::SetMinAndMaxSize);
    mainGrid->setContentsMargins(80, 80, 80, 80);

    addProjectButton = new QPushButton(centralwidget);
    addProjectButton->setObjectName(QString::fromUtf8("addProjectButton"));
    sizePolicy.setHeightForWidth(addProjectButton->sizePolicy().hasHeightForWidth());
    addProjectButton->setSizePolicy(sizePolicy);
    addProjectButton->setMinimumSize(QSize(160, 160));
    addProjectButton->setMaximumSize(QSize(160, 160));
    addProjectButton->setText(QString::fromUtf8("Add Project"));

    mainGrid->addWidget(addProjectButton);

    std::vector projects_vector = repo.getProjects();

    for(Project project: projects_vector) {
        addProjectToLayout(project);
    }
}

void Directory::addProjectToLayout(Project &projectToAdd) {
    QWidget *widget = new QWidget(centralwidget);
    QString projectWidgetIdentifier = QString::fromUtf8(projectToAdd.get_name() + "_" + std::to_string(projectToAdd.get_id()));
    widget->setObjectName(projectWidgetIdentifier + "_widget");
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
    widget->setSizePolicy(sizePolicy);
    widget->setMinimumSize(QSize(160, 160));
    widget->setMaximumSize(QSize(160, 160));
    widget->setBaseSize(QSize(160, 160));
    QGridLayout *widgetGrid = new QGridLayout(widget);
    widgetGrid->setObjectName(projectWidgetIdentifier + "_grid");
    QLabel *nameLabel = new QLabel(widget);
    nameLabel->setObjectName(projectWidgetIdentifier + "_name_label");
    nameLabel->setText(QString::fromUtf8(projectToAdd.get_name()));

    widgetGrid->addWidget(nameLabel, 0, 0, 1, 2);

    QLabel *regDateLabel = new QLabel(widget);
    regDateLabel->setObjectName(projectWidgetIdentifier + "_reg_date_label");
    regDateLabel->setText(QString::fromUtf8("Registration Date"));

    widgetGrid->addWidget(regDateLabel, 1, 0, 1, 1);

    QLineEdit *regDateInput = new QLineEdit(widget);
    regDateInput->setObjectName(projectWidgetIdentifier + "_reg_date_input");
    regDateInput->setText(QString::fromUtf8(projectToAdd.get_registration_date()));

    widgetGrid->addWidget(regDateInput, 1, 1, 1, 1);

    QLabel *startDateLabel = new QLabel(widget);
    startDateLabel->setObjectName(projectWidgetIdentifier + "_start_date_label");
    startDateLabel->setText(QString::fromUtf8("Start Date"));

    widgetGrid->addWidget(startDateLabel, 2, 0, 1, 1);

    QLineEdit *startDateInput = new QLineEdit(widget);
    startDateInput->setObjectName(projectWidgetIdentifier + "_start_date_input");
    startDateInput->setText(QString::fromUtf8(projectToAdd.get_start_date()));

    widgetGrid->addWidget(startDateInput, 2, 1, 1, 1);

    mainGrid->addWidget(widget);
}
