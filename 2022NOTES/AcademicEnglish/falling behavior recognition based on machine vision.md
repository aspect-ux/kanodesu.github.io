#### falling behavior recognition based on machine vision

1.[Implementation of Behavior Recognition Based on Machine Vision | IEEE Conference Publication | IEEE Xplore](https://ieeexplore.ieee.org/document/9040773)

#### Introduction

The article mainly concentrates on the detection of human body  to analyze  whether the subject's behavior is normal,which is con

ducted on video sequence frame and analyzed by algorithms. It has a broad application prospect.

##### I. Introduction

1.Detect human body in the surveillance video in real time using  YOLO v3 deep neural network algorithm based on Pytorch framework.

2.Classify the target and capture the tracking of the target;

3.Describe the movements and Judge them; 

###### II Detection of Targets

1.uses the yolov3 deep neural network algorithm based on the pytorch framework, and the backbone network uses Darknet-53.

2.Darknet-53 takes into account the complexity of the network and the accuracy of detection. 

###### III. The Identification and Tracking of  Target

1.After detecting the motion information of the target human 

body, the algorithm is trained on the Microsoft COCO dataset,

which can realize the classification and localization of 80

common objects. 

2. After processing, the 

category and position coordinates of the object in the user 

image are returned. There are two kinds of data returned: the 

first one is to directly return the detected image, that is, draw 

the border of the object on the image and mark the category.The second type returns the primary and secondary 

classification of the object and the coordinate data of the object 

with json data. 



