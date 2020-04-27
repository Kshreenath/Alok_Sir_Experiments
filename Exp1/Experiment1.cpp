#include<opencv2/opencv.hpp>
#include<stdio.h>

using namespace cv;

int main(int argc,char** argv){
    
    if(argc !=2){
    
    printf("usage : displayImage.out <Image_Path> \n");
        return -1;
    }
    Mat image=imread(argv[1],1);
    
    if(!image.data)
    {
        printf("No Image Data\n");
        return -1;
    }
    namedWindow("Experiment1",CV_WINDOW_AUTOSIZE);
    imshow("Display Image",image);
    waitKey(0);
    return 0;
}
