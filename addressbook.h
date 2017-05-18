#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "commands.h"

#define STUDENT_NAME "Alexander Young"
#define STUDENT_ID "s3330467"
#define STUDENT_EMAIL "s3330467@student.rmit.edu.au"

void menu();
int checkCommands(char **, AddressBookList *);
void showStudentInformation();
#endif
