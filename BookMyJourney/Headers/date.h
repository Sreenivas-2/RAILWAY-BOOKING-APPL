#ifndef DATE_H
#define DATE_H

#include <QDialog>
#include <QDate>
class QCalendarWidget;
class QDialogButtonBox;
class QVBoxLayout;
/*!
 * \brief The date class
 */
class date : public QDialog{
    Q_OBJECT

public:
    date(QWidget *parent=0);
    /*!
     * \brief selectedDate - function that notes down the selected date.
     * \return
     */
    QDate selectedDate() const;

private:
    QWidget *widget;
    QCalendarWidget *calendarWidget;
    QDialogButtonBox* buttonBox;
    QVBoxLayout *verticalLayout;
};

#endif // DATE_H
