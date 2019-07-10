#ifndef PAYMENTDIALOG_H
#define PAYMENTDIALOG_H

#include <QDialog>

namespace Ui {
class PaymentDialog;
}
/*!
 * \brief The PaymentDialog class
 */
class PaymentDialog : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief PaymentDialog - This constructor displays the User interface which includes the payment details. We will have a timer of 20 seconds, before which the user has to decide whether he/she is willing to book tickets. After 10 seconds, the session expires and asks the user to re-book tickets. As user confirms the payment, we assume that the user has paid for it and we reserve the tickets for the user.
     * \param parent - variable (of type QWidget *) which represents the Dialog.
     */
    explicit PaymentDialog(QWidget *parent = nullptr);
    ~PaymentDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_checkBox_stateChanged(int arg1);

    void myfunction();
//public slots:
    //void myfunction();
private:
    Ui::PaymentDialog *ui;
    QTimer *timer;
};

#endif // FIFTHDIALOG_H
