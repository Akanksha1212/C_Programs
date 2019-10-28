#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "BMP.h"

//Opening different file by commenting out those not needed 

//#define FILENAME "Sample_Image/Sample_0.bmp"
//#define FILENAME "Sample_Image/Sample_1.bmp"
//#define FILENAME "Sample_Image/Sample_2.bmp"
//#define FILENAME "Sample_Image/Sample_3.bmp"

//#define FILENAME "Test_Image/Bird.bmp"
//#define FILENAME "Test_Image/Cat.bmp"
//#define FILENAME "Test_Image/Man.bmp"
#define FILENAME "Test_Image/Hands.bmp"

#define HEADERSIZE 14


int main(void)
{
	
	convertRED();
	convertBLUE();
	convertGREEN();
	convertGRAYSCALE();
	convertBW();
	convertBLUR();


	return 0;

}



void convertRED(void)
{
	//opening and creating files
	FILE *fname, *fp_red;
	
	fname = fopen(FILENAME, "rb");

	fp_red = fopen("red.bmp", "w+b");

	if (fname == NULL) {
		printf("Error: fopen failed for fname.\n");
		
	}
	if (fp_red == NULL) {
		printf("Error: fopen failed for fp_red.\n");
		
	}


	int headerinfo[HEADERSIZE];
	//array for storing header info

	//reading header info
	for (int i = 0; i < HEADERSIZE; i++)
	{
		int store;
		store = fgetc(fname);
		headerinfo[i] = store;
		//printf("%d ", headerinfo[i]);

	}

	int header_size = headerinfo[10]; //offset of header until pixel data
	//printf("header size: %d", header_size);
	

	rewind(fname);//resetting pointer position
	int header_index = 0;
	int temp = 0;
	int width_19, width_18;
	int height_23, height_22;

	//reading and copying header to new file
	for (int i = 0; i < header_size; i++) {

		temp = fgetc(fname);
		if (header_index == 18)
		{
			width_18 = temp;
		}
		if (header_index == 19)
		{
			width_19 = temp;
		}
		if (header_index == 22)
		{
			height_22 = temp;
		}
		if (header_index == 23)
		{
			height_23 = temp;
		}

		header_index++;
		//printf("%d ", temp);
		fputc(temp, fp_red);
	}
	
	//calculating height and width 
	int width, height;
	width = width_19 * 256 + width_18; 
	height = height_23 * 256 + height_22; 
	//printf("width: %d\n", width);
	//printf("height: %d\n", height);
	
	//calculating padding
	int padding = 0;
	padding = width % 4;
	//printf("padding: %d\n", padding);

	unsigned char pix_in[3];
	unsigned char pix_out[3];
	int row = 0;
	int col = 0;

	//reading and modifying pixel data
	for (row = 0; row < height; row++)
	{
		for (col = 0; col < (width + padding); col++)
		{
			if (col < width)
			{
				fread(pix_in, 1, 3, fname);
				pix_out[0] = 0; //blue
				pix_out[1] = 0; //green
				pix_out[2] = pix_in[2]; //red

				fwrite(pix_out, 1, 3, fp_red);
			}
			else
			{
				fread(pix_in, padding, 1, fname);
				fwrite(pix_in, padding, 1, fp_red);
				col = col + padding;
			}
		}
	}
	
	fclose(fp_red);
	fclose(fname);
	return;
}


