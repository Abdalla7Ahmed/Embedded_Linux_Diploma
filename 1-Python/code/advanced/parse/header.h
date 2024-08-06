#ifndef HEADER_H_
#define HEADER_H_

#define ABC 5
typedef struct XYZ
{
    int i;
    int j;
    int k;
    char c;

};

void LCD_init(void);
void LCD_send_command(char command,char mode);
void LCD_send_char(char character,char mode);
void LCD_send_string(char *string,char mode);
void Display_number(int number,char mode);
void Display_float(float number,char mode);




// this is single line comment 
/*
this
is 
multi
line
comment
*/






#endif