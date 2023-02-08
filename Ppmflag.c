#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <pthread.h>

/* With and height of our image */
#define WIDTH  800
#define HEIGHT 600

unsigned char img[WIDTH * HEIGHT * 3];

/* Output data as PPM file */
void saveppm(char *filename, unsigned char *img, int width, int height){
        
        /* FILE pointer */
        FILE *f;
        
        /* Open file for writing */
        f = fopen(filename, "wb");
        
        /* PPM header info, including the size of the image */
        fprintf(f, "P6 %d %d %d\n", width, height, 255);
        
        /* Write the image data to the file - remember 3 byte per pixel */
        fwrite(img, 3, WIDTH*HEIGHT, f);
        
        /* Make sure you close the file */
        fclose(f);

}

int main(int argc,char *argv[])
{
    unsigned char img[WIDTH * HEIGHT * 3];

        int i,j;


        for(i=0; i<HEIGHT; i++){
                for(j=0; j<WIDTH; j++){
                        if( (j>=350 && j<450) || (i>=250 && i<350) ){
                                img[(j + i*WIDTH)*3 + 0] = 255;
                                img[(j + i*WIDTH)*3 + 1] = 0;
                                img[(j + i*WIDTH)*3 + 2] = 0;
                        }else{
                                img[(j + i*WIDTH)*3 + 0] = 255;
                                img[(j + i*WIDTH)*3 + 1] = 255;
                                img[(j + i*WIDTH)*3 + 2] = 255;
                        }
                }

        }


	    
	    saveppm("enflag.ppm", img, WIDTH, HEIGHT);
   
	return 0;
}
