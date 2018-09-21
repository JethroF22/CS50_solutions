# Questions

## What's `stdint.h`?

A header file in which the bit lengths of integers are specifically defined, allowing for portability
across different devices. The defined lengths are the same size on any device, independent of architecture,
thereby making programs more portable.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

To have specifically defined integer bit lengths which are the same across devices

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

8, 32, 32 and 16

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

'BM'

## What's the difference between `bfSize` and `biSize`?

`bfSize` is the size of the bitmap and `biSize` is the required number of bytes `BITMAPINFOHEADER` stucture

## What does it mean if `biHeight` is negative?

It indicates the that file is a top-down Device Independent Bitmap (DIB) which cannot be compressed

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

`biBitCount`

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

The specified files do not exist

## Why is the third argument to `fread` always `1` in our code?

It indicates that only one element should be read from the specified file.
That element's size specified by the second argument to `fread`

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

0

## What does `fseek` do?

Set the position of the file specified by the first argument to the offset 
specified by the second argument from the position specified by the third argument. 

## What is `SEEK_CUR`?

One of 3 constants that can be passed as the third argument to `fseek`. It
indicates the current position of the file pointer

## Whodunit?

It was Professor Plum with the candlestick in the library
