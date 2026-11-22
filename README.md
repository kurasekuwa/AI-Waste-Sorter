# AI-Waste-Sorter

## Introduction
Hello! Hi there! What's up! My name is kurasekuwa and this is my team's version of an AI-based Camera Waste Sorter. We used:
- Arduino UNO R3
- SG90 Micro Servo Motor
- A USB-A webcam
- Various 3D Printed Parts (not included in the repo at the moment)
- A laptop
- Exported JSON files from Google Teachable Machine

We assembled the final mechanism with the servo and webcam wired to the Arduino and laptop respectively before taking photos on Google Teachable Machine (https://teachablemachine.withgoogle.com/) in order to accurately portray what the camera would actually be seeing. We found it easier to place the mechanism over a uniformly colored surface (such as a black mouse pad) in order to keep results consistent no matter the location. We trained the model on 3 items: a piece of plastic, paper, and cardboard. If you choose to train your own model, make sure to take the photos under an artificially lit environment so that light does not mess with results.

## Instructions
I suggest downloading [AI-Waste-Sorter.zip](AI-Waste-Sorter.zip) from the repo. The other files in the repo are just what is inside the folder (exucse me for the poor organization.) 

1.Once you extract it, you will get a folder called *AI-Waste-Sorter*. Inside that you will find *index.html* which contains the HTML, CSS, and JavaScript code for the website. Do not open the website through that as it will not work. You will also find a folder called *AISorter* which contains AISorter.ino which is the Arduino file that controls the servo. You will also find a folder called *my_model* which contains *model.json*, *metadata.json*, and *weights.bin*. This file comes from the Teachable Machine Website. **DO NOT CHANGE THE NAMES OF THESE FILES OR THE FOLDER!** If you want to use a different model, make sure you rename that folder *"my_model"*.

2.Right click the *AI-Waste-Sorter* folder and click open in terminal. You should see something like:

```C:\Users\YOURUSERNAME\OneDrive\Documents\AI-Waste-Sorter>```

If you don't see "OneDrive" or "Documents," that's okay (I think). That's just where your file is located. Next to the    arrow type:

```python3 -m http.server 8000``` 

and press Enter.
