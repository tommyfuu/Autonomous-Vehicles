//header file, strict for C/C++ multi-file system, you may choose not having it for Arduino
#ifndef _GC_FLASH_H_ //ensure this header file will only be included once (if multiple file need this header)
#define _GC_FLASH_H_

//GC[] gold code to broadcast, oldGoatTime, the time previous broadcasting ends, flipped true: inversed, else: regular
unsigned long broadcastGC(bool GC[], unsigned long oldGoalTime, bool flipped);

#endif
