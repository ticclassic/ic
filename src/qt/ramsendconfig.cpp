#include "ramsendconfig.h"
#include "ui_ramsendconfig.h"

#include "bitcoinunits.h"
#include "guiconstants.h"
#include "optionsmodel.h"
#include "walletmodel.h"
#include "init.h"

#include <QMessageBox>
#include <QPushButton>
#include <QKeyEvent>
#include <QSettings>

RamsendConfig::RamsendConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RamsendConfig),
    model(0)
{
    ui->setupUi(this);

    connect(ui->buttonBasic, SIGNAL(clicked()), this, SLOT(clickBasic()));
    connect(ui->buttonHigh, SIGNAL(clicked()), this, SLOT(clickHigh()));
    connect(ui->buttonMax, SIGNAL(clicked()), this, SLOT(clickMax()));
}

RamsendConfig::~RamsendConfig()
{
    delete ui;
}

void RamsendConfig::setModel(WalletModel *model)
{
    this->model = model;
}

void RamsendConfig::clickBasic()
{
    configure(true, 1000, 2);

    QString strAmount(BitcoinUnits::formatWithUnit(
        model->getOptionsModel()->getDisplayUnit(), 1000 * COIN));
    QMessageBox::information(this, tr("Ramsend Configuration"),
        tr(
            "Ramsend was successfully set to basic (%1 and 2 rounds). You can change this at any time by opening Braincoin's configuration screen."
        ).arg(strAmount)
    );

    close();
}

void RamsendConfig::clickHigh()
{
    configure(true, 1000, 8);

    QString strAmount(BitcoinUnits::formatWithUnit(
        model->getOptionsModel()->getDisplayUnit(), 1000 * COIN));
    QMessageBox::information(this, tr("Ramsend Configuration"),
        tr(
            "Ramsend was successfully set to high (%1 and 8 rounds). You can change this at any time by opening Braincoin's configuration screen."
        ).arg(strAmount)
    );

    close();
}

void RamsendConfig::clickMax()
{
    configure(true, 1000, 16);

    QString strAmount(BitcoinUnits::formatWithUnit(
        model->getOptionsModel()->getDisplayUnit(), 1000 * COIN));
    QMessageBox::information(this, tr("Ramsend Configuration"),
        tr(
            "Ramsend was successfully set to maximum (%1 and 16 rounds). You can change this at any time by opening Braincoin's configuration screen."
        ).arg(strAmount)
    );

    close();
}

void RamsendConfig::configure(bool enabled, int coins, int rounds) {

    QSettings settings;

    settings.setValue("nRamsendRounds", rounds);
    settings.setValue("nAnonymizeBraincoinAmount", coins);

    nRamsendRounds = rounds;
    nAnonymizeBraincoinAmount = coins;
}
