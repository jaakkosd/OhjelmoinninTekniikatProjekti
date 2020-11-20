#ifndef SETUPDIALOG_H
#define SETUPDIALOG_H

#include <QDialog>
#include "rulesdialog.h"

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
    void showRules();

signals:
    void settings(int difficulity, int startPoint);


private:
    Ui::SetupDialog *ui;
    RulesDialog rulesDialog_;
};

#endif // SETUPDIALOG_H