void convertGREEN(void)
{
	//opening and creating files
	FILE *fname, *fp_green;

	fname = fopen(FILENAME, "rb");

	fp_green = fopen("green.bmp", "w+b");

	if (fname == NULL) {
		printf("Error: fopen failed for fname.\n");

	}
	if (fp_green == NULL) {
		printf("Error: fopen failed for fop.\n");

	}


	int headerinfo[HEADERSIZE];
	//array for storing header info

	//copying header
	for (int i = 0; i < HEADERSIZE; i++)
	{
		int store;
		store = fgetc(fname);
		headerinfo[i] = store;
		//printf("%d ", headerinfo[i]);

	}

	int header_size = headerinfo[10]; //offset of header until pixel data
	//printf("header size: %d", header_size);
	//getchar();

	rewind(fname);//resetting pointer position
	int header_index = 0;
	int temp = 0;
	int width_19, width_18;
	int height_23, height_22;

	//reading and writing header to output file
	for (int i = 0; i < header_size; i++) {

		temp = fgetc(fname);
		if (header_index == 18)
		{
			width_18 = temp;
		}
		if (header_index == 19)
		{
			width_19 = temp;
		}
		if (header_index == 22)
		{
			height_22 = temp;
		}
		if (header_index == 23)
		{
			height_23 = temp;
		}

		header_index++;
		//printf("%d ", temp);
		fputc(temp, fp_green);
	}

	//calculating height and width 
	int width, height;
	width = width_19 * 256 + width_18;
	height = height_23 * 256 + height_22;
	//printf("width: %d\n", width);
	//printf("height: %d\n", height);

	//calculating padding
	int padding = 0;
	padding = width % 4;
	//printf("padding: %d\n", padding);

	unsigned char pix_in[3];
	unsigned char pix_out[3];
	int row = 0;
	int col = 0;

	//reading and modifying pixel data
	for (row = 0; row < height; row++)
	{
		for (col = 0; col < (width + padding); col++)
		{
			if (col < width)
			{
				fread(pix_in, 1, 3, fname);
				pix_out[0] = 0; //blue
				pix_out[1] = pix_in[1]; //green
				pix_out[2] = 0; //red

				fwrite(pix_out, 1, 3, fp_green);

			}
			else
			{
				fread(pix_in, padding, 1, fname);
				fwrite(pix_in, padding, 1, fp_green);
				col = col + padding;
			}
		}
	}

	fclose(fp_green);
	fclose(fname);
	return;
}

void convertBLUE(void)
{
	//opening and creating files
	FILE *fname, *fp_blue;

	fname = fopen(FILENAME, "rb");

	fp_blue = fopen("blue.bmp", "w+b");

	if (fname == NULL) {
		printf("Error: fopen failed for fname.\n");

	}
	if (fp_blue == NULL) {
		printf("Error: fopen failed for fop.\n");

	}


	int headerinfo[HEADERSIZE];
	//array for storing header info

	//copying header
	for (int i = 0; i < HEADERSIZE; i++)
	{
		int store;
		store = fgetc(fname);
		headerinfo[i] = store;
		//printf("%d ", headerinfo[i]);

	}

	int header_size = headerinfo[10]; //offset of header until pixel data
	//printf("header size: %d", header_size);
	//getchar();

	rewind(fname);//reseting pointer position
	int header_index = 0;
	int temp = 0;
	int width_19, width_18;
	int height_23, height_22;

	//copying and writing header to output file
	for (int i = 0; i < header_size; i++) {

		temp = fgetc(fname);
		if (header_index == 18)
		{
			width_18 = temp;
		}
		if (header_index == 19)
		{
			width_19 = temp;
		}
		if (header_index == 22)
		{
			height_22 = temp;
		}
		if (header_index == 23)
		{
			height_23 = temp;
		}

		header_index++;
		//printf("%d ", temp);
		fputc(temp, fp_blue);
	}

	//calculating height and width 
	int width, height;
	width = width_19 * 256 + width_18;
	height = height_23 * 256 + height_22;
	//printf("width: %d\n", width);
	//printf("height: %d\n", height);

	//calculating padding
	int padding = 0;
	padding = width % 4;
	//printf("padding: %d\n", padding);

	unsigned char pix_in[3];
	unsigned char pix_out[3];
	int row = 0;
	int col = 0;

	//reading and modifying pixel data
	for (row = 0; row < height; row++)
	{
		for (col = 0; col < (width + padding); col++)
		{
			if (col < width)
			{
				fread(pix_in, 1, 3, fname);
				pix_out[0] = pix_in[0]; //blue
				pix_out[1] = 0; //green
				pix_out[2] = 0; //red

				fwrite(pix_out, 1, 3, fp_blue);

			}
			else
			{
				fread(pix_in, padding, 1, fname);
				fwrite(pix_in, padding, 1, fp_blue);
				col = col + padding;
			}
		}
	}

	fclose(fp_blue);
	fclose(fname);
	return;
}

