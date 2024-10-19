#!/usr/bin/python
#2- Create task to run python script which sending an email to friend with report of uptime every sunday at 9:00 am 

import smtplib
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart
from email import encoders
import os
import datetime

def sendEmail(smtpHost, smtpPort, mailUname, mailPwd, fromEmail, mailSubject, mailContentText, recepientsMailList, attachmentFpaths):
    # create message object
    msg = MIMEMultipart()
    msg['From'] = fromEmail
    msg['To'] = ','.join(recepientsMailList)
    msg['Subject'] = mailSubject
    msg.attach(MIMEText(mailContentText, 'plain'))
    #sg.attach(MIMEText(mailContentHtml, 'html'))

    # create file attachments
    if attachmentFpaths !=False:
        for aPath in attachmentFpaths:
        # check if file exists
            part = MIMEBase('application', "octet-stream")
            part.set_payload(open(aPath, "rb").read())
            encoders.encode_base64(part)
            part.add_header('Content-Disposition',
                            'attachment; filename="{0}"'.format(os.path.basename(aPath)))
            msg.attach(part)

    # Send message object as email using smptplib
    s = smtplib.SMTP(smtpHost, smtpPort)
    s.starttls()
    s.login(mailUname, mailPwd)
    msgText = msg.as_string()
    sendErrs = s.sendmail(fromEmail, recepientsMailList, msgText)
    s.quit()

    # check if errors occured and handle them accordingly
    if not len(sendErrs.keys()) == 0:
        raise Exception("Errors occurred while sending email", sendErrs)


# mail server parameters
smtpHost = "smtp.gmail.com"
smtpPort = 587
mailUname = 'abdallahahmed17120@gmail.com'
mailPwd = 'tuax ixzo svrp buiq '
fromEmail = 'abdallahahmed17120@gmail.com'

uptiem = datetime.datetime.now();

# mail body, recepients, attachment files
mailSubject = "test subject"
mailContentHtml = "Hi, Hope u are fine. <br/> This is a <b>test</b> mail from python script using an awesome library called <b>smtplib</b> "
mailContentText = f"Hi, Hope u are fine , the current time is {uptiem}"
recepientsMailList = ["abdallahahmed17120@gmail.com"]
attachmentFpaths = ["smtp.png", "poster.png"] #write it's value ot false if you don't want to send any photos
sendEmail(smtpHost, smtpPort, mailUname, mailPwd, fromEmail,
          mailSubject, mailContentText, recepientsMailList, False)

print("execution complete...")
