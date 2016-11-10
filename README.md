# simple mdi chaild db app
Аpplication consist of two parts:

1. The main application (style MDIForm), which has everything you need to communicate with the database. there are items to open the child form, and close the application from the main menu.

2. Chaild dll library, which is loaded dynamically. This is a form of the dll (MDIChild style). In this form the main menu there are three items:

a. Display / update data
b. Add a note
c. Close form

Naturally, child forms can be many. When you add a new record on the form to display its ID. To connect to the database using the connectors from the main application. The user can change the column width. Application will save user choice and restore it when user run application next time.

Script for generate DB schema contains at  ..\SQL\GenerateDB.sql 
