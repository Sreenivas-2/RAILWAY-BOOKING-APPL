#ifndef JOURNEYDETDIALOG_H
#define JOURNEYDETDIALOG_H

#include <QDialog>

namespace Ui {
class JourneyDetDialog;
}
/*!
 * \brief The JourneyDetDialog class
 */
class JourneyDetDialog : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief JourneyDetDialog - This constructor displays the User Interface, which asks the user to enter the journey details. We can access to trains, which run in next 31 days. This is handled in date.h.
     * \param parent - variable (of type QWidget *) which represents the Dialog.
     */
    explicit JourneyDetDialog(QWidget *parent = nullptr);
    ~JourneyDetDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_toolButton_clicked();

private:
    Ui::JourneyDetDialog *ui;
};

#endif // THIRDDIALOG_H
