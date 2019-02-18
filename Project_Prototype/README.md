# อธิบายไลบรารี่ที่ต้องใช้ในโปรเจค ITCS381_Multimedia

```python
import cv2 # ไลบรารี่ OpenCV
from matplotlib import pyplot as plt #import python plot graph
import matplotlib as mpl #import math library from python
import numpy as np
```

## OpenCV คืออะไร

**OpenCV (Open source Computer Vision)** เป็นไลบรารีฟังก์ชันการเขียนโปรแกรม (Library of Programming Functions) โดยส่วนใหญ่จะมุ่งเป้าไปที่การแสดงผลด้วยคอมพิวเตอร์แบบเรียลไทม์ (Real-Time Computer Vision)
OpenCV ยังสนับสนุนเฟรมเวิร์กการเรียนรู้เชิงลึก (Deep Learning Frameworks) ได้แก่ TensorFlow, Torch/PyTorch และ Caffe
![opencv](https://cdn-images-1.medium.com/max/1000/1*3ANX23zTl0Tq4lWgZxlNRQ@2x.jpeg)

## การใช้ประโยชน์

ตัวอย่างการประยุกต์ใช้งาน OpenCV มีดังนี้

   - ชุดเครื่องมือคุณลักษณะ 2 มิติและ 3 มิติ (2D and 3D feature toolkits)
   - การประมาณระยะในขณะเคลื่อนที่ (Egomotion Estimation)
   - ระบบรู้จำใบหน้า (Facial recognition system)
   - การจดจำท่าทาง (Gesture recognition)
   - ปฏิสัมพันธ์ระหว่างมนุษย์และคอมพิวเตอร์ (Human-Computer interaction; HCI)

## สามารถเขียนด้วยภาษาอะไรบ้าง

OpenCV ถูกเขียนขึ้นด้วยภาษา C++ มีการรองรับ Python, Java และ MATLAB/OCTAVE — API สำหรับอินเทอร์เฟสเหล่านี้สามารถพบได้ในเอกสารออนไลน์ ซึ่งมีการรวมไว้หลากหลายภาษา เช่น C#, Perl, Ch, Haskell และ Ruby ได้รับการพัฒนาเพื่อส่งเสริมการนำมาใช้งานโดยผู้ใช้ที่เพิ่มขึ้น

## มาเล่ากันถึงโค้ดและไลบรารี่ที่ต้องใช้ในโปรเจคกันดีกว่า

```python
im = cv2.imread('รูป.jpg',0)

```
 **cv2.imread(img,value)**
 value สามารถแทนค่า 0 คือ **ภาพสีเทา(Grayscale)** หรือ 1 **สำหรับภาพสี(Color)** และ -1 สำหรับการโหลดภาพมาใช้ปกติ **(Normal import)**

 ```python
print(im.shape)  #Get the dimension of an image height*width
 ```
 **print(ตัวแปร.shape)** คือการแสดงผลลัพธ์ของขนาดภาพ คือ **กว้าง x ยาว** โค้ดบรรทัดนี้เหมาะสำหรับการคำนวนเพื่อการแบ่ง ROI (Region of Interest) ในแต่ละช่องของรูป

 ```python
im = cv2.imread('รูป.jpg',1)
plt.imshow(cv2.cvtColor(im,cv2.COLOR_BGR2RGB))
 ```

 **im = cv2.imread('รูป.jpg',1)** ถ้าเราใช้โค้ดนี้เพื่อเอารูปมาใช้ใน Jupyter Notebook รูปที่ได้จะมีสีสันที่ผิดปกติเนื่องจาก Jupyter Notebook นั้นใช้โหมดสีแบบ BGR เราจึงต้องเปลี่ยนโหมดสีนี้กลับเป็นสีปกติโดยใช้ Library **cv2.cvtColor(img,Colormode)**

 ```python
im = cv2.imread('รูป.jpg',1)
convert = cv2.cvtColor(im,cv2.colormode)
plt.imshow(convert)
 ```
## โหมดสีที่ใช้ในโปรแจคแบบคร่าวๆ
| โหมดสี(colormode)       | ความหมาย       |
| :-------------: |:-------------:|
|COLOR_BGR2GRAY|เปลี่ยนโหมดสีจาก BGR เป็น Gray|
|COLOR_BGR2RGB|เปลี่ยนโหมดสีจาก BGR เป็น RGB|
|COLOR_RGB2GRAY|เปลี่ยนโหมดสีจาก RGB เป็น Gray|
|COLOR_RGB2BGR|เปลี่ยนโหมดสีจาก RGB เป็น BGR|
|COLOR_GRAY2BGR|เปลี่ยนโหมดสีจาก Gray เป็น BGR|
|COLOR_GRAY2RGB|เปลี่ยนโหมดสีจาก Gray เป็น RGB|

## ทุกครั้งที่นำภาพมาใช้ใน Jupyter Notebook ต้องใช้ cv2.cvtColor ทุกครั้งหรือไม่

ถ้านำภาพมาใช้ปกติ เช่น การ Plot Graph หรือใช้ในบางฟังก์ชัน สีที่ออกมาจะเป็น RGB แบบปกติ แต่ เมื่อใช้ไลบรารี่ **CV2** ของ Python แล้ว ภาพที่นำมาใช้กับ **CV2** นั้นจะมีการเรียงสีแบบใหม่เป็น BGR (Blue-Green-Red) วิธีแก้ให้ใช้โค้ดนี้เพื่อแก้โหมดสีให้ถุกต้อง

```python
cv2.cvtColor(im,cv2.COLOR_BGR2RGB) # เปลี่ยนโหมดสีจาก BGR เป็น RGB
```

## การเลือกแค่สีเดียวจาก BGR ในรูปแบบ Grayscale
```python
im = cv2.imread('รูป.jpg',0)
im[:,:,0] # สีน้ำเงิน Blue Channel
im[:,:,1] # สีเขียว Green Channel
im[:,:,2] # สีแดง Red Channel
# ให้เลือกสีใดสีหนึ่งจากนั้นให้ใช้โค้ด 2 บรรทัดล่าง เพื่อเปลี่ยนสีเป็น Grayscale
convertbgr2gray = cv2.cvtColor(im,cv2.COLOR_BGR2GRAY) 
convertgray2bgr = cv2.cvtColor(convertbgr2gray,cv2.COLOR_GRAY2BGR)
```

## การเลือกสองสีจาก BGR แล้วนำสองสีที่เลือกมาผสมกัน

```python
onecolorRR = im.copy()
onecolorRR[:,:,0] = 0
onecolorRR[:,:,0] = 0
axes[0].imshow(cv2.cvtColor(onecolorDD,cv2.COLOR_RGB2BGR))
axes[0].set_title("Blue-Green", fontsize=32) # สีที่ได้จะเป็น สีน้ำเงิน-เขียว
axes[0].axis('off')

onecolorDD = im.copy()
onecolorDD[:,:,2] = 0
onecolorDD[:,:,2] = 0
axes[1].imshow(cv2.cvtColor(onecolorRR,cv2.COLOR_RGB2BGR))
axes[1].set_title("Green-Red", fontsize=32) # สีที่ได้จะเป็น สีเขียว-แดง
axes[1].axis('off')

onecolorRGB = im.copy()
onecolorRGB[:,:,1] = 0
onecolorRGB[:,:,1] = 0
axes[2].imshow(cv2.cvtColor(onecolorRGB,cv2.COLOR_RGB2BGR))

axes[2].set_title("Red-Blue ", fontsize=32) # สีที่ได้จะเป็น สีแดง-น้ำเงิน
axes[2].axis('off')
```
 