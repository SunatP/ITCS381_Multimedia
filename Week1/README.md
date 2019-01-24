# Week 1 Digitization and Bitmap Image
---
## Digital Image 
 * A camera raw image file contains minimally processed data from the image sensor of either a digital camera, or motion picture film scanner, or other image scanner.
 * ไฟล์ RAW เป็นรูปแบบของไฟล์ที่เซนเซอร์กล้องของเราบันทึกข้อมูลภาพทุกส่วนเอาไว้ครับ การที่มันไม่ถูกย่อแบบ JPEG ทำให้เราได้ไฟล์ภาพที่คุณภาพสูงกว่า และสามารถเอามาแต่งต่อและแก้ไขได้โดยที่ภาพไม่เสียหายเหมือน JPEG ที่โดนบีบอัดคุณภาพไฟล์มาแล้ว(JPEG สามารถแต่งภาพได้แต่ไม่ดีเท่าไฟล์ RAW)
 
 ![RawVjpg](http://www.zoomcamera.net/images/column_1484708113/raw%20file%20raw%20vs%20jpeg.jpg)

---
## Color Bit depth
* รูปภาพของเราจะมีระดับของโทนแสงขาว-ดำอยู่ที่ไล่ตั้งแต่มืดตื๋อไปจนสว่างจ้า สิ่งนี้เราเรียกมันว่า bit-depth ไฟล์ JPEG (8 bit) มันไล่ได้256ระดับ ในขณะที่ไฟล์ RAW (12 bit, 14 bit) จะไล่ได้ 4,096 ระดับ ไปจนถึงเป็นหมื่นๆระดับ (ขึ้นอยู่กับความสามารถของเซนเซอร์จากกล้องถ่ายภาพ)
* ในการใช้งานทั่วๆไป การไล่ได้256ระดับของ 8 bit ก็ถือว่าเหลือเฟือแล้ว แต่หากเราเอาภาพที่ไล่โทนได้แค่ 256 ระดับไปทำการแต่ง ภาพเรามีโอกาสที่จะเกิดความแตกต่างในการไล่โทนอย่างเห็นได้ชัด เห็นความไม่นุ่มนวล เพราะระดับการไล่โทนมันมีน้อยไป

![Color](https://www.azooptics.com/images/Article_Images/ImageForArticle_1151(1).jpg)

----

# Pixels from Image 
 * พิกเซล (Pixel) นั้นมีความสำคัญต่อการสร้างภาพกราฟฟิกของคอมพิวเตอร์มาก เพราะทุกๆ ส่วนของภาพกราฟฟิก เช่น จุด เส้น แบบ ลายและสีของภาพ ล้วนเกิดจากพิกเซลทั้งสิ้น อย่างเช่น กล้องถ่ายรูปความละเอียด 5 ล้านพิกเซล นั้นหมายความว่าเมื่อถ่ายภาพที่ความละเอียดสูงสุด (ที่กล้องตัวนั้นๆ จะสามารถทำได้) ภาพนั้นจะได้เม็ด พิกเซล (Pixel) 5 ล้านเม็ด หากลองสังเกตไฟล์ภาพจากหน้าจอคอม หรือโทรศัพท์มือถือดีๆ เราจะมองเห็นภาพเหล่านั้นมีเม็ดสีสีเหลี่ยมเล็กๆ เรียงต่อกันอยู่ นั้นแหละคือ พิกเซล (Pixel) ดังนั้นจึงสามารถสรุปได้ว่า หากค่าพิกเซลสูงมากเท่าไหร่ภาพที่ได้ก็จะยิ่งมีความละเอียดสูงมากตามไปด้วย

 ![Pixel](https://image.slidesharecdn.com/20110615-02-digitization-110621100127-phpapp02/95/introduction-to-images-digitization-17-728.jpg?cb=1308650632)

 * อะไรคือ PPI
   * ค่า PPI หรือ Pixel Per Inch นั้นมักจะใช้บอกถึงความละเอียดภาพที่แสดงผลบนหน้าจอแสดงผลในแง่ของจำนวนเม็ดพิกเซลต่อพื้นที่แสดงผลขนาด 1 ตารางนิ้ว ยกตัวอย่างเช่น มือถือแบรนด์หนึ่งมีหน้าจอความละเอียด 440 PPI นั้นหมายความว่าในพื้นที่หน้าจอขนาด 1 ตารางนิ้วนั้น จะมีเม็ดพิกเซลเล็กๆ เรียงกันถึง 440 พิกเซลเลยทีเดียว หากเปรียบเป็นการปลูกข้าว ก็เท่ากับว่าในพื้นที่ 1 ตารางนิ้ว นั้นมีต้นข้าวปลูกอยู่ถึง 440 ต้นนั้นเอง
   ![PPI](https://news.siamphone.com/upload/news/nw14918/6.1.jpg)
 * แล้ว DPI ล่ะคืออะไร
   * DPI ย่อมาจาก Dots Per Inch หรือหากอธิบายอย่างสั้นๆก็คือ หน่วยวัดความละเอียดของรูปภาพที่เราจำเป็นต้องเลือกใช้ในงานพิมพ์เพื่อคุณภาพงานพิมพ์ที่ดีที่สุด ซึ่งยิ่งจำนวนจุดมีมากเท่าไหร่ ความคมชัดของรูปภาพก็จะมีมากยิ่งขึ้น เพราะเนื่องจากเครื่องพิมพ์ไม่สามารถรักษาขนาด Dot ให้เท่ากับ Pixel ได้และการพิมพ์ลงบนกระดาษที่ต่างกันอาจไม่สามารถรับหมึกได้เท่ากันจึงส่งผลให้เกิดข้อแตกต่างกับควาวมความคมชัดของภาพ ยกตัวอย่างเช่น ภาพที่มีรายละเอียด 2500DPI ก็จะแสดงผลได้ละเอียดและชัดเจนมากกว่ารูปภาพที่มีความละเอียดเพียงแค่ 1100DPI เป็นต้น
   ![DPIvPPI](https://www.gogoprint.co.th/media/wysiwyg/888.jpg)

* สรุป 
   * DPI คือการตั้งค่าการพิมพ์ที่สามารถทำได้บนเครื่องพิมพ์

   * PPI คือการตั้งค่าของภาพที่สามารถทำได้ในโปรแกรมสำหรับการพิมพ์

## Calculate Image Size
  - **Example** Want to print 8 * 10 inch picture at 300 dpi 
    - calculate total pixel
      1. (width * dpi) * (height * dpi) = (8 * 300) * (10* 300) = 2400 * 3000 pixel

## Compatible file type

| Image Type       | Byte per pixel           | Possible color combination  |Compatible File Type|
| ------------- |:-------------:| -----:|-----:|
| 1 bit Line art      | 1/8 byte per pixel | 2 colors, 1 bit per pixel. One ink or white paper |TIF, PNG, GIF |
| 8-bit Indexed Color      | Up to 1 byte per pixel if 256 colors| 256 colors maximum.For graphics use today |TIF, PNG, GIF |
| 8-bit Grayscale | 1 byte per pixel      |	256 shades of gray|JPG, TIF, PNG |
| 16 bit Grayscale      | 2 bytes per pixel |65636 shades of gray |TIF, PNG|
| 24 bit RGB(8-bit mode)     | 3 bytes per pixel (one byte each for R, G, B) | Computes 16.77 million colors max. 24 bits is the "Norm" for photo images, e.g., JPG |JPG, TIF, PNG |
| 32 bit CMYK | 4 bytes per pixel, for Prepress     |Cyan, Magneta, Yellow and Black ink, typically in halftones|TIF|
| 48-bit RGB(16-bit mode) | 6 bytes per pixel      | 2.81 trillion colors max. Except we don't have 16-bit display devices |TIF,PNG|

## **Note**
   * **JPG** files are limited to only 24 bit RGB color or 8-bit grayscale. JPG is radically different than most, using a lossy compression which at extremes can be very small but also detrimental to image quality if we overdo it. A larger file with a better JPG Quality setting is the best photo image. Surely the most popular image file, most digital camera images and web page images are JPG. Many one hour photo printing shops only accept JPG files. Just do not overdo the size reduction. The largest high quality JPG image is still a rather small file, compared to others. 
   * **GIF** files were designed by CompuServe for early 8-bit video monitors when small file size was important for speed of dial up modems, all before 24 bit color or JPG was popular (and now 24 bit color is very superior for photo images). Since the image resolution number (dpi) is Not used by video monitors, it is not stored in GIF files, therefore making GIF less suitable for printing purposes. GIF is at most one byte per pixel, and is intended for indexed color, such as graphics, but 8-bit grayscale will also fit. GIF uses lossless compression. 
   * **PNG** files are versatile (multi-purpose). Two main modes: 8-bit PNG mode is intended for indexed color, comparable uses as GIF files (but with additions). Otherwise PNG can be 24 bit or 48-bit RGB color, or 8 or 16 bit grayscale, comparable to TIF for those. PNG uses lossless compression, often a bit smaller file than GIF or TIF LZW, but can be slightly slower to open and decompress.
   * **TIF** files are the most versatile in a few ways (image types RGB, CMYK prepress, YCbCr, Halftones, CIE L*a*b*), and surely we could say popular with the more serious users (but not compatible in web browsers). Generally used for lossless data, both photo and for scanned text document archival. LZW compression is used for photos, and documents usually use ITU G3 or G4 compression (including fax is TIFF format). Technically TIF allows designers to invent any new format in TIF format, but of course, then it is only compatible for their intended use with their software. 
   * **Raw** files are 12 or 14 bits per pixel (less than 2 bytes per pixel), and are often also compressed. Raw images are not directly viewable (our monitors show RGB). We see a RGB conversion while processing raw (typically correcting white balance and maybe exposure), and then a RGB file is output, often a JPG file. If additional edit is needed later, we discard that JPG file as expendable, and use the raw process to add any additional edit, and output a good replacement JPG file. 
