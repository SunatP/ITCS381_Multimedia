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
## เปลี่ยนภาพสีเป็นขาวดำ (BGR To Grayscale)
ภาพที่เรานำเข้ามาใช้ใน Jupyter Notebook นั้น โหมดสีที่ใช้นั้นปกติจะเป็น BGR ถ้าเราต้องการเปลี่ยนโหมดสีให้เป็น Grayscale ทำได้โดยใช้โค้ด ดังนี้
```python
im = cv2.cvtColor(imC, cv2.COLOR_BGR2GRAY)
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
 
## การปรับแต่งสีรูปในโหมด Grayscale

**เพิ่ม/ลดความสว่าง (Brightness/Darkness)** ให้กับรูป โดยการใช้
```python
weight = 100       # weight คือการเพิ่ม/ลด ค่าความสว่างให้กับภาพได้
brighter = cv2.add(im,weight) # ใช้ไลบรารี่ add จาก cv2 เพื่อเพิ่มความสว่างให้กับภาพ 
```
**weight** ถ้าค่าที่ใช้เป็นลบ เช่น **-200** ภาพที่ใช้ **weight = -200** จะมืดลง แต่ถ้าใช้ **weight = 100** ภาพที่ได้จะมีความสว่างมากขึ้น

**การทำภาพสีกลับ (invert Process)**

```python
negative = cv2.subtract(255,im) # 255 คือ Value ที่ใช้ในการ Invert ค่าใน Histogram ส่งผลให้ภาพที่ได้มีลักษณะคล้ายกับเนกาทีฟ
```
การใช้ **cv2.subtract** คือการลดค่าแสง/สี ที่อยู่ในภาพให้ได้ตามความต้องการ

**การเพิ่ม/ลดคอนทราสต์ (Increase/Decrease Contrast)** โดยการใช้

```python
higher = cv2.multiply(4,im)   # cv2.multiply คือการนำ value ไปคูณกับภาพที่ต้องการแสดงผล จะทำให้ภาพที่ได้มีคอนทราสต์มากยิ่งขึ้น
contrast = cv2.divide(im,8)   # cv2.divide คือการนำ ภาพที่ต้องการแสดงผลไปหารด้วย Value จะทำให้ภาพที่ได้มีคอนทราสต์ลดลง
```

## การปรับแต่งรูปในโหมดสี RGB (ใช้ for loop)

โดยทุกรูปที่ต้องการจะปรับแต่งนั้นต้องใช้โค้ดนี้เสมอ
```python
 im = cv2.cvtColor(brighter,cv2.COLOR_BGR2RGB
```
เพราะเราการเปลี่ยนโหมดสีจาก BGR ให้อยู่โหมดปกติที่ตามนุษย์แบบเรามอง (RGB) จะสามารถแก้ไขภาพได้ง่ายขึ้น

**ทำภาพสีให้สว่าง(Increase Brightness) โดยใช้ for loop**
```python
import numpy as np
weight = 100

brighter = np.ones(imC.shape,dtype='uint8') # for increase Brightness
for i in np.arange(0,3):
    brighter[:,:,i] = cv2.add(imC[:,:,i], weight)
    increase = cv2.cvtColor(brighter,cv2.COLOR_BGR2RGB)

darker = np.ones(imC.shape,dtype='uint8') # darker for decrease Brightness
for i in np.arange(0,3):
    darker[:,:,i] = cv2.add(imC[:,:,i], weight-200)
```
**for loop** นี้จะทำการเพิ่ม **Weight** ลงใน imC[:,:,i] ตั้งแต่ 0 - 3

**การทำภาพเนกาทีฟ (Negative Process)**

```python
negative = np.ones(imC.shape,dtype='uint8')
for i in np.arange(0,3):
    negative[:,:,i] = cv2.subtract(255,imC[:,:,i]) # 255 คือ Value ที่ใช้ในการ Invert ค่าใน Histogram ส่งผลให้ภาพที่ได้มีลักษณะคล้ายกับเนกาทีฟในโหมดสี 
```
**เพิ่ม/ลดครอนทราสต์ให้กับภาพ (Increase/Decrease Contrast)**

```python
Contrast = np.ones(imC.shape,dtype='uint8')
for i in np.arange(0,3):
    Contrast[:,:,i] = cv2.multiply(2,imC[:,:,i]) # Multiply ไว้ใช้สำหรับการเร่งคอนทราสต์

lowercon = np.ones(imC.shape,dtype='uint8')
for i in np.arange(0,3):
    lowercon[:,:,i] = cv2.divide(imC[:,:,i],2)  # Divide สำหรับการลดคอนทราสต์
```

## การใช้ ROI สำหรับตกแต่งรูปภาพเฉพาะพื้นที่ ที่เราสนใจ
ROI = Region of Interesting คือการเลือกจุดที่เราสนใจจากภาพนั้นๆและต้องการนำส่วนนั้นของภาพมาใช้ คล้ายกับการครอปภาพ เพื่อนำไปตัดแปะ วิธีการใช้มีดังนี้

```python
def get_figsize(im):
    # What size does the figure need to be in inches to fit the image?
    dpi = plt.rcParams['figure.dpi']
    dim = im.shape
    figuresize = dim[1]/float(dpi), dim[0]/float(dpi)
    return(figuresize)
```

```python
def display_image_actual_size_single(im_data):
    figuresize = get_figsize(im_data)
    # Create a figure of the right size with one axes that takes up the full figure
    fig = plt.figure(figsize=figuresize)
    # Add the single axis to fit the image to the screen boundary
    ax = fig.add_axes([0, 0, 1, 1])
    ax.imshow(im_data, cmap='gray')
    ax.axis('off')
    plt.show()
    return(fig)
```

```python
rows, cols, channels = fg.shape       #get the width, the height, and the channels of fg
roi = bg[0:0+rows, 2288:2500+cols]  # เลือกบริเวณที่เราสนใจจากนั้นคำนวน พื้นที่ ที่ต้องการจะตัด โดยใส่ จุดเริ่มต้น:จุดสิ้นสุดลงไปใน เช่น bg[0:1000 , 200:1000] เป็นต้น
display_image_actual_size_single(roi) # เพื่อแสดงบริเวณที่ตัดรูปภาพออกมาใช้
print(fg.shape)
print(roi.shape)
```

## ใส่เอฟเฟคให้กับภาพ

 การใส่เอฟเฟคเช่น **Median Blur , Gaussian Blur , Average , etc.** สามารถทำได้โดยใช้ **CV2** เข้ามาช่วย

 **สิงที่ต้อง Import มาใช้**

 ```python
import cv2 #import OpenCV
from matplotlib import pyplot as plt #import python plot graph
import matplotlib as mpl #import math library from python
import numpy as np
 ```

 ## ฟังก์ชั่นการใส่ Salt & Pepper ให้กับภาพ

```python
def saltpepper_noise(image, prob):
    output = np.zeros(image.shape,np.uint8)
    thres = 1 - prob
    for i in range(image.shape[0]):
        for j in range(image.shape[1]):
            rdn = np.random.random()
            if rdn < prob:
                output[i][j] = 0
            elif rdn > thres:
                output[i][j] = 255
            else:
                output[i][j] = image[i][j]
    return output
```
วิธีการใช้ ให้สร้างตัวแปรขึ้นมา 1 ตัว แล้วบอก ตัวแปรตัวนี้ให้เท่ากับชื่อฟังก์ชันที่ต้องการใช้ เช่น

```python
imSP1 = saltpepper_noise(im,prob) #Add noise, 'prob' controls how much noise is added
# แทน prob ด้วย ค่าที่ต้องการ แนะนำว่า 0.01 - 0.00750
```
 ## ฟังก์ชั่นการใส่ Gaussian Blur ให้กับภาพ

 ```python
BlurGauss = cv2.GaussianBlur(im, (15,15), 0)
 ```

 ## ฟังก์ชั่นการใช้ Box average ให้กับภาพ
 ```python
blurBox = cv2.boxFilter(im, -1, (15,15))
 ```

## การใช้ Sobel Edge Detector
```
sobeledgeH = cv2.Sobel(im, -1, 0, 1, ksize=5)   #horizontal edges, changes in the y direction
sobeledgeV = cv2.Sobel(im, -1, 1, 0, ksize=5)   #vertical edges, changes in the x direction
sobeledgeHV = cv2.Sobel(im, -1, 1, 1, ksize=5)   #sobel edges, changes in the x direction
```

## การผสมฟังก์ชั่นการเบลอ
```python
# Median Filter on S&P
imSP2 = saltpepper_noise(im,0.425)  
medianFilteredimSP = cv2.medianBlur(imSP2,7)   #Apply a median filter to of size ‘sz’

# Gaussian on Filter S&P
imblurSP4 = saltpepper_noise(im,0.0625)         #Add noise, 'prob' controls how much noise is added
BlurGauss2 = cv2.GaussianBlur(imblurSP4, (15,15), 0)
```