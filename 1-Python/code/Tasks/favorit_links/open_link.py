#!/usr/bin/python3
import favorit_links



while True:
    favorit_links.print_links()
    number = int(input("what do you want to visit ? "))
    favorit_links.openLink(favorit_links.Links[number-1])
