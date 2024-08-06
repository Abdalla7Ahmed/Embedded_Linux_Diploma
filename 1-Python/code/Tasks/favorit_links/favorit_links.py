#!/usr/bin/python3

import webbrowser


Links = ['https://www.facebook.com/' , 'https://github.com/Abdalla7Ahmed?tab=repositories','https://www.linkedin.com/feed/','https://www.youtube.com/']

favorit_links ={
    "facebook_link":'https://www.facebook.com/',
    "Github_link" : 'https://github.com/Abdalla7Ahmed?tab=repositories',
    "Linkedin_link":'https://www.linkedin.com/feed/',
    "Youtube_link":'https://www.youtube.com/'
}


def openLink(link):
    webbrowser.open_new_tab(link)


def print_links():
    counter = 1
    for i in favorit_links:
        print(counter ,"." , i , " ==> ",favorit_links[i])
        counter = counter + 1
 