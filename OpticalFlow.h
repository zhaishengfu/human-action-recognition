#pragma once
#include "stdafx.h"
#define N_FRAMES_SUM 5

class OpticalFlow
{
public:
	OpticalFlow(CvSize imgSize, CvSize outImageSize = cvSize(80,60));
	~OpticalFlow(void);
	void Calculate(IplImage *frame);
	void Draw();
	void Write(ofstream &fout);
	void Align(CvRect face, IplImage *mask = NULL);
	void OpticalFlow::Normalize(IplImage *image);
	void OpticalFlow::Smooth(IplImage *image);
	void Split();
	void Finalize();
	double* GetData();
	void EqualizeHistogram(IplImage *image);
public:
	IplImage *_velx, *_vely, *_velz, *_tmp, *_gray1, *_gray2;
	CvSize _outImageSize;
	IplImage *_nFlow[N_FRAMES_SUM], *_eFlow[N_FRAMES_SUM], *_sFlow[N_FRAMES_SUM], 
		*_wFlow[N_FRAMES_SUM], *_zFlow[N_FRAMES_SUM];
	IplImage *_nSum, *_eSum, *_sSum, *_wSum, *_zSum;
	double *_data;
};