import pyautogui as pt
from time import sleep
import os



#**********INSTRUCTIONS**************
#
#   Open StarRez
#   Click on the LUID of the first student on the roster verification list
#   Now run this script (you will have 8 seconds to do the next few instructions)
#   Press 'Entry' in the top left corner
#   Press 'Close' in the top left corner
#   This is all you have to do, now watch the script run. 
#
#*************************************

#function for keypresses
def keyPress(key, num): 
    for x in range(num):
        pt.keyDown(key)
        pt.keyUp(key)


#find image using pyautogui
def clickImage(img, found, off_x=0, off_y=0):
    found = False

    #loop until the image is found (as the website can take some time to load)
    while found == False:
        position = pt.locateCenterOnScreen(img, confidence=.8)

        if position is None:
            print(f'{img} not found....')
            found = False
        else:
            pt.moveTo(position, duration=.1)
            pt.moveRel(off_x, off_y, duration=.1)
            pt.click(clicks=1, interval=.3)
            found = True

def findImage(img, found, off_x=0, off_y=0):
    found = False

    #loop until the image is found (as the website can take some time to load)
    try:
        while found == False:
            position = pt.locateCenterOnScreen(img, confidence=.8)

            if position is None:
                print(f'{img} not found....')
                found = False
            else:
                found = True
    except pt.ImageNotFoundException:
        found = False
    return found


def incorrectAnswer():
    if (findImage(os.path.dirname(__file__)+"\\images/readResource.jpg", found)):
        pt.scroll(-1000)
        sleep(0.2)
        clickImage(os.path.dirname(__file__)+"\\images/readConcept.jpg", found)
        sleep(0.2)
        clickImage(os.path.dirname(__file__)+"\\images/toQuestions.jpg", found)
        sleep(0.2)
        clickImage(os.path.dirname(__file__)+"\\images/nextQuestion.jpg", found)
        sleep(0.2)
    else:
        clickImage(os.path.dirname(__file__)+"\\images/nextQuestion.jpg", found)
        sleep(0.2)



def correctAnswer():
    clickImage(os.path.dirname(__file__)+"\\images/nextQuestion.jpg", found)
    sleep(0.2)


#---------MAIN-----------

endNumber = 1000 #edit this according to the number of students needing roster verification

#countdown
for x in range(5):
    print(x, '...')
    sleep(1)



i = 1
found = False
while i <= endNumber:
    
    if(findImage(os.path.dirname(__file__)+"\\images/multipleChoice.jpg", found)):
        clickImage(os.path.dirname(__file__)+"\\images/multipleChoice.jpg", found)
        clickImage(os.path.dirname(__file__)+"\\images/highConf.jpg", found)

        if(findImage(os.path.dirname(__file__)+"\\images/incorrectQuestion.jpg", found)):
            incorrectAnswer()
        else:
            correctAnswer()
   
    elif (findImage(os.path.dirname(__file__)+"\\images/multipleSquareChoice.jpg", found)):
        clickImage(os.path.dirname(__file__)+"\\images/multipleSquareChoice.jpg", found)
        clickImage(os.path.dirname(__file__)+"\\images/multipleSquareChoice.jpg", found)
        clickImage(os.path.dirname(__file__)+"\\images/multipleSquareChoice.jpg", found)
        clickImage(os.path.dirname(__file__)+"\\images/highConf.jpg", found)

        if(findImage(os.path.dirname(__file__)+"\\images/incorrectQuestion.jpg", found)):
            incorrectAnswer()
        else:
            correctAnswer()

    elif (findImage(os.path.dirname(__file__)+"\\images/textbox.jpg", found)):
        while (findImage(os.path.dirname(__file__)+"\\images/textbox.jpg", found)):
            clickImage(os.path.dirname(__file__)+"\\images/textbox.jpg", found)
            sleep(0.2)
            keyPress('a', 4)
        clickImage(os.path.dirname(__file__)+"\\images/highConf.jpg", found)

        if(findImage(os.path.dirname(__file__)+"\\images/incorrectQuestion.jpg", found)):
            incorrectAnswer()
        else:
            correctAnswer()

    elif (findImage(os.path.dirname(__file__)+"\\images/endOfConnect.jpg", found)):
        i = 1000
    else:
        i = 1000


    i += 1


print("")
print("***********Done!*************")


