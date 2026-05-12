{\rtf1\ansi\ansicpg1252\cocoartf2822
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <stdio.h>\
\
int findLRU(int time[], int n) \{\
\
    int i, minimum = time[0], pos = 0;\
\
    for(i = 1; i < n; ++i) \{\
\
        if(time[i] < minimum) \{\
            minimum = time[i];\
            pos = i;\
        \}\
    \}\
\
    return pos;\
\}\
\
int main() \{\
\
    int no_of_frames, no_of_pages;\
    int frames[10], pages[30], time[10];\
\
    int counter = 0;\
    int flag1, flag2;\
    int i, j, pos, faults = 0;\
\
    printf("Enter number of frames: ");\
    scanf("%d", &no_of_frames);\
\
    printf("Enter number of pages: ");\
    scanf("%d", &no_of_pages);\
\
    printf("Enter reference string: ");\
\
    for(i = 0; i < no_of_pages; ++i)\
        scanf("%d", &pages[i]);\
\
    for(i = 0; i < no_of_frames; ++i)\
        frames[i] = -1;\
\
    for(i = 0; i < no_of_pages; ++i) \{\
\
        flag1 = flag2 = 0;\
\
        for(j = 0; j < no_of_frames; ++j) \{\
\
            if(frames[j] == pages[i]) \{\
\
                counter++;\
                time[j] = counter;\
\
                flag1 = flag2 = 1;\
                break;\
            \}\
        \}\
\
        if(flag1 == 0) \{\
\
            for(j = 0; j < no_of_frames; ++j) \{\
\
                if(frames[j] == -1) \{\
\
                    counter++;\
                    faults++;\
\
                    frames[j] = pages[i];\
                    time[j] = counter;\
\
                    flag2 = 1;\
                    break;\
                \}\
            \}\
        \}\
\
        if(flag2 == 0) \{\
\
            pos = findLRU(time, no_of_frames);\
\
            counter++;\
            faults++;\
\
            frames[pos] = pages[i];\
            time[pos] = counter;\
        \}\
\
        printf("\\n");\
\
        for(j = 0; j < no_of_frames; ++j)\
            printf("%d\\t", frames[j]);\
    \}\
\
    printf("\\n\\nTotal Page Faults = %d\\n", faults);\
\
    return 0;\
\}}