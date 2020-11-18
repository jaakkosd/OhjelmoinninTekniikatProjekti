#include "setupdialog.h"
#include "ui_setupdialog.h"
#include "QDebug"

SetupDialog::SetupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetupDialog)
{
    ui->setupUi(this);

    connect(ui->startButton, &QPushButton::clicked,
            this, &SetupDialog::emitSettings);
    connect(ui->startButton, &QPushButton::clicked,
            this, &SetupDialog::accept);
}

SetupDialog::~SetupDialog()
{
    delete ui;
}

void SetupDialog::emitSettings()
{
    int difficulity = ui->DifficulitycomboBox->currentIndex();
    qDebug() << difficulity;
    int startPoint = ui->startComboBox->currentIndex();
    qDebug() << startPoint;
    emit settings(difficulity, startPoint);
}
