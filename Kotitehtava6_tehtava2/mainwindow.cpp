#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), state(1),result(0)
{
    number1Edit = new QLineEdit(this);
    number1Edit->setReadOnly(true);

    number2Edit = new QLineEdit(this);
    number2Edit->setReadOnly(true);

    resultEdit = new QLineEdit(this);
    resultEdit->setReadOnly(true);

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(number1Edit, 0, 0, 1, 4);
    layout->addWidget(number2Edit, 1, 0, 1, 4);
    layout->addWidget(resultEdit, 2, 0, 1, 4);

    for (int i = 0; i <= 9; ++i) {
        QPushButton *numberButton = new QPushButton(QString::number(i), this);
        layout->addWidget(numberButton);
        connect(numberButton, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    }

    QStringList operators = {"+", "-", "*", "/"};
    for (const QString &op : operators) {
        QPushButton *operatorButton = new QPushButton(op, this);
        layout->addWidget(operatorButton);
        connect(operatorButton, &QPushButton::clicked, this, &MainWindow::operatorClickHandler);
    }

    QPushButton *clearButton = new QPushButton("Clear", this);
    QPushButton *enterButton = new QPushButton("Enter", this);
    layout->addWidget(clearButton);
    layout->addWidget(enterButton);

    connect(clearButton, &QPushButton::clicked, this, &MainWindow::clearHandler);
    connect(enterButton, &QPushButton::clicked, this, &MainWindow::enterHandler);

    clearHandler();

    updateResultEdit();
}

void MainWindow::numberClickHandler() {
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());

    if (clickedButton) {
        if (operand.isEmpty()) {
            QString currentText = number1Edit->text();
            currentText += clickedButton->text();
            number1Edit->setText(currentText);
        } else {
            QString currentText = number2Edit->text();
            currentText += clickedButton->text();
            number2Edit->setText(currentText);
        }
    }

}


void MainWindow::operatorClickHandler() {
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (clickedButton) {
        qDebug() << "Operator Clicked: " << clickedButton->text();
        operand = clickedButton->text();
        state = 2;
    }
}

void MainWindow::clearHandler() {
    qDebug() << "Clear Clicked";
    state = 1;
   number1Edit->clear();
   number2Edit->clear();
    operand = "";
    result = 0;
    updateResultEdit();
}

void MainWindow::enterHandler() {
    qDebug() << "Enter Clicked";
    if (!number1Edit->text().isEmpty() && !number2Edit->text().isEmpty() && !operand.isEmpty()) {
        float num1 = number1Edit->text().toFloat();
        float num2 = number2Edit->text().toFloat();
        if (operand == "+") {
            result = num1 + num2;
        } else if (operand == "-") {
            result = num1 - num2;
        } else if (operand == "*") {
            result = num1 * num2;
        } else if (operand == "/") {
            if (num2 != 0) {
                result = num1 / num2;
            } else {

                result = 0;
            }
        }


        operand = "";
        state = 1;


        updateResultEdit();
    }
}

void MainWindow::updateLineEdit() {
    if (state == 1) {
        number1Edit->setText(number1Edit->text());
        number2Edit->clear();
    } else if (state == 2) {
        number1Edit->clear();
        number2Edit->setText(number2Edit->text());
    }
    resultEdit->setText(QString::number(result));
}
void MainWindow::updateResultEdit() {
    if (state == 1) {
        number1Edit->setText(number1Edit->text());
        number2Edit->clear();
    } else if (state == 2) {
        number1Edit->clear();
        number2Edit->setText(number2Edit->text());

    }
    resultEdit->setText(QString::number(result));
}
