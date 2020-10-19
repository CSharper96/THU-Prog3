#include <iostream>
#include <cassert>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

class Image {
    int c,w,h;
    stbi_uc* data;

    // TODO
};

/** 
 * @brief simple "draw border" example. 
 * @param inp: input image (read only)
 * @param b: border position
 * @param d: dash size
 * @param out: output image (must have same size as input image)
 */
void border(const Image& inp, int b, int d, Image &out) {
    assert(inp.getWidth() == out.getWidth());
    assert(inp.getHeight() == out.getHeight());
    for (int y=0;y<inp.getHeight();y++) {
        for (int x=0;x<inp.getWidth();x++) {
            if (x==b || y==b || x==inp.getWidth()-b-1 || y==inp.getHeight()-b-1) {
                out.set(x,y, 255*(((x+y)/d)%2) );
            }
            else {
                out.set(x,y, inp.get(x,y));
            }
        }
    }
}

/** 
 * @brief trivial box filter implementation.
 * @param inp: input image (read only)
 * @param b: blur size
 * @param out: output image (must have same size as input image)
 */
void blur(const Image& inp, int b, Image &out) {
    assert(inp.getWidth() == out.getWidth());
    assert(inp.getHeight() == out.getHeight());
    for (int y=0;y<inp.getHeight();y++) {
        for (int x=0;x<inp.getWidth();x++) {
            int x1 = x-b/2;
            int x2 = x1+b;
            int y1 = y-b/2;
            int y2 = y1+b;
            if (x1<0) x1=0;
            if (y1<0) y1=0;
            if (x2>=inp.getWidth()) x2=inp.getWidth();
            if (y2>=inp.getHeight()) y2=inp.getHeight();
            int sum=0;
            int total=0;
            for(int yy=y1;yy<y2;yy++) {
                for(int xx=x1;xx<x2;xx++) {
                    sum += inp.get(xx,yy);
                    total++;
                }
            }
            out.set(x,y, sum / total);
        }
    }
}

int main(int, char**) {
    Image inp{ "../blume2.png" };
    Image out{ inp.getWidth(), inp.getHeight() };
    border(inp, 5, 1, out);
    out.write_png("output_border_01.png");
    border(inp, 5, 6, out);
    out.write_png("output_border_06.png");
    border(inp, 5, 24, out);
    out.write_png("output_border_24.png");
    blur(inp, 5, out);
    out.write_png("output_blur_05.png");
    blur(inp, 15, out);
    out.write_png("output_blur_15.png");
}
