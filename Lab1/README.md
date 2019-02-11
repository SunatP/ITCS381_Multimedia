# LAB 2: Image Arithmetic Operations

## Image Arithmetic for Grayscale Images    

Pick a color image you like. Instead of loading an image in grayscale as we have done earlier, we will try reading it as is (without a flag). Expectedly, we obtain a BGR image. We then convert it to grayscale using **OpenCV cvtColor** function. Look familiar? This is the same function that we use to convert from BGR to RGB. The only difference is the transform specification: **cv2.COLOR_BGR2GRAY.** We display side-by-side the color and gray images.
### Example of code
```python
imC = cv2.imread('dog.jpg') # any kind of picture can be use
im = cv2.cvtColor(imC, cv2.COLOR_BGR2GRAY)
```

```python
imC = cv2.imread('dog.jpg')
im = cv2.cvtColor(imC, cv2.COLOR_BGR2GRAY)
fig, axes = plt.subplots(1, 2, figsize=(30,20))
plt.tight_layout()

axes[0].imshow(cv2.cvtColor(imC,cv2.COLOR_BGR2RGB))
axes[0].set_title("Original", fontsize=32)
axes[0].axis('off')
axes[1].imshow(im,cmap='gray')
axes[1].set_title("Gray", fontsize=32)
axes[1].axis('off')


plt.show()
fig.savefig("Lab2Ex1.jpg", bbox_inches='tight')
```
### Output should be like this picture
![1](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/Lab2/Lab2Ex1.jpg)

**Exercise #1**: In the following lines of code, we show you how to perform addition on a grayscale image, making it uniformly brighter. Refer to the lecture on how to do subtraction, multiplication, division, and image negative. Below, we show you our complete set of output, you do yours on your selected image. You will need to vary the weight (increase or decrease it), observe the results, and select the weight that best fitted your work.

### Example code
```python
weight = 100                              #Specify a constant to add/subtract to an image
brighter = cv2.add(im,weight)             #Image addition, an image is uniformly brighter
```
### Example code to give the result 2 x 3 picture

```python
weight = 100                              #Specify a constant to add/subtract to an image
brighter = cv2.add(im,weight)             #Image addition, an image is uniformly brighter
fig, axes = plt.subplots(2, 3, figsize=(30,20))
plt.tight_layout()

axes[0,0].imshow(im,cmap='gray')
axes[0,0].set_title("Original", fontsize=32)
axes[0,0].axis('off')
axes[0,1].imshow(brighter,cmap='gray')
axes[0,1].set_title("Brighter", fontsize=32)
axes[0,1].axis('off')
brighter2 = cv2.add(im,weight-200)   
axes[0,2].imshow(brighter2,cmap='gray')
axes[0,2].set_title("Darker", fontsize=32)
axes[0,2].axis('off')
negative = cv2.subtract(255,im)   
axes[1,0].imshow(negative,cmap='gray')
axes[1,0].set_title("Negative", fontsize=32)
axes[1,0].axis('off')
higher = cv2.multiply(4,im)   
axes[1,1].imshow(higher,cmap='gray')
axes[1,1].set_title("Higher Contrast", fontsize=32)
axes[1,1].axis('off')
contrast = cv2.divide(im,8)   
axes[1,2].imshow(contrast,cmap='gray')
axes[1,2].set_title("Lower Contrast", fontsize=32)
axes[1,2].axis('off')




plt.show()
fig.savefig("Lab2Ex2.jpg", bbox_inches='tight')

```
### Example should be like this
![2](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/Lab2/Lab2Ex2.jpg)

## Image Arithmetic for Color Images


Next, we apply the same five operations: brighter/darker, higher/lower contrast, and negative to a color image. Unlike grayscale, we now have three channels that we need to handle. The arithmetic is essentially the same as before but we repeat it three times for three channels. As an example, we pick another color image to work on and detail how to brighten it in two steps. The code and the result is shown below.

   1. Use NumPy to create a placeholder for a new (brighter) image. This is a 3D array the same size and shape as the original image. Its data type is an 8-bit unsigned integer. All elements, i.e. pixel values, are set to 1.
   2. Use for-loop to process the **three BGR channels.** Each iteration of the loop adds weight to the pixel values of each channel of an input image and store it into the respective channel of an output image.
