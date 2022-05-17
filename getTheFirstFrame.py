import cv2
def getFirstFrame(videofile):
    vidcap = cv2.VideoCapture(videofile)
    success, image = vidcap.read()
    if success:
        cv2.imwrite("first_frame.jpg", image)  # save frame as JPEG file

getFirstFrame('/home/sigmind/Documents/Flask-File-Uploads/static/files/ch1.mp4')
