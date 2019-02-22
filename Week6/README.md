# Week 6 Non-uniform Image Scaling **Seam Carving**

## Teached by Asst. Prof. Dr. Worapan Kusakunniran

### Topic
    - Unform Scaling
        - Interpolation
    - Non-Uniform resizing
        - Backward Seam Carving
        - Forward Seam Carving
    - Sample Applications
    - Image Scaling
        - Interpolation is needed because of the finite size of pixels
            - Finite pixel doesn’t have real decimal index
            - Interpolation can obtain approximate value to fit in index based on proportional values between it
        - Suppose that we are scaling an image
        - Original image coordinate(x,y)
        - Scaled image coordinate(x′,y′)
        - When we want to fill-in color for each pixel at (x′,y′)in the scaled image, we will use color of pixel at (x,y)from the original image, where x,y=(x′/s,y′/s), s is scaling factor
        - xand y are often not integer, thus such pixel does not actually exist ->(x,y)are shown in the above figure as x, surrounding by 4 pixels P1,P2,P3,P4
    - Interpolation
        - Nearest neighbor
        - Bilinear interpolation
        - Bicubic interpolation
- **Interpolation: Nearest Neighbor**
    - Nearest neighbor
        - Use value of pixel whose center is closest in the original image to real coordinates of ideal interpolated pixel (proportional round up)

```C++
template<class PIXEL>
void ScaleMinifyByTwo(PIXEL *Target, PIXEL *Source, int SrcWidth, int SrcHeight)
{
  int x, y, x2, y2;
  int TgtWidth, TgtHeight;
  PIXEL p, q;

  TgtWidth = SrcWidth / 2;
  TgtHeight = SrcHeight / 2;
  for (y = 0; y < TgtHeight; y++) {
    y2 = 2 * y;
    for (x = 0; x < TgtWidth; x++) {
      x2 = 2 * x;
      p = average(Source[y2*SrcWidth + x2], Source[y2*SrcWidth + x2 + 1]);
      q = average(Source[(y2+1)*SrcWidth + x2], Source[(y2+1)*SrcWidth + x2 + 1]);
      Target[y*TgtWidth + x] = average(p, q);
    } /* for */
  } /* for */
}
```

$$หาอัตราส่วนจากรูปแรก = x1*y1$$
$$หาอัตราส่วนจากรูปที่สอง = x2*y2$$
$$หา Sx โดย Sx = x2/x1 $$
$$หา Sy โดย Sy = y2/y1 $$
$$หา y' โดย y' = yตำแหน่งใหม่แต่ละช่อง/Sy$$
$$หา x' โดย x' = xตำแหน่งใหม่แต่ละช่อง/Sx$$