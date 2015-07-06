#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QString>
#include <QDir>
#include <QStringList>
#include <QRegularExpression>
#include <QProcess>
#include <QScrollBar>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_toolButton_clicked();
    void onReadStdin();
    void on_commandLinkButton_clicked();

private:
    Ui::MainWindow *ui;
    QString fname;
    QStringList flist;
    QStringList args;
    QString bin;
    QString output;
    QProcess *pro;
    QString inputFile;
    QString outputFile;
};

#endif // MAINWINDOW_H
