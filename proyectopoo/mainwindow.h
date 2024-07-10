#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListView>
#include <QPushButton>
#include <QStringListModel>
#include "TokenStorage.h"
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loadButton_clicked();

private:
    Ui::MainWindow *ui;
    QListView *tokenListView;
    QPushButton *loadButton;
    QStringListModel *model;
    TokenStorage *tokenStorage;
    void loadTokens();
};
#endif // MAINWINDOW_H
