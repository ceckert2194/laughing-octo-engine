#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidget>  // Add this

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void onButtonClicked();
    void onDeleteClicked();  // Add this

private:
    QLineEdit *inputField;
    QPushButton *submitButton;
    QWidget *centralWidget;
    QListWidget *todoList;    // Add this
    QPushButton *deleteButton; // Add this
};

#endif // MAINWINDOW_HPP