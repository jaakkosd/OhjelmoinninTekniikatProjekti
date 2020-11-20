#include "graphic/rulesdialog.h"
#include "ui_rulesdialog.h"

RulesDialog::RulesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RulesDialog)
{
    ui->setupUi(this);

    connect(ui->closePushButton, &QPushButton::clicked,
            this, &RulesDialog::close);
}

RulesDialog::~RulesDialog()
{
    delete ui;
}