void convertGRAYSCALE(void)
{
	//opening and creating files
	FILE *fname, *fp_gray;

	fname = fopen(FILENAME, "rb");

	fp_gray = fopen("gray.bmp", "w+b");

	if (fname == NULL) {
		printf("Error: fopen failed for fname.\n");

	}
	if (fp_gray == NULL) {
		printf("Error: fopen failed for fop.\n");

	}


	int headerinfo[HEADERSIZE];
	//array for storing header info

	//Copying header
	for (int i = 0; i < HEADERSIZE; i++)
	{
		int store;
		store = fgetc(fname);
		headerinfo[i] = store;
		//printf("%d ", headerinfo[i]);

	}

	int header_size = headerinfo[10]; //offset of header until pixel data
	//printf("header size: %d", header_size);
	//getchar();

	//reset pointer position
	rewind(fname);
	int header_index = 0;
	int temp = 0;
	int width_19, width_18;
	int height_23, height_22;

	//Copying header to output file
	for (int i = 0; i < header_size; i++) {

		temp = fgetc(fname);
		if (header_index == 18)
		{
			width_18 = temp;
		}
		if (header_index == 19)
		{
			width_19 = temp;
		}
		if (header_index == 22)
		{
			height_22 = temp;
		}
		if (header_index == 23)
		{
			height_23 = temp;
		}

		header_index++;
		//printf("%d ", temp);
		fputc(temp, fp_gray);
	}

	//calculating height and width 
	int width, height;
	width = width_19 * 256 + width_18;
	height = height_23 * 256 + height_22;
	//printf("width: %d\n", width);
	//printf("height: %d\n", height);

	//calculating padding
	int padding = 0;
	padding = width % 4;
	//printf("padding: %d\n", padding);

	unsigned char pix_in[3];
	unsigned char pix_out[3];
	int row = 0;
	int col = 0;
	int graysale;

	//Reading and modifying pixel data before writing to output file
	for (row = 0; row < height; row++)
	{
		for (col = 0; col < (width + padding); col++)
		{
			if (col < width)
			{
				fread(pix_in, 1, 3, fname);
				graysale = ((pix_in[0] + pix_in[1] + pix_in[2]) / 3);
				pix_out[0] = graysale; //blue
				pix_out[1] = graysale; //green
				pix_out[2] = graysale; //red

				fwrite(pix_out, 1, 3, fp_gray);

			}
			else
			{
				fread(pix_in, padding, 1, fname);
				fwrite(pix_in, padding, 1, fp_gray);
				col = col + padding;
			}
		}
	}

	fclose(fp_gray);
	fclose(fname);
	return;
}


void convertBW(void)
{
	//opening and creating files
	FILE *fname, *fp_BW;

	fname = fopen(FILENAME, "rb");

	fp_BW = fopen("bw.bmp", "w+b");

	if (fname == NULL) {
		printf("Error: fopen failed for fname.\n");

	}
	if (fp_BW == NULL) {
		printf("Error: fopen failed for fp_red.\n");

	}


	int headerinfo[HEADERSIZE];
	//array for storing header info

	//Copying header
	for (int i = 0; i < HEADERSIZE; i++)
	{
		int store;
		store = fgetc(fname);
		headerinfo[i] = store;
		//printf("%d ", headerinfo[i]);

	}

	int header_size = headerinfo[10]; //offset of header until pixel data
	//printf("header size: %d", header_size);
	//getchar();

	rewind(fname);
	int header_index = 0;
	int temp = 0;
	int width_19, width_18;
	int height_23, height_22;

	//copying header and extracting header info
	for (int i = 0; i < header_size; i++) {

		temp = fgetc(fname);
		if (header_index == 18)
		{
			width_18 = temp;
		}
		if (header_index == 19)
		{
			width_19 = temp;
		}
		if (header_index == 22)
		{
			height_22 = temp;
		}
		if (header_index == 23)
		{
			height_23 = temp;
		}

		header_index++;
		//printf("%d ", temp);
		fputc(temp, fp_BW);
	}

	//calculating height and width 
	int width, height;
	width = width_19 * 256 + width_18;
	height = height_23 * 256 + height_22;
	//printf("width: %d\n", width);
	//printf("height: %d\n", height);

	//calculating padding
	int padding = 0;
	padding = width % 4;//4 - ((width * 3) % 4);
	//printf("padding: %d\n", padding);

	unsigned char pix_in[4];
	unsigned char pix_out[4];
	int row = 0;
	int col = 0;
	
	//reading and modifying pixel data
	for (row = 0; row < height; row++)
	{
		for (col = 0; col < (width + padding); col++)
		{
			if (col < width)
			{
				fread(pix_in, 1, 3, fname);

				
				
					if (((pix_in[0] + pix_in[1] + pix_in[2]) / 3) <= 127)
					{
						pix_out[0] = 0; //green
						pix_out[1] = 0; //red
						pix_out[2] = 0;//blue
						
					}
					if (((pix_in[0] + pix_in[1] + pix_in[2]) / 3) > 127)
					{
						pix_out[0] = 255; //green
						pix_out[1] = 255; //red
						pix_out[2] = 255;//blue
						
						
					}
					
				



				fwrite(pix_out, 1, 3, fp_BW);
			}
			else
			{
				fread(pix_in, padding, 1, fname);
				fwrite(pix_in, padding, 1, fp_BW);
				col = col + padding;

			}
		}
	}
	//getchar();
	fclose(fp_BW);
	fclose(fname);
	return;
} 


