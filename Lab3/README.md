# LAB 3: Image Bitwise Logical Operators

## Adding a Logo to an Image Using Bitwise Operators

In this lab exercise, we make use of user-defined functions in order to display the actual size of an image while fitting it to the screen boundaries. We provide two functions: one for displaying a single image and the other for displaying two images side-by-side. Here are the code and sample usages of these functions are presented below.
## Add this line into Jupyter Notebook
```python
import cv2 #import OpenCV
from matplotlib import pyplot as plt #import python plot graph
import matplotlib as mpl #import math library from python

bg = cv2.imread('bg.jpg')
bg = cv2.cvtColor(bg,cv2.COLOR_BGR2RGB)
fg = cv2.imread('fg.jpg')
fg = cv2.cvtColor(fg,cv2.COLOR_BGR2RGB)
```

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
def display_image_actual_size_double(im_data1,im_data2):
    # assuming that the two input images have the same dimension and shape
    # then, we calculate figsize from one of the two images
    figuresize = get_figsize(im_data1)
    # Create a figure of the right size that can accommodate two images side-by-side
    fig = plt.figure(figsize=(figuresize[0],figuresize[1]*2+.1))
    ax1 = fig.add_axes([0,0,1,1])
    ax1.imshow(im_data1, cmap='gray')
    ax1.axis('off')
    ax2 = fig.add_axes([1.1,0,1,1])
    ax2.imshow(im_data2, cmap='gray')
    ax2.axis('off')
    return(fig)
```

```python
plt.imshow(bg)
```
## Output of BG should be like this

![BG](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/Lab3/bgplot.png)

## Load and display selected images

First, let us look at our background and foreground images that we have chosen. Load them into your Python enviroment and display them. The code here illustrates how to use both of our user-defined image-display functions. Also, we show you two foreground cases (as noted above); you need only one.

```python
fig = display_image_actual_size_double(fg, bg)
```
## Output of BG and FG should be like this

![dual](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/Lab3/dualimg.jpg)

## Identify a region of interest on a background image

Decide where on the background you want to put your foreground image. Cut from the background this region of interest (roi); it is of the same width, same height, and same color channels as the foreground image. For example, in our case here, we will put the logo at the bottom right of our poster. The logo's top-left corner will be at the coordinate (row=390, column=765) of the poster. Remember image axes? Row 0 is at the top.

## Code
```python
rows, cols, channels = fg.shape       #get the width, the height, and the channels of fg
roi = bg[1000:1000+rows, 1800:1800+cols]  #cut from bg the roi of the same dimesions as fg
print(fg.shape)
print(roi.shape)
fig = display_image_actual_size_double(fg,roi)
fig.savefig("Lab3Ex1.jpg",bbox_inches='tight') #Save image output
```
## Output should be like this

![dual1](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/Lab3/Lab3Ex1.jpg)

## Create a binary mask of a foreground

Following the lecture where we create a black-and-white image of a robot, we first convert the foreground image to grayscale, named it fgGrayscale. Then, we threshold it using OpenCV threshold function (provided below). It returns two outputs, the thresholded image is the latter. The second variable thres is your threshold.

```python
# Example 
retval, mask = cv2.threshold(fgGrayscale, thres, 255, cv2.THRESH_BINARY)
```
## How to use it with code
```python
fgGrayscale = cv2.cvtColor(fg,cv2.COLOR_BGR2GRAY)
retval, mask = cv2.threshold(fgGrayscale, 200, 255, cv2.THRESH_BINARY)
fig = display_image_actual_size_double(fgGrayscale, mask)
fig.savefig("Lab3Ex2.jpg",bbox_inches='tight')
```

## Output should be like this

![output](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/Lab3/Lab3Ex2.jpg)

## แล้วอะไรคือ **cv2.threshold**
ในตัวอย่างคือโค้ด ของ Python, **Threshold** ก็คือเกณฑ์ที่ใช้แบ่งสิ่งใดสิ่งหนึ่ง เช่น
มีรถอยู่ 5 คัน ขับด้วยความเร็ว ดังนี้ 60, 156, 120, 80 และ 180 กม.ต่อชม. แล้วเราก็เถียงกับเพื่อนว่า คันไหนขับเร็ว คันไหนขับช้า เราเลยต้องมีเกณฑ์มาแบ่ง
สมมติเราให้ รถที่ขับเร็วกว่า 90 กม.ต่อชม. เป็นรถที่ขับเร็ว เราเรียกค่านี้ว่า **Threshold Value**
<br>

**Threshold Value** คือ การนำภาพ 1 Channel (หรือ **Grayscale Image**) มาแปลงค่า intesity ของแต่ละ Pixel ให้เหลือเพียง 2 ค่า คือ 0(ดำ) กับ 255(ขาว) เราเรียกภาพที่มีค่า intensity เพียง 2 ค่า ว่า **"Binary Image"** โดยเราจะใช้ Threshold Value ในการแบ่งว่า Pixel ที่มี intensity XX ควรมีค่าเท่าไหร่ ดังนี้

   - pixel ที่มีค่า มากกว่าเท่ากับ Threshold Value มีค่าเท่ากับ 255 หรือสีขาว

    - pixel ที่มีค่า น้อยกว่า Threshold Value มีค่าเท่ากับ 0 หรือสีดำนั้นเอง

**Pixel** ที่เป็นสีดำจะมีค่าเป็น **0** ส่วนสีขาวจะมีค่าเป็น **255** ซึ่งเพิ่งเท่านี้เรายังไม่สามารถลบ พื้นหลัง ออกได้เดี๋ยวคราวหน้าจะมาสอนสร้าง mask ไว้คุมตัวโคนันแล้วลบพื้นหลังทิ้ง 

```python
cv2.threshold(Grayscale_img, threshold_value, max_value, style)

