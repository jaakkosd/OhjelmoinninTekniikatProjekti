#ifndef SETUPDIALOG_H
#define SETUPDIALOG_H

#include <QDialog>
#include "rulesdialog.h"

namespace Ui {
class SetupDialog;
}

/**
 * @brief The SetupDialog class creates dialog where user have to choose game
 * starting parameters
 */
class SetupDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief SetupDialog default constructor
     * @param parent is a QWidget pointer that defaults to nullptr
     */
    explicit SetupDialog(QWidget *parent = nullptr);
    /**
     * @brief Destructor.
     */
    ~SetupDialog();

public slots:
    /**
     * @brief emitSettings emits settings signal
     */
    void emitSettings();
    /**
     * @brief showRules start rulesdialog and show rules on it
     */
    void showRules();

signals:
    void settings(int difficulity, int startPoint);


private:
    Ui::SetupDialog *ui;
    RulesDialog rulesDialog_;
};

#endif // SETUPDIALOG_H
