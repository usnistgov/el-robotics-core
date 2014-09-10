#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void generateScene();
    void setInputFile(char *fileName);
    QString inputFile;

private:
    Ui::Dialog *ui;
    void accept();
    void reject();
    void exec();
    bool displayed;
};

#endif // DIALOG_H
