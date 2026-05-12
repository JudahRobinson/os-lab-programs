{\rtf1\ansi\ansicpg1252\cocoartf2822
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <stdio.h>\
\
int main() \{\
\
    int i, j, k;\
    int n, frameno;\
    int page[50], frame[10];\
    int move = 0, flag;\
    int count = 0;\
    int count1[10] = \{0\};\
\
    printf("Enter number of pages: ");\
    scanf("%d", &n);\
\
    printf("Enter page reference string: ");\
\
    for(i = 0; i < n; i++)\
        scanf("%d", &page[i]);\
\
    printf("Enter number of frames: ");\
    scanf("%d", &frameno);\
\
    for(i = 0; i < frameno; i++)\
        frame[i] = -1;\
\
    printf("Page Reference String\\tFrames\\n");\
\
    for(i = 0; i < n; i++) \{\
\
        printf("%d\\t\\t\\t", page[i]);\
\
        flag = 0;\
\
        for(j = 0; j < frameno; j++) \{\
\
            if(page[i] == frame[j]) \{\
\
                flag = 1;\
                count1[j]++;\
                break;\
            \}\
        \}\
\
        if(flag == 0) \{\
\
            for(j = 0; j < frameno; j++) \{\
\
                if(frame[j] == -1) \{\
\
                    frame[j] = page[i];\
                    count1[j]++;\
                    count++;\
                    break;\
                \}\
            \}\
\
            if(j == frameno) \{\
\
                int min = 0;\
\
                for(k = 1; k < frameno; k++) \{\
\
                    if(count1[k] < count1[min])\
                        min = k;\
                \}\
\
                frame[min] = page[i];\
                count1[min] = 1;\
                count++;\
            \}\
        \}\
\
        for(j = 0; j < frameno; j++)\
            printf("%d\\t", frame[j]);\
\
        printf("\\n");\
    \}\
\
    printf("Total Page Faults: %d\\n", count);\
\
    return 0;\
\}}