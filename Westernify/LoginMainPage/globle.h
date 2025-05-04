#ifndef GLOBLE_H
#define GLOBLE_H
#include <QString>
#include <QVariantList>

/**
 * @author Weiyi Zeng
 * @file globle.h
 * @brief Global variables and definitions for the application.
 */

extern int num01; ///< An example global integer variable.
extern QString str; ///< An example global QString variable with the value "test".
extern QString username_qj; ///< Global variable for storing the current username.
extern QString password_qj; ///< Global variable for storing the current password.
extern QVariantList list_all_student; ///< Global list for storing student data.
extern QString sqluser; ///< Global variable for storing the SQL username (default is "root").
extern QString sqlpass; ///< Global variable for storing the SQL password (default is empty).
extern QVariantList list_all_dormstudent; ///< Global list for storing dormitory student data.
#endif // VARIATE_H
