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

Before anything you should have everything plugged in. The Arduino should be plugged into the laptop directed (might say COM5 in the IDE). The Arduino should connect to the servo through 3 wires. Have the brown wire connected to the ground (GND), have the red wired connected to power (5V), and have the orange wire connected to the signal (the 9 pin.) The webcam can connect to your laptop however it is needed even though an adapter. I found that the Arduino works best if it is plugged in directly though. Also, make sure that you have the latest version of python downloaded onto your device (you will find out why later.)

1.Once you extract it, you will get a folder called *AI-Waste-Sorter*. Inside that you will find *index.html* which contains the HTML, CSS, and JavaScript code for the website. Do not open the website through that as it will not work. You will also find a folder called *AISorter* which contains AISorter.ino which is the Arduino file that controls the servo. You will also find a folder called *my_model* which contains *model.json*, *metadata.json*, and *weights.bin*. This file comes from the Teachable Machine Website. **DO NOT CHANGE THE NAMES OF THESE FILES OR THE FOLDER!** If you want to use a different model, make sure you rename that folder *"my_model"*.

2.Right click the *AI-Waste-Sorter* folder and click open in terminal. You should see something like:

```C:\Users\YOURUSERNAME\OneDrive\Documents\AI-Waste-Sorter>```

If you don't see "OneDrive" or "Documents," that's okay (I think). That's just where your file is located. Next to the    arrow type:

```python3 -m http.server 8000``` 

and press Enter. If there's an error mentioning something about Python, just download the latest version of python from the Microsoft Store (I promise it is not that big!) Once you've done that and everything seems to be working, type "http://localhost:8000/" in your web browser and it should be working!

3.On the website, the first thing you should do is load the model by clicking the load model button. I added barriers that prevent you from doing other things without loading the model so that it does not break. Next, load the camera and make sure to allow the website to use it. Make sure the webcam on the mechanism is connected to the website. It might freeze the website as it loads and none of the other buttons might work but just give it a second. Oh yeah, have the AISorter.ino open on your laptop too and upload the code onto the Arduino. That way you can connect the Arduino to the website by pressing the button. Now everything should be connected!

4.You can test the mechanism if it is working by going to the Manual Servo Testing section and pressing the different buttons. To have the mechanism automatically sort, press the "Enable Automatic Sorting" button. **Everything that happens on the website should be shown in the System Status section.**

That should be everything when it comes to setting up the software!

## AI USE FULL DISCLOSURE

Most of the Javascript and CSS are resource websites or other repos which will be linked before. The HTML in terms of website structure is written by me and other things are referenced in the websites. All of that is referenced by me. 

**HOWEVER!** I did you ChatGPT to generate code to debug and fix issues that came up regarding creating a delay check to keep the mechanism working.
```js
  // CHECK EMPTY SCENE BEFORE NORMAL CONFIDENCE CHECK
  if (emptyLabels.includes(label)) {

    lastClass = "";
    candidateSince = 0;

    if (probability >= emptyResetThreshold) {

      if (emptySince === 0) {
        emptySince = now;
        log("Empty scene detected: " + label +
            " (" + (probability * 100).toFixed(1) + "%). Confirming...");
      }

      if (objectProcessed && now - emptySince >= emptyDelay) {
        objectProcessed = false;

        log("Empty scene confirmed. Ready for next object.");

        document.getElementById("aiStatus").textContent =
          "Ready for next object.";
      } else if (!objectProcessed) {
        document.getElementById("aiStatus").textContent =
          "No object detected. Ready.";
      }

    } else {
      emptySince = 0;

      document.getElementById("aiStatus").textContent =
        "Empty scene confidence too low. Waiting...";
    }

    return;
  }

  // Reset empty-scene timer when an object or other class appears
  emptySince = 0;

  // CHECK NORMAL OBJECT CONFIDENCE
  if (probability < threshold) {
    lastClass = "";
    candidateSince = 0;

    document.getElementById("aiStatus").textContent =
      "Low confidence - waiting for a clearer image.";

    // Diagnostic entry: shows what the model predicts when confidence is low.
    if (objectProcessed) {
      log("Waiting to reset. Current prediction: " + label +
          " (" + (probability * 100).toFixed(1) + "%).");
    }

    return;
  }

  // IGNORE UNKNOWN CLASSIFICATIONS
  if (!Object.prototype.hasOwnProperty.call(classCommands, label)) {
    lastClass = "";
    candidateSince = 0;

    document.getElementById("aiStatus").textContent =
      "Unrecognized class - not sorting.";

    return;
  }

  // WAIT UNTIL PREVIOUS OBJECT HAS BEEN REMOVED
  if (objectProcessed) {
    document.getElementById("aiStatus").textContent =
      "Sorting complete. Remove the object to continue.";

    return;
  }

  // START TIMER FOR A NEW CLASSIFICATION
  if (label !== lastClass) {
    lastClass = label;
    candidateSince = now;

    document.getElementById("aiStatus").textContent =
      "Checking classification stability...";

    return;
  }
```
