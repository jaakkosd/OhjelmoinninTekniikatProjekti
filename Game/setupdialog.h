#ifndef SETUPDIALOG_H
#define SETUPDIALOG_H

#include <QDialog>

namespace Ui {
class SetupDialog;
}

class SetupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetupDialog(QWidget *parent = nullptr);
    ~SetupDialog();

public slots:
    void emitSettings();

signals:
    void settings(int difficulity, int startPoint);


private:
    Ui::SetupDialog *ui;
};

#endif // SETUPDIALOG_H
