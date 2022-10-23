import os
import cv2
import time
import HandTrackingModule as hm

cap = cv2.VideoCapture(0)
cap.set(3,640)
cap.set(4,480)
cap.set(10,150)
pTime = 0
cTime = 0
folderPath = "D:\programing\python_programms\download_proggrams\Finger_Count-main\Finger_Images"

myList = os.listdir(folderPath)
print(myList)
overLayList = []
for imPath in myList:
    image = cv2.imread(f'{folderPath}/{imPath}')
    overLayList.append(image)

# print(len(overLayList))

detector = hm.handDetector()
tipIds = [4,8,12,16,20]
while True:
    success, img=cap.read()


    img = detector.findHands(img)
    LmList = detector.findPosition(img,draw=False)
    # print(LmList)

    if len(LmList) != 0:
        fingers = []
        if LmList[tipIds[0]][1] > LmList[tipIds[0] - 1][1]:
            fingers.append(1)
        else:
            fingers.append(0)
        for id in range(1,5):

            if LmList[tipIds[id]][2] < LmList[tipIds[id] - 2][2]:
               fingers.append(1)
            else:
                fingers.append(0)
        # print(fingers)
        totalFingers = fingers.count(1)
        print(totalFingers)
        img[0:200, 0:200] = overLayList[totalFingers -1]
        cv2.rectangle(img,(20,255),(170,425),(0,255,46),cv2.FILLED)
        cv2.putText(img,str(totalFingers),(45,375),cv2.FONT_HERSHEY_PLAIN,10,(255,45,4),25)


    cTime = time.time()
    fps = 1 / (cTime - pTime)
    pTime = cTime

    cv2.putText(img, str(int(fps)), (400, 70), cv2.FONT_HERSHEY_DUPLEX, 3, (255, 0, 0), 3)
    cv2.imshow("video",img)

    if cv2.waitKey(100) & 0xFF == ord('q'):
        break
