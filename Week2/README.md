# Week 2

## Representation of Monochrome Image in programming
  - ## Grey Channel
   ![1](https://www.spacetelescope.org/static/projects/img/imgproc_fig2.jpg)
  * each element (pixel) in Matrix (2D Array) represents the intensity of brightness in that pixel 
    * 0 is equal to Black (0-Black)
    * 255 is equal to White (255-White)
    *  **NOTE** **Monochrome:** Each pixel is stored as asingle bit (0 or 1) A 640 x 480 monochrome image requires 37.5 KB of storage.
    *  **Grayscale:** Each pixel is usually storedas a byte (value between 0
to 255)A 640 x 480 grayscale image requires over 300 KB of storage

  - ## RGB Channel 
    ![2](https://www.researchgate.net/profile/Dennis_Wee_Neo/publication/260038465/figure/fig1/AS:297304901865489@1447894420867/Results-of-image-processing-by-MATLAB-a-RGB-matrix-for-original-image-b-simu-lated.png)
  * In the Red Channel, each element of the matrix (valued 0-255) represents an intensity of red color in that pixel, likewise in green and blue channels.
  - ## Color in per Channels
    ![3](https://slideplayer.com/slide/9806828/32/images/43/Comparison+RGB+CMY+CMYK+YIQ+HSV+HSL.jpg)
## Objectives (Monochrome)
  ![mono](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/img/monochrome.jpg)
## Objectives (Color)  
  ![color](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/img/color.jpg)
## Creating a negative of a grayscale image
  ![neg](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/img/negative.jpg)
  - A positive image is a normal image. A negative image is a total inversion, in which light areas appear dark and vice versa. A negative color image is additionally color-reversed with red areas appearing cyan, greens appearing magenta, and blues appearing yellow, and vice versa.
  - Film negatives usually have less contrast, but a wider dynamic range, than the final printed positive images. The contrast typically increases when they are printed onto photographic paper. When negative film images are brought into the digital realm, their contrast may be adjusted at the time of scanning or, more usually, during subsequent post-processing. 

  ![howtong](https://upload.wikimedia.org/wikipedia/commons/b/b3/Photographic_processing.jpg)

## Bitwise operation Black and White Image
![bitwise](http://wiki.lofarolabs.com/images/0/09/Bitwise.jpg)
***
 
 ![bitwisecont](http://2.bp.blogspot.com/-8VMKL0rc9lI/UsuRPuajCqI/AAAAAAAABUc/tXJmVxi_g3Y/s1600/bitwiseOperators.JPG)
***
 
 ![bitwise2](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/img/bitwise.jpg)

## Pixel vs Neighborhood Processing
 ![imgprocess](https://raw.githubusercontent.com/SunatP/ITCS381_Multimedia/master/img/imgprocess.jpg)
  - ## Neighborhood Processing 
  ![neighborhoodprocess](http://what-when-how.com/wp-content/uploads/2012/07/tmp26dc134_thumb.png)
 
  What is it? A sliding neighborhood operation is an operation that is performed a pixel at a time, with the value of any given pixel in the output image being determined by applying some algorithm to the values of the corresponding input pixel's neighborhood. A pixel's neighborhood is some set of pixels, defined by their locations relative to that pixel, which is called the center pixel. The neighborhood is a rectangular block, and as you move from one element to the next in an image matrix, the neighborhood block slides in the same direction. 
  
  The following figure shows the neighborhood blocks for some of the elements in a 6-by-5 matrix with 2-by-3 sliding blocks. The center pixel for each neighborhood is marked with a dot.
   
  - **EXAMPLE**
    ![ex](https://edoras.sdsu.edu/doc/matlab/toolbox/images/blocka.gif)

The center pixel is the actual pixel in the input image being processed by the operation. If the neighborhood has an odd number of rows and columns, the center pixel is actually in the center of the neighborhood. If one of the dimensions has even length, the center pixel is just to the left of center or just above center. For example, in a 2-by-2 neighborhood, the center pixel is the upper left one.

For any m-by-n neighborhood, the center pixel is
```
  floor(([m n]+1)/2) 
```   

In the 2-by-3 block shown in Example, the center pixel is (1,2), or, the pixel in the second column of the top row of the neighborhood.

To perform a sliding neighborhood operation:

   1. Select a single pixel.
   2. Determine the pixel's neighborhood.
   3. Apply a function to the values of the pixels in the neighborhood. This function must return a scalar.
   4. Find the pixel in the output image whose position corresponds to that of the center pixel in the input image. Set this output pixel to the value returned by the function.
   5. Repeat steps 1 through 4 for each pixel in the input image.

For example, suppose Example represents an averaging operation. The function might sum the values of the six neighborhood pixels and then divide by 6. The result is the value of the output pixel.
