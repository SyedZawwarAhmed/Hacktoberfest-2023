from pytube import YouTube
import tkinter
from tkinter import filedialog
import os
import time

flag = 1

root = tkinter.Tk()
root.withdraw() #use to hide tkinter window
root.tk.call('tk', 'scaling', 2.0)

def search_for_file_path ():
    currdir = os.getcwd()
    tempdir = filedialog.askdirectory(parent=root, initialdir=currdir, title='Please select a Location')
    return tempdir

def download_youtube_video(video_link):
    yt = YouTube(video_link)

    print("\nAbout Video\n")
    print("Title of video:   ",yt.title)
    print("Number of views:  ",yt.views)
    print("Length of video:  ",yt.length,"seconds")

    #Quality Options
    stream = str(yt.streams.filter(progressive=True))
    stream = stream[1:]
    stream = stream[:-1]
    streamlist = stream.split(", ")
    print("\nAll available options for downloads:\n")
    for i in range(0,len(streamlist)):
        st = streamlist[i].split(" ")
        print(i+1, ".", "Resolution: ", st[3][4:], sep="")
    
    quality = int(input("Enter Quality Choice Number(1,2,3...): "))
    ys = yt.streams.get_by_resolution(((streamlist[quality - 1].split(" "))[3][5:-1]))

    print("\n---Downloading---")
    ys.download(f"{search_for_file_path()}")
    print("Downloaded Successfully!")

while(flag == 1):
    video_link = str(input("Enter the link of the Video you want to Download: "))
    download_youtube_video(video_link)

    choice = int(input("Do you want to download more Videos(Yes -> [Enter 1], No -> [Enter 0]): "))
    if(choice == 0):
        flag = 0

print("\nThank you For Using Youtube Downloader\nA Product Developed by Ashwin Narayanan S")
time.sleep(4)
