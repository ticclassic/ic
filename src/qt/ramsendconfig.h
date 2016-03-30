#ifndef RAMSENDCONFIG_H
#define RAMSENDCONFIG_H

#include <QDialog>

namespace Ui {
    class RamsendConfig;
}
class WalletModel;

/** Multifunctional dialog to ask for passphrases. Used for encryption, unlocking, and changing the passphrase.
 */
class RamsendConfig : public QDialog
{
    Q_OBJECT

public:

    RamsendConfig(QWidget *parent = 0);
    ~RamsendConfig();

    void setModel(WalletModel *model);


private:
    Ui::RamsendConfig *ui;
    WalletModel *model;
    void configure(bool enabled, int coins, int rounds);

private slots:

    void clickBasic();
    void clickHigh();
    void clickMax();
};

#endif // RAMSENDCONFIG_H