### Example Code
```python
weight = 100
brighter = np.ones(im.shape,dtype='uint8')
for i in np.arange(0,3):
    brighter[:,:,i] = cv2.add(im[:,:,i], weight)
```


### Code to process
```python
import numpy as np # Don't forget to import numpy to use in np.arange
weight = 100
fig, axes = plt.subplots(1, 2, figsize=(30,20))
plt.tight_layout()

axes[0].imshow(cv2.cvtColor(imC,cv2.COLOR_BGR2RGB))
axes[0].set_title("Original", fontsize=32)
axes[0].axis('off')



brighter = np.ones(imC.shape,dtype='uint8')
for i in np.arange(0,3):
    brighter[:,:,i] = cv2.add(imC[:,:,i], weight)
    axes[1].imshow(cv2.cvtColor(brighter,cv2.COLOR_BGR2RGB))
axes[1].set_title("Brighter", fontsize=32)
axes[1].axis('off')
    
fig.savefig("Lab2Ex3.jpg", bbox_inches='tight')
```

### Output should be like this

![3](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/Lab2/Lab2Ex3.jpg)

**Exercise 2** : follow the brighter example to perform darker, higher- and lower-contrast. Then, do a negative image. The code for negative operation is exactly the same as that use in grayscale, i.e. there is no need to explicitly perform arithmetic on each channel separately. Adjust the weights to fit your image so you can clearly see effects of all five operators. Display your results in a 2x3 grid as shown in an example below.

```python
fig, axes = plt.subplots(2, 3, figsize=(30,20))
plt.tight_layout()

axes[0,0].imshow(cv2.cvtColor(imC,cv2.COLOR_BGR2RGB))
axes[0,0].set_title("Original", fontsize=32)
axes[0,0].axis('off')

brighter = np.ones(imC.shape,dtype='uint8')
for i in np.arange(0,3):
    brighter[:,:,i] = cv2.add(imC[:,:,i], weight)
    axes[0,1].imshow(cv2.cvtColor(brighter,cv2.COLOR_BGR2RGB))
axes[0,1].set_title("Brighter", fontsize=32)
axes[0,1].axis('off')
    
darker = np.ones(imC.shape,dtype='uint8')
for i in np.arange(0,3):
    darker[:,:,i] = cv2.add(imC[:,:,i], weight-200)
    axes[0,2].imshow(cv2.cvtColor(darker,cv2.COLOR_BGR2RGB))
axes[0,2].set_title("Darker", fontsize=32)
axes[0,2].axis('off') 

negative = np.ones(imC.shape,dtype='uint8')
for i in np.arange(0,3):
    negative[:,:,i] = cv2.subtract(255,imC[:,:,i])
    axes[1,0].imshow(cv2.cvtColor(negative,cv2.COLOR_BGR2RGB))
axes[1,0].set_title("Negative", fontsize=32)
axes[1,0].axis('off')    
    
Contrast = np.ones(imC.shape,dtype='uint8')
for i in np.arange(0,3):
    Contrast[:,:,i] = cv2.multiply(2,imC[:,:,i])
    axes[1,1].imshow(cv2.cvtColor(Contrast,cv2.COLOR_BGR2RGB))
axes[1,1].set_title("Higher Contrast", fontsize=32)
axes[1,1].axis('off')    

lowercon = np.ones(imC.shape,dtype='uint8')
for i in np.arange(0,3):
    lowercon[:,:,i] = cv2.divide(imC[:,:,i],2)
    axes[1,2].imshow(cv2.cvtColor(lowercon,cv2.COLOR_BGR2RGB))
axes[1,2].set_title("Lower Contrst", fontsize=32)
axes[1,2].axis('off')    
    
fig.savefig("Lab2Ex4.jpg", bbox_inches='tight')
```
### Output should be like this
![4](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/Lab2/Lab2Ex4.jpg)
