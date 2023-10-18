from pytube import YouTube
import tkinter
from tkinter import filedialog
import os
import time

def search_for_file_path():
    """
    Prompt the user to select a download location.
    """
    currdir = os.getcwd()
    tempdir = filedialog.askdirectory(parent=root, initialdir=currdir, title='Please select a Location')
    return tempdir

def download_youtube_video(video_link):
    """
    Download a YouTube video based on the provided link.
    """
    yt = YouTube(video_link)

    print("\nAbout Video\n")
    print("Title of video:   ", yt.title)
    print("Number of views:  ", yt.views)
    print("Length of video:  ", yt.length, "seconds")

    # Quality Options
    streams = yt.streams.filter(progressive=True)
    print("\nAll available options for downloads:\n")
    for i, stream in enumerate(streams):
        print(f"{i+1}. Resolution: {stream.resolution}")

    quality = int(input("Enter Quality Choice Number (1, 2, 3...): ")
    ys = streams[quality - 1]

    print("\n---Downloading---")
    ys.download(search_for_file_path())
    print("Downloaded Successfully!")

root = tkinter.Tk()
root.withdraw()  # use to hide tkinter window

flag = 1

while flag:
    video_link = input("Enter the link of the Video you want to Download: ")
    download_youtube_video(video_link)

    choice = int(input("Do you want to