void convertBLUR(void)
{
	//opening and creating files
	FILE *fname, *fp_blur;

	fname = fopen(FILENAME, "rb");

	fp_blur = fopen("blur.bmp", "w+b");

	if (fname == NULL) {
		printf("Error: fopen failed for fname.\n");

	}
	if (fp_blur == NULL) {
		printf("Error: fopen failed for fp_red.\n");

	}


	int headerinfo[HEADERSIZE];
	//array for storing header info


	for (int i = 0; i < HEADERSIZE; i++)
	{
		int store;
		store = fgetc(fname);
		headerinfo[i] = store;
		//printf("%d ", headerinfo[i]);

	}
	
	
	int header_size = headerinfo[10]; //offset of header until pixel data
	//printf("header size: %d", header_size);
	//getchar();

	rewind(fname); //reset file pointer
	int header_index = 0;
	int temp = 0;
	int width_19, width_18;
	int height_23, height_22;

	//copying header while extracting header info
	for (int i = 0; i < header_size; i++) {

		temp = fgetc(fname);
		if (header_index == 18)
		{
			width_18 = temp;
		}
		if (header_index == 19)
		{
			width_19 = temp;
		}
		if (header_index == 22)
		{
			height_22 = temp;
		}
		if (header_index == 23)
		{
			height_23 = temp;
		}

		header_index++;
		//printf("%d ", temp);
		fputc(temp, fp_blur);
	}

	//calculating height and width 
	int width, height;
	width = width_19 * 256 + width_18;
	height = height_23 * 256 + height_22;
	//printf("width: %d\n", width);
	//printf("height: %d\n", height);

	int bitmp_width = width_18;
	int bitmp_height = height_22;
	//printf("bmpw: %d, bmph: %d", bitmp_width, bitmp_height);
	//getchar();

	//calculating padding
	int padding = 0;
	padding = width % 4; //4 - ((width * 3) % 4);
	//printf("padding: %d\n", padding);

	
	int row = 0;
	int col = 0;

	//creating a 2D array
	unsigned char** bitmp_original;
	unsigned char** bitmp_blur;

	bitmp_original = (unsigned char**)malloc(height*(sizeof(unsigned char *)));

	bitmp_blur = (unsigned char**)malloc(height * sizeof(unsigned char *));

	for (int i = 0; i < height; i++)
	{
		bitmp_original[i] = (unsigned char*)malloc(((width * 3) + padding)*(sizeof(unsigned char)));
	}
	
	for (int i = 0; i < height; i++)
	{
		bitmp_blur[i] = (unsigned char*)malloc(((width * 3) + padding)*(sizeof(unsigned char)));
	}

	//Getting pixel data from original image
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < (width * 3) + padding; col++)
		{
			int store = fgetc(fname);
			bitmp_original[row][col] = store;
		}
	}

	int pix_blur = 0;
	int pix_row = 0;
	int pix_col = 0;

	for (row = 0; row < height; row++)
	{
		for (col = 0; col < width; col++)
		{
			for (int pix_index = 0; pix_index < 3; pix_index++)
			{
				int pix_count = 0;
				int pix_sum = 0;

				for (int y = -3; y <= 3; y++) //y-coordinate
				{
					for (int x = -3; x <= 3; x++) //x-coordinate
					{
						//row pixel = y+row
						if ((y + row >= 0) && (y + row < height) && (x + col < width))
						{
							pix_sum = pix_sum + bitmp_original[row + y][(col + x) * 3 + pix_index];
							pix_count++;
						}
					}
				}

				pix_blur = pix_sum / pix_count;
				bitmp_blur[row][col * 3 + pix_index] = pix_blur;
			}
		}
	}

	// copying modified pixels into blurred image
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < ((width * 3) + padding); col++) {
			int temp_store = bitmp_blur[row][col];
			fputc(temp_store, fp_blur);

		}
	}

	//free allocated memory
	free(bitmp_original);
	free(bitmp_blur);

	fclose(fp_blur);
	fclose(fname);
	return;
}

