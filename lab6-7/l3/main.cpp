#include <QDate>
#include <QTextStream>
#include <QTime>
#include <ctime>

int main() {

  // Дата и время

  QTextStream out(stdout);
  out.setCodec("CP866");

  QDate dt1(2015, 4, 12);
  out << "The date is " << dt1.toString() << Qt::endl;

  QDate dt2;
  dt2.setDate(2015, 3, 3);
  out << "The date is " << dt2.toString() << Qt::endl;

  QTime tm1(17, 30, 12, 55);
  out << "The time is " << tm1.toString("hh:mm:ss.zzz") << Qt::endl;

  QTime tm2;
  tm2.setHMS(13, 52, 45, 155);

  out << "The time is " << tm2.toString("hh:mm:ss.zzz") << Qt::endl;

  // Вывод

  QDate cd = QDate::currentDate();
  QTime ct = QTime::currentTime();

  out << "Current date is: " << cd.toString() << Qt::endl;
  out << "Current time is: " << ct.toString() << Qt::endl;

  // Сравнение дат

  if (dt1 < dt2) {
    out << dt1.toString() << " comes before "
        << dt2.toString() << Qt::endl;
  } else {
    out << dt1.toString() << " comes after "
        << dt2.toString() << Qt::endl;
  }

  // Определение високосного года

  QList<int> years({ 2010, 2011, 2012, 2013, 2014, 2015, 2016 });

  foreach (int year, years) {
    if (QDate::isLeapYear(year)) {
      out << year << " is a leap year" << Qt::endl;
    } else {
      out << year << " is not a leap year" << Qt::endl;
    }
  }

  // Предопределенные и пользовательские форматы дат

  out << "Today is " << cd.toString(Qt::TextDate) << Qt::endl;
  out << "Today is " << cd.toString(Qt::ISODate) << Qt::endl;
  out << "Today is " << cd.toString(Qt::SystemLocaleShortDate) << Qt::endl;
  out << "Today is " << cd.toString(Qt::SystemLocaleLongDate) << Qt::endl;
  out << "Today is " << cd.toString(Qt::DefaultLocaleShortDate) << Qt::endl;
  out << "Today is " << cd.toString(Qt::DefaultLocaleLongDate) << Qt::endl;
  out << "Today is " << cd.toString(Qt::SystemLocaleDate) << Qt::endl;
  out << "Today is " << cd.toString(Qt::LocaleDate) << Qt::endl;

  // Предопределенные и пользовательские форматы времени

  out << "The time is " << ct.toString(Qt::TextDate) << Qt::endl;
  out << "The time is " << ct.toString(Qt::ISODate) << Qt::endl;
  out << "The time is " << ct.toString(Qt::SystemLocaleShortDate) << Qt::endl;
  out << "The time is " << ct.toString(Qt::SystemLocaleLongDate) << Qt::endl;
  out << "The time is " << ct.toString(Qt::DefaultLocaleShortDate) << Qt::endl;
  out << "The time is " << ct.toString(Qt::DefaultLocaleLongDate) << Qt::endl;
  out << "The time is " << ct.toString(Qt::SystemLocaleDate) << Qt::endl;
  out << "The time is " << ct.toString(Qt::LocaleDate) << Qt::endl;

  // Работа с днями недели

  int wd = cd.dayOfWeek();

  QLocale loc;

  out << "Today is " << QDate::shortDayName(wd) << Qt::endl;
  out << "Today is " << QDate::longDayName(wd) << Qt::endl;

  // Проверка корректности даты

  QList<QDate> dates({ QDate(2015, 5, 11), QDate(2015, 8, 1),
      QDate(2015, 2, 30) });

  for (int i = 0; i < dates.size(); i++) {

    if (dates.at(i).isValid()) {
      out << "Date " << i + 1 << " is a valid date" << Qt::endl;
    } else {
      out << "Date " << i + 1 << " is not a valid date" << Qt::endl;
    }
  }

  // Класс QDateTime

  QDateTime cdt = QDateTime::currentDateTime();

  out << "The current datetime is " << cdt.toString() << Qt::endl;
  out << "The current date is " << cdt.date().toString() << Qt::endl;
  out << "The current time is " << cdt.time().toString() << Qt::endl;

  // Юлианская дата

  out << "Gregorian date for today: " << cd.toString(Qt::ISODate) << Qt::endl;
  out << "Julian day for today: " << cd.toJulianDay() << Qt::endl;

  QDate bordate(1812, 9, 7);
  QDate slavdate(1805, 12, 2);

  int j_today    = cd.toJulianDay();
  int j_borodino = bordate.toJulianDay();
  int j_slavkov  = slavdate.toJulianDay();

  out << "Days since Slavkov battle: " << j_today - j_slavkov << Qt::endl;
  out << "Days since Borodino battle: " << j_today - j_borodino << Qt::endl;

  // UTC-время

  out << "Universal datetime: " << cdt.toUTC().toString() << Qt::endl;
  out << "Local datetime: " << cdt.toLocalTime().toString() << Qt::endl;

  // Unix-время

  time_t t = time(0);
  out << t << Qt::endl;

  QDateTime dt;
  dt.setTime_t(t);
  out << dt.toString() << Qt::endl;

  out << cdt.toTime_t() << Qt::endl;

  return 0;
}