cv2.threshold(img,thres,255,cv2.THRESH_BINARY)

```

|คำศัพท์|ความหมาย|
|--|--|
|Grayscale_img | ภาพขาวดำ ที่จริงมันก็คือ ภาพที่มี 1 Channel เราอาจจะไม่ต้องแปลงเป็น Grayscale แต่เอา Channel R, G หรือ B มาใช้เลยก็ได้ด้วยการใช้ Function cv2.split() |
|threshold_value|Threshold value|
|max_value| 	ค่าสีที่ใช้แสดง เมื่อ Pixel นั้นมีค่ามากกว่า th_value เช่น ถ้าเราลดจาก 255 เป็น 200 ภาพผลลัพธ์ที่ได้จากสีขาวก็จะกลายเป็นสีออกเทาๆ|
|style|ลักษณะผลลัพธ์ แบบที่เราใช้ก็เป็นแบบธรรมดา ถ้าเติม _INV ไปก็จะ invert สีผลลัพธ์ให้ตรงกันข้าม |

**Style** มีทั้งหมด 5 แบบ ดังตัวอย่าง
```python
cv2.THRESHOLD_BINARY

cv2.THRESHOLD_BINARY_INV 

cv2.THRESHOLD_TRUNC

cv2.THRESHOLD_TOZERO

cv2.THRESHOLD_TOZERO_INV
```

## Mask the foreground and the roi, then combine them

The next steps involves applying one or more bitwise operations, making use of the binary mask we have just created. We give you the expected output; it is your task to figure out the process. Below is an OpenCV command for 'and' operation. The syntax of other bitwise operations are the same (consult OpenCV library to learn more).


```python 
mask_inv = cv2.bitwise_not(mask)
result = cv2.bitwise_and(fg, fg, mask = mask_inv)
fig = display_image_actual_size_double(mask_inv,result)
fig.savefig("Lab3Ex3.jpg",bbox_inches='tight')
```
## Output should be like this 

![output](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/Lab3/Lab3Ex3.jpg)

## อะไรคือ **cv2.bitwise_not cv2.bitwise_and**
```python
result = cv2.bitwise_and(fg, fg, mask = mask_inv)
```
**bitwise_and** คือการนำภาพระดับบิตที่ชื่อว่า fg มาทำการ AND กับ Mask ที่ชื่อว่า mask_inv โดยมีหลักการว่า 0 AND กับอะไรก็จะได้ 0
```python
inv=cv2.bitwise_not(mask)
```
**bitwise_not** คือการการสลับภาพ mask จาก 0 เป็น 1 จาก 1 เป็น 0 หรือ การสลับจากภาพขาวเป็นดำ จากดำเป็นขาว

<br>

**Exercise #4** : Mask the roi (deleting pixels that will be replaced by the logo). Display both the mask and the result.

```python
result2 = cv2.bitwise_and(roi,roi,mask=mask)
fig = display_image_actual_size_double(mask,result2)
fig.savefig("Lab3Ex4.jpg", bbox_inches='tight')
```

## Output should be like this 

![output1](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/Lab3/Lab3Ex4.jpg)


**Exercise #5** : Combine foreground and roi (putting the logo onto the roi). Display and save your combined roi.

```python
result3 = cv2.add(result,result2)
fig = display_image_actual_size_single(result3)
fig.savefig("Lab3Ex5.jpg", bbox_inches='tight')
```
## Output should be like this 

![output2](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/Lab3/Lab3Ex5.jpg)

## Put the processed roi back onto the original background image4


**Exercise #6**: Put roi (now with the logo) back onto the original background. Display and save your result.

## Add Logo to image

```python
dst = cv2.add(result2,result3)
bg[0:rows, 0:cols ] = dst
fig = display_image_actual_size_single(bg)
fig.savefig("Lab3Ex6.jpg", bbox_inches='tight')
```

## Output it's look like this

![Real](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/Lab3/Lab3Ex6.jpg)