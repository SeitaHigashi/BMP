#include <stdio.h>

struct {
	char filetype[2],filesize[4], yoyaku1[2], yoyaku2[2], offset[4],headsize[4],weightsize[4],hightsize[4];
} typedef bmpfile;

union {
	char data[26];
	bmpfile bmp;
} typedef bmpuni;

int main(void){
    FILE *fp=fopen("AMD.bmp","rb");
    int j;
    unsigned char i;
	bmpuni b;
	for(j=0;j<26;j++) {
		 fscanf(fp,"%c", &(b.data[j]));
	}
	puts(b.bmp.filetype);
	puts(b.bmp.filesize);
	puts(b.bmp.yoyaku1);
	printf("headsize:%d\n",b.bmp.headsize);
	puts(b.bmp.weightsize);
	puts(b.bmp.hightsize);
	//printf("%o"
  // for(j=1;/*feof(fp)==0*/j<=100;j++){
    /*    fscanf(fp,"%c",&i);
        printf("%02x",i);
        if(j%50==0)puts("");
    }
    */fclose(fp);
    return 0;
}
