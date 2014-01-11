#ifndef _FD_CONFIG_H
#define _FD_CONFIG_H

typedef struct
{
    unsigned int FDThreadNum;
    unsigned int FDThreshold;
    unsigned int MajorFaceDecision;
    unsigned int OTRatio;
    unsigned int SmoothLevel;
    unsigned int FDSkipStep;
    unsigned int FDRefresh;
}FD_Customize_PARA;


void get_fd_CustomizeData(FD_Customize_PARA  *FDDataOut);
	
#endif /* _FD_CONFIG_H */

