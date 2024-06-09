#! /usr/bin/python3

# pip install pytube
from pytube import YouTube
YouTube('https://www.youtube.com/shorts/ECpwGlEqusQ')\
    .streams.filter(progressive=True, file_extension='mp4').first().download()
