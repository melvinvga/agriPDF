#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(char * numeroProducteur, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void brochurePDF();
    QString numeroProducteur;
};

#endif // MAINWINDOW_H
