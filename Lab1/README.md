# LAB 1: Grayscale and RGB Color Images

## Working with Black & White Images
### Read/write and display an image
Choose your input image and save it to Lab1 directory. Choose an image that is different from the ones used as examples in class and choose one that is not the same as your friends. Be creative and have fun!

```python
import cv2 #import OpenCV
from matplotlib import pyplot as plt #import matplotlib
```
Load an image in grayscale. OpenCV imread takes two parameters: the name of an image file, and a tag 1 for color, **0 for grayscale**, and **-1 for unchanged (load the image as is)**. Then we write it to file.

```python
im = cv2.imread('dog.jpg',0)
cv2.imwrite('dog_bw.jpg',im)
```
True

Display an image using matplotlib. The cmap argument indicates the colormap. Default is color; ours is grayscale.
```python
plt.imshow(im, cmap='gray')
plt.show()
```
![1](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/Lab1/dog_bw.jpg)

## Explore the properties of the image

```python
print(im.shape)  #Get the dimension of an image height*width
print(im.dtype)  #Get the data type of an image
```

(640, 640) <br>
uint8


Our bird image is a 2D array of **640 rows** and **640 columns**, representing the height and width, respectively. Your image may be of different dimensions and that is okay. Each pixel value is stored in an **8-bit unsigned integer (uint8)** for **color/intensity scaling in the range of 0 to 255**.

In most image processing programming, images are stored in multi-dimensional arrays: 2D for grayscale and 3D for color. Operations on images are thus nothing more than mathematical functions performed on arrays and matrices. In Python, these are supported by the NumPy library. We show a couple examples below.
```python
import numpy as np #import numpy library
print(np.min(im))  #Find the minimum pixel value in an image
print(np.max(im))  #Find the maimum pixel value in an image

```
Output<br> 0 <br>
251
## Working with Color Images

### BGR versus RGB channels
First, we reload our bird image. This time, load it in color (using imread with flag=1). Then, display the color image.

```python
im = cv2.imread('dog.jpg',1)
plt.imshow(im)
plt.show()
```

![2](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/Lab1/bluedog.png)

```python
plt.imshow(cv2.cvtColor(im,cv2.COLOR_BGR2RGB))
plt.show()
```
![3](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/Lab1/normaldog.png)
## Explore the information in each color channel

Next, let's try to analze the information contained in each of the three channels individually. First, we separate the three color channels into three layers. These channels correspond to the third dimension of our image array. Since our image is BGR, the first layer (index 0) is blue, then green and red. Each layer can be displayed as a 2D grayscale image, whose intensity indicates the amount of the color a pixel contains.

```python
fig, axes = plt.subplots(2, 3, figsize=(30,20))
plt.tight_layout()

axes[0,0].imshow(cv2.cvtColor(im,cv2.COLOR_BGR2RGB))
axes[0,0].set_title("Original", fontsize=32)
axes[0,0].axis('off')
axes[0,1].imshow(im)
axes[0,1].set_title("!!!Incorrect channels!!!", fontsize=32)
axes[0,1].axis('off')
axes[0,2].imshow(cv2.cvtColor(im,cv2.COLOR_BGR2GRAY), cmap='gray')
axes[0,2].set_title("8-Bit Grayscale", fontsize=32)
axes[0,2].axis('off')

axes[1,0].imshow(im[:,:,0], cmap='gray')
axes[1,0].set_title("Blue", fontsize=32)
axes[1,0].axis('off')

axes[1,1].imshow(im[:,:,1], cmap='gray')
axes[1,1].set_title("Green", fontsize=32)
axes[1,1].axis('off')

axes[1,2].imshow(im[:,:,2], cmap='gray')
axes[1,2].set_title("Red", fontsize=32)
axes[1,2].axis('off')

plt.show()
fig.savefig("Lab1Ex1.jpg", bbox_inches='tight')
```
## Output should be like this

![4](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/Lab1/Lab1Ex1.jpg)

## Coloring and mixing up the channels

Give the blue channel the blue color. Create a copy of our image. Instead of extracting the blue as we did earlier, we leave it alone. We then set the other two channels to zero.

```python
onecolorR = im.copy()
onecolorR[:,:,1] = 0
onecolorR[:,:,2] = 0
plt.imshow(cv2.cvtColor(onecolorR,cv2.COLOR_RGB2BGR)) # Add this line to show the true output
``` 

## Color in BGR Blue and Black

```python
fig, axes = plt.subplots(1, 2, figsize=(30,20))
plt.tight_layout()

axes[1].imshow(cv2.cvtColor(onecolorR,cv2.COLOR_RGB2BGR))
axes[0].set_title("Blue (in grayscale)", fontsize=32)
axes[0].axis('off')
axes[0].imshow(cv2.cvtColor(onecolorR,cv2.COLOR_BGR2GRAY), cmap='gray')
axes[1].set_title("Blue", fontsize=32)
axes[1].axis('off')


plt.show()
fig.savefig("Lab1Ex2.jpg", bbox_inches='tight')
```
## Output should be like this

![5](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/Lab1/Lab1comEx2.jpg)


**Exercise #2**: One-channel color image. Above, we have created one one-color image for the blue channel. Your task is to create the other two one-color images for the green and red channels. Then, display the three channels side-by-side. An example of an expected output is shown below.

```python
fig, axes = plt.subplots(1, 3, figsize=(30,20))
plt.tight_layout()

axes[2].imshow(cv2.cvtColor(onecolorB,cv2.COLOR_RGB2BGR))
axes[0].set_title("Blue ", fontsize=32)
axes[0].axis('off')
axes[1].imshow(cv2.cvtColor(onecolorD,cv2.COLOR_RGB2BGR))
axes[1].set_title("Green", fontsize=32)
axes[1].axis('off')
axes[0].imshow(cv2.cvtColor(onecolorR,cv2.COLOR_RGB2BGR))
axes[2].set_title("Red", fontsize=32)
axes[2].axis('off')


plt.show()
fig.savefig("Lab1Ex2.jpg", bbox_inches='tight')
```
## Output should be like this

![6](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/Lab1/Lab1Ex2.jpg)


**Exercise #3**: Two-channel color image. Pairing of the BGR channels. Create and display three two-channel color images; they are blue-green, green-red, and red-blue. An example of an expected output is shown below. Hint: to display one-color image, we set the other two channels to zeros. Thus, to display two-color image, which channel or channels should be set to zeros?
```python
fig, axes = plt.subplots(1, 3, figsize=(30,20))
plt.tight_layout()

onecolorRGB = im.copy()
onecolorRGB[:,:,1] = 0
onecolorRGB[:,:,1] = 0
axes[2].imshow(cv2.cvtColor(onecolorRGB,cv2.COLOR_RGB2BGR))

axes[2].set_title("Red-Blue ", fontsize=32)
axes[2].axis('off')
onecolorDD = im.copy()
onecolorDD[:,:,2] = 0
onecolorDD[:,:,2] = 0
axes[1].imshow(cv2.cvtColor(onecolorRR,cv2.COLOR_RGB2BGR))
axes[1].set_title("Green-Red", fontsize=32)
axes[1].axis('off')

onecolorRR = im.copy()
onecolorRR[:,:,0] = 0
onecolorRR[:,:,0] = 0
axes[0].imshow(cv2.cvtColor(onecolorDD,cv2.COLOR_RGB2BGR))
axes[0].set_title("Blue-Green", fontsize=32)
axes[0].axis('off')

plt.show()
fig.savefig("Lab1Ex3.jpg", bbox_inches='tight')
```
## Output should be like this

![7](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/Lab1/Lab1Ex3.jpg)