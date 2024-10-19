#include "customer_operations.h"
#include "ui_customer_operations.h"
#include "mainwindow.h"
#include "account.h"
#include <QInputDialog>
Customer_operations::Customer_operations(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Customer_operations)
{
    ui->setupUi(this);
}

Customer_operations::~Customer_operations()
{
    delete ui;
}

int Customer_operations::QMessageBox_Display(QString text,int type)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Confirmation Required"); // Set the title
    msgBox.setText(text); // Set the question text

    // Set the icon to a question mark
    if(type == QMessageBox::Question)
    {
        msgBox.setIcon(QMessageBox::Question);
        // Set the buttons and default button
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
    }
    else if(type == QMessageBox::Information)
    {
        msgBox.setIcon(QMessageBox::Information);
    }

    // Optionally, set a fixed size and background color
    msgBox.setStyleSheet("background-color: lightyellow;"); // Change color for questions
    msgBox.setFixedSize(400, 200); // Set a fixed size

    // Show the message box and store the result
    int result = msgBox.exec();
    return result;
}
void Customer_operations::make_action(Operation_Type current_type)
{

    QString Customer_Name;
    QString Customer_NN;
    QString Customer_Password;
    float Amount;

    Customer_Name = ui->lineEdit_Name->text();
    Customer_NN = ui->lineEdit_NN->text();
    Customer_Password = ui->lineEdit_Password->text();
    Amount = ui->lineEdit_Amount->text().toFloat();
    Make_Operation operation(Customer_Name,Customer_NN,Customer_Password);

    qDebug ()<<Amount;

    bool flag{false};
    if(Customer_Name.isEmpty())
    {
        qDebug() <<"Name is empty" ;
        ui->lineEdit_Name->setText("*");
        flag =true;
    }
    if(Customer_NN.isEmpty())
    {
        qDebug() <<"NN is empty" ;
        ui->lineEdit_NN->setText("*");
        flag =true;
    }
    if(Customer_Password.isEmpty())
    {
        qDebug() <<"Password is empty" ;
        ui->lineEdit_Password->setText("*");
        flag =true;
    }

    if(!flag)
    {
        QString check;
        check = operation.Return_Item("Person","National_Number",QString("WHERE National_Number = %1").arg(Customer_NN));
        qDebug() << "Result: " << check;
        if(check == "No")
        {
            QMessageBox::critical(this,"critical","there is no account with National_Number " + Customer_NN);
        }
        else
        {
            QString name,pass,nn,string_balance;
            int id;
            float current_balance{},New_balance{};
            // name = operation.Return_Item("Person","Name",QString("WHERE National_Number = %1").arg(Customer_NN));
            // pass = operation.Return_Item("Person","Password",QString("WHERE National_Number = %1").arg(Customer_NN));
            // nn = operation.Return_Item("Person","National_Number",QString("WHERE National_Number = %1").arg(Customer_NN));
            // id = operation.Return_Item("Person","Customer_ID",QString("WHERE National_Number = %1").arg(Customer_NN));
            current_balance = operation.Return_Item("Person","Balance",QString("WHERE National_Number = %1").arg(Customer_NN)).toFloat();
            qDebug() <<"the current balance before make any operation is "<<current_balance;
            id = operation.Check_Acount_Info();
            if(id ==-1)
            {
                QMessageBox::critical(this,"critical","plese enter correct data");

            }
            else
            {
                QDateTime currentDateTime ;
                if(current_type == Operation_Type::BALANCE_ENQUIRY)
                {
                    QString display_string = QString("Current balance is : %1").arg(current_balance);

                    QMessageBox_Display(display_string,QMessageBox::Information);
                }
                else if (current_type == Operation_Type::DEPOSIT)
                {
                    // currentDateTime = QDateTime::currentDateTime();
                    // //update the person table
                    // New_balance = current_balance + Amount;
                    // qDebug() <<"the New balance is "<<New_balance;

                    // QString updateBalance = QString("UPDATE Person SET Balance = %1 WHERE Customer_ID = %2")
                    //                             .arg(New_balance)
                    //                             .arg(id);
                    // operation.updateData(updateBalance);

                    // QString transaction = QString("INSERT INTO Account_Transaction (Customer_ID, Date_Time, Transaction_Type, Amount) "
                    //                               "VALUES (%1, '%2', '%3', %4)")
                    //                           .arg(id)
                    //                           .arg(currentDateTime.toString("yyyy-MM-dd HH:mm:ss"))
                    //                           .arg("Deposit")
                    //                           .arg(Amount);
                    // operation.updateData(transaction);

                    operation.m_deposit(id,Amount);
                    // ask him if he need a report for the last operation
                    QString question = "Are you need a report for the last operation ?";
                    int result = QMessageBox_Display(question,QMessageBox::Question);
                    // Check the user's response
                    if (result == QMessageBox::Yes) {
                        // User clicked Yes
                        qDebug() <<"Yes";
                        QString display_string;
                        //date
                        //name
                        //national id
                        //the deposit amount
                        //total amount
                        display_string = QString("Date : %1 \n Name : %2 \n National Number : %3 \n Deposit Amount : %4 \n Total Amount : %5 \n ")
                                             .arg(currentDateTime.toString("yyyy-MM-dd HH:mm:ss"))
                                             .arg(Customer_Name)
                                             .arg(Customer_NN)
                                             .arg(Amount)
                                             .arg(New_balance);

                        QMessageBox_Display(display_string,QMessageBox::Information);

                    }
                }
                else if (current_type == Operation_Type::WITHDRAW)
                {
                    bool flag{false};
                    currentDateTime = QDateTime::currentDateTime();
                    //update the person table

                    New_balance = current_balance - Amount;
                    if(New_balance < 0)
                    {
                        int retans;

                        // below zero
                        QString display_question = "You havn't this amount into your account\ndo you want to open checking_acount ?";
                        retans = QMessageBox_Display(display_question,QMessageBox::Question);
                        if(retans == QMessageBox::Yes)
                        {
                             // checking account
                            qDebug()<<"open checking_acount";
                            QString insertData = QString("INSERT INTO Account (Account_ID, Account_Type, Balance, Credit_Limit, Interest_Rate, Principal_Amount, Loan_Date, Loan_Duration, Customer_ID) "
                                                  "VALUES (%1, '%2', %3, '%4', %5, %6, '%7', %8, %9)")
                                              .arg(3)
                                              .arg("Checking_Account")
                                              .arg(New_balance)
                                              .arg("creditLimit")
                                              .arg(10)
                                              .arg(Amount)
                                              .arg(currentDateTime.toString("yyyy-MM-dd HH:mm:ss"))
                                              .arg(0)
                                              .arg(id);
                            operation.insertData(insertData);
                            QString updateBalance = QString("UPDATE Person SET Balance = %1 WHERE Customer_ID = %2")
                                                        .arg(New_balance)
                                                        .arg(id);
                            operation.updateData(updateBalance);

                        }
                        else if(retans == QMessageBox::No)
                        {
                            display_question = "do you want to withdraw the remaining or cancel the operation ?";
                            retans = QMessageBox_Display(display_question,QMessageBox::Question);
                            if(retans == QMessageBox::Yes)
                            {
                                qDebug()<<"withdraw the remaining";
                                QString updateBalance = QString("UPDATE Person SET Balance = %1 WHERE Customer_ID = %2")
                                                            .arg(0.0)
                                                            .arg(id);
                                operation.updateData(updateBalance);
                                New_balance = 0;
                            }
                            else if(retans == QMessageBox::No)
                            {
                                flag = true;
                                qDebug()<<"cancel the operation ";

                            }
                        }

                    }
                    else
                    {
                        // there is  enough balance
                        QString updateBalance = QString("UPDATE Person SET Balance = %1 WHERE Customer_ID = %2")
                                                    .arg(New_balance)
                                                    .arg(id);
                        qDebug() <<"befor update person table";
                        operation.updateData(updateBalance);

                    }
                    if(!flag)
                    {

                        QString question = "Are you need a report for the last operation ?";
                        int result = QMessageBox_Display(question,QMessageBox::Question);
                        // Check the user's response
                        if (result == QMessageBox::Yes)
                        {
                            // User clicked Yes
                            qDebug() <<"Yes";
                            QString display_string;
                            //date
                            //name
                            //national id
                            //the deposit amount
                            //total amount
                            display_string = QString("Date : %1 \n Name : %2 \n National Number : %3 \n withdraw Amount : %4 \n Total Amount : %5 \n ")
                                                 .arg(currentDateTime.toString("yyyy-MM-dd HH:mm:ss"))
                                                 .arg(Customer_Name)
                                                 .arg(Customer_NN)
                                                 .arg(Amount)
                                                 .arg(New_balance);

                            QMessageBox_Display(display_string,QMessageBox::Information);
                        }
                        QString transaction = QString("INSERT INTO Account_Transaction (Customer_ID, Date_Time, Transaction_Type, Amount) "
                                                      "VALUES (%1, '%2', '%3', %4)")
                                                  .arg(id)
                                                  .arg(currentDateTime.toString("yyyy-MM-dd HH:mm:ss"))
                                                  .arg("withdraw")
                                                  .arg(Amount);
                         operation.updateData(transaction);
                    }


                }
                //     qDebug() <<"the New balance is "<<New_balance;





                //     // if the balance below zero ask him if he need to open checking accoint or WITHDRAW the valid balance
                //     // ask him if he need a report for the last operation

                // }
            }
        }

    }

}



Make_Operation::Make_Operation(QString Customer_Name,QString Customer_NN,QString Customer_Pass)
{
    createDatabase("Library_Management_System.db");
    Set_Customer_Name(Customer_Name);
    Set_Customer_NN(Customer_NN);
    Set_Customer_Pass(Customer_Pass);

}
Make_Operation::~Make_Operation()
{

}


void Customer_operations::on_pushButton_3_clicked()
{
    //Deposit
    current_type = Operation_Type::DEPOSIT;
    make_action(current_type);
}



void Customer_operations::on_pushButton_clicked()
{
    //withdraw
    current_type = Operation_Type::WITHDRAW;
    make_action(current_type);
}


void Customer_operations::on_pushButton_2_clicked()
{
    //Balance Enquiry
    current_type = Operation_Type::BALANCE_ENQUIRY;
    make_action(current_type);
}


void Customer_operations::on_pushButton_Home_clicked()
{
    //home
    hide();
    MainWindow *mainwindow;
    mainwindow = new MainWindow;
    mainwindow->showMaximized();
}


void Customer_operations::on_pushButton_Back_clicked()
{
    //back
    hide();
    Account *account;
    account = new Account;
    account->showMaximized();
}

