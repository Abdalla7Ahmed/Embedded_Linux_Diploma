#!/bin/bash
################### translate.sh #####################

word=$(xclip -o)
url="https://translate.google.com.eg/?sl=en&tl=ar&text=${word}&op=translate"
google-chrome "$url"
