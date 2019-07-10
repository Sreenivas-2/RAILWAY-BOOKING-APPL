#ifndef ACCOUNTDIALOG_H
#define ACCOUNTDIALOG_H

#include <QDialog>

namespace Ui {
class AccountDialog;
}
/*!
 * \brief The AccountDialog class
 */
class AccountDialog : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief AccountDialog - This constructor displays the User interface, which is for new users. It asks the new user to enter details to create an account. All these details are noted down in server temporarily and will be stored into a text file which acts as data-base. This user can now login using his/her username and password in future.
     * \param parent - variable (of type QWidget *) which represents the Dialog.
     */
    explicit AccountDialog(QWidget *parent = nullptr);
    ~AccountDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AccountDialog *ui;
};

#endif // SECDIALOG_H
