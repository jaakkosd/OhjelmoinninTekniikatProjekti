#include "setupdialog.h"
#include "ui_setupdialog.h"

SetupDialog::SetupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetupDialog)
{
    ui->setupUi(this);

    connect(ui->startButton, &QPushButton::clicked,
            this, &SetupDialog::emitSettings);
    connect(ui->startButton, &QPushButton::clicked,
            this, &SetupDialog::accept);
    connect(ui->rulesButton, &QPushButton::clicked,
            this, &SetupDialog::showRules);
}

SetupDialog::~SetupDialog()
{
    delete ui;
}

void SetupDialog::emitSettings()
{
    int difficulity = ui->DifficulitycomboBox->currentIndex();
    int startPoint = ui->startComboBox->currentIndex();
    emit settings(difficulity, startPoint);
}

void SetupDialog::showRules()
{
    rulesDialog_.exec();
}
