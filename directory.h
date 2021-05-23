#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Directory; }
QT_END_NAMESPACE

class Directory : public QMainWindow
{
    Q_OBJECT

public:
    Directory(QWidget *parent = nullptr);
    ~Directory();

private:
    Ui::Directory *ui;
};
#endif // DIRECTORY_H
