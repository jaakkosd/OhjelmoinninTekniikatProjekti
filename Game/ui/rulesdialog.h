#ifndef RULESDIALOG_H
#define RULESDIALOG_H

#include <QDialog>

namespace Ui {

class RulesDialog;
}
/**
 * @brief The RulesDialog class creates dialog which show rules of the game
 */
class RulesDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief RulesDialog default constructror
     * @param parent is a QWidget pointer that defaults to nullptr
     */
    explicit RulesDialog(QWidget *parent = nullptr);
    /**
     * @brief Destructor.
     */
    ~RulesDialog();

private:
    Ui::RulesDialog *ui;
};

#endif // RULESDIALOG_H
