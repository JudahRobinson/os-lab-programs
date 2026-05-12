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
    int bt[20], rem[20], wt[20], tat[20];\
    int n, tq, i, time = 0, done;\
\
    printf("Enter number of processes: ");\
    scanf("%d", &n);\
\
    for(i = 0; i < n; i++) \{\
        printf("Burst time for P%d: ", i + 1);\
        scanf("%d", &bt[i]);\
        rem[i] = bt[i];\
    \}\
\
    printf("Enter Time Quantum: ");\
    scanf("%d", &tq);\
\
    do \{\
        done = 1;\
\
        for(i = 0; i < n; i++) \{\
\
            if(rem[i] > 0) \{\
                done = 0;\
\
                if(rem[i] > tq) \{\
                    time += tq;\
                    rem[i] -= tq;\
                \}\
                else \{\
                    time += rem[i];\
                    wt[i] = time - bt[i];\
                    rem[i] = 0;\
                \}\
            \}\
        \}\
\
    \} while(!done);\
\
    for(i = 0; i < n; i++)\
        tat[i] = bt[i] + wt[i];\
\
    printf("\\nProcess\\tBT\\tWT\\tTAT\\n");\
\
    for(i = 0; i < n; i++)\
        printf("P%d\\t%d\\t%d\\t%d\\n",\
               i + 1, bt[i], wt[i], tat[i]);\
\
    return 0;\
\}}