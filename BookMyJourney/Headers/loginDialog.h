#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QMainWindow>

namespace Ui {
class LoginDialog;
}
/*!
 * \brief The LoginDialog class
 */
class LoginDialog : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief LoginDialog - This constructor displays the home-page, which asks the user to enter login details and included an image of train. Verification is done whether the entered username and password match with the records in our data-base. If they match, we proceed further. Else, Informs the user to re-enter username and password.
     * \param parent - variable (of type QWidget *) which represents the Dialog.
     */
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::LoginDialog *ui;
};

#endif // MAINWINDOW_H
