#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void updateLineEdit();
private slots:
    void numberClickHandler();
    void operatorClickHandler();
    void clearHandler();
    void enterHandler();

private:
    QLineEdit *number1Edit;
    QLineEdit *number2Edit;
    QLineEdit *resultEdit;
    QString operand;
    float result;
    int state;

    void updateResultEdit();
};

#endif
