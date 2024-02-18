#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>

class CounterApp : public QWidget {
    Q_OBJECT

public:
    CounterApp(QWidget *parent = nullptr) : QWidget(parent) {
        lineEdit = new QLineEdit(this);
        lineEdit->setReadOnly(true);

        countButton = new QPushButton("Count", this);
        resetButton = new QPushButton("Reset", this);

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(lineEdit);
        layout->addWidget(countButton);
        layout->addWidget(resetButton);

        connect(countButton, &QPushButton::clicked, this, &CounterApp::countButtonClicked);
        connect(resetButton, &QPushButton::clicked, this, &CounterApp::resetButtonClicked);

        count = 0;
        updateLineEdit();
    }

private slots:
    void countButtonClicked() {
        count++;
        updateLineEdit();
    }

    void resetButtonClicked() {
        count = 0;
        updateLineEdit();
    }

private:
    void updateLineEdit() {
        lineEdit->setText(QString::number(count));
    }

    QLineEdit *lineEdit;
    QPushButton *countButton;
    QPushButton *resetButton;
    int count;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    CounterApp counterApp;
    counterApp.show();

    return app.exec();
}

#include "main.moc"
