
## 1.Controls(Redirection,Piping,Wildcard,regex)

### input/output streams

![screen](./images/3.1.png)
![screen](./images/3.2.png)
- **0**: Standard Input (`stdin`) - typically used for input from the keyboard or a file.
- **1**: Standard Output (`stdout`) - used for output, usually to the terminal or a file.
- **2**: Standard Error (`stderr`) - used for error messages, usually to the terminal or a file.

The file descriptor **`3`** is an additional file descriptor that your process has opened. It points to the file `/home/abdallah/file.txt`.

File descriptors beyond `0`, `1`, and `2` are used by the process to manage other files or resources that it opens. In your case:

- **3** is being used to read from `/home/abdallah/file.txt`. This might be a file opened by the process to read data from.

### 1.1 Redirection 
(>)  --> output overwrite
(>>) --> output append
(<) --> input

we can overwrite (>) the output to file.txt  or append (>>) it to file.txt

![screen](./images/3.3.png)

redirect output to file.txt and error to error.log
![screen](./images/3.4.png)

### 1.2 Piping

![screen](./images/3.5.png)
![screen](./images/3.6.png)

### 1.3 Wildcard
### 1.3.1 Asterisk (*) : represents zero or more characters.
![screen](./images/3.7.png)

### 1.3.2 Question Mark (?): represents a single character. 
![screen](./images/3.8.png)

### 1.3.3 Square Brackets [ ] and,ranges : allow you to specify a range or a set of characters for a single position in the pattern. 

![screen](./images/3.9.png)
### 1.3.4 Brace Expansion {} or : allows you to generate multiple strings by specifying a comma-separated list inside curly 
![screen](./images/3.10.png)

### 1.3.5 Exclamation Mark (!) not: can be used to negate a pattern. 

![screen](./images/3.11.png)


## 1.4 regular expression (regex)

### Literal Vs. Meta-Characters  
### Literal characters :- 
are those characters that represent themselves in the search pattern .
### Meta characters :- 
are those characters that have special meaning(^  $  .  [  ]  {  }  -  ?  *  +  (  )  |  \ )

==> Meta characters can be treated as literals if they are escaped, i.e. preceded by a back slash  Examples,  \^    \{   \$    \\ 
==>The back slash can also convert some of the literal characters into a meta-characters  
Examples : \d    \w 

### Types of Regular Expressions 
1. Basic Regular Expressions ==> .   ^   $   [   ]  * 
2. Extended Regular Expressions ==>  (   )   {   }   ?   +   | 
The tool ‘grep’ uses BRE 
To access ERE, use ‘egrep’ or ‘grep –E ‘ 

 
### 1.BASIC REGULAR EXPRESSIONS (BRE) 
we will use this website (regex)
https://regex101.com/r/zbD0o4/1

1.1 ANY (.) any single character (not including NULL character) 
![screen](./images/3.12.png)

1.2 Anchor Characters (^ , $)
The (^) mean that the string has to be at the beginning of the line 
The ($) mean that the string has to be at the end of the line 

![screen](./images/3.13.png)
![screen](./images/3.14.png)
## any empty line
![screen](./images/3.15.png)


1.3 Bracket Expressions []
The use of brackets for any of a set of characters listed between the brackets 
![screen](./images/3.16.png)

![screen](./images/3.16.png)
![screen](./images/3.17.png)
Any character inside the bracket will be considered literal except for 
(-) if it comes in the middle (will be considered as range) 
![screen](./images/3.18.png)
![screen](./images/3.19.png)

![screen](./images/3.20.png)
(^) if it comes at the beginning (will considered as negation) 
![screen](./images/3.21.png)

### Shorthand Character Classes 
![screen](./images/3.22.png)
![screen](./images/3.23.png)
![screen](./images/3.24.png)


### 2.EXTENDED REGULAR EXPRESSIONS (ERE) 
2.1 Alternation (|)

![screen](./images/3.25.png)

2.2 Quantifiers (\*,+, and ?) 
‘?’ ==> zero or one time
![screen](./images/3.26.png)
'\*'  ==> zero or More times
![screen](./images/3.27.png)
 ‘+’ ==> One or More times
![screen](./images/3.28.png)


1.3 Matching Count ( { ) and ( } ) 
![screen](./images/3.29.png)
![screen](./images/3.30.png)
![screen](./images/3.31.png)
![screen](./images/3.32.png)
![screen](./images/3.33.png)

================================
Examples
We are searching any line starting with a phone number… this can be in the format 
(nnn) nnn – nnnn OR nnn nnn-nnnn
![screen](./images/3.34.png)


## 2-Text Processing(sed , grep  , cut,hexdump,file)

### sed TOOL 


![screen](./images/3.31.png)

![screen](./images/3.32.png)

If the search pattern exists multiple times inside the same line, only the first occurrence will be substituted To avoid that use the global flag 
![screen](./images/3.33.png)

![screen](./images/3.34.png)

### grep 
![screen](./images/3.35.png)
![screen](./images/3.36.png)


## 3-System information(Ls family,du,/etc,/proc,who ,id, neofetch )

### Ls family
![screen](./images/3.37.png)
![screen](./images/3.38.png)
![screen](./images/3.39.png)
### du
![screen](./images/3.40.png)

### who/neofetch/id
![screen](./images/3.41.png)
