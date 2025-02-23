#include "../include/MainWindow.hpp"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Todo List");
    resize(400, 500);  // Make window bigger

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    
    // Add todo list widget
    todoList = new QListWidget(this);
    layout->addWidget(todoList);
    
    // Input field and submit button in horizontal layout
    QHBoxLayout *inputLayout = new QHBoxLayout();
    inputField = new QLineEdit(this);
    submitButton = new QPushButton("Add Task", this);
    inputLayout->addWidget(inputField);
    inputLayout->addWidget(submitButton);
    
    // Delete button
    deleteButton = new QPushButton("Delete Selected", this);
    
    // Add layouts and widgets
    layout->addLayout(inputLayout);
    layout->addWidget(deleteButton);

    // Connect signals
    connect(submitButton, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(deleteButton, &QPushButton::clicked, this, &MainWindow::onDeleteClicked);
}

void MainWindow::onButtonClicked() {
    QString text = inputField->text().trimmed();
    if (!text.isEmpty()) {
        todoList->addItem(text);
        inputField->clear();
    }
}

void MainWindow::onDeleteClicked() {
    QListWidgetItem *item = todoList->currentItem();
    if (item) {
        delete todoList->takeItem(todoList->row(item));
    }
}