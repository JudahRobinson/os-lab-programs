{\rtf1\ansi\ansicpg1252\cocoartf2822
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\froman\fcharset0 Times-Roman;}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;}
{\*\expandedcolortbl;;\cssrgb\c0\c0\c0;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\partightenfactor0

\f0\fs24 \cf0 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 #include <stdio.h>\
\
int main() \{\
    int n, i;\
    int bt[20], wt[20], tat[20];\
\
    printf("Enter number of processes: ");\
    scanf("%d", &n);\
\
    for(i = 0; i < n; i++) \{\
        printf("Enter Burst Time for P%d: ", i + 1);\
        scanf("%d", &bt[i]);\
    \}\
\
    wt[0] = 0;\
\
    for(i = 1; i < n; i++)\
        wt[i] = wt[i - 1] + bt[i - 1];\
\
    for(i = 0; i < n; i++)\
        tat[i] = wt[i] + bt[i];\
\
    printf("\\nProcess\\tBT\\tWT\\tTAT\\n");\
\
    for(i = 0; i < n; i++)\
        printf("P%d\\t%d\\t%d\\t%d\\n",\
               i + 1, bt[i], wt[i], tat[i]);\
\
    return 0;\
\}}