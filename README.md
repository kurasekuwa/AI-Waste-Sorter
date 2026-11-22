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
I suggest downloading [Download the ZIP file](AI-Waste-Sorter.zip).
