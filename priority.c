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
    int bt[20], p[20], wt[20], tat[20], pr[20];\
    int n, i, j, temp;\
\
    printf("Enter number of processes: ");\
    scanf("%d", &n);\
\
    for(i = 0; i < n; i++) \{\
\
        printf("Burst time for P%d: ", i + 1);\
        scanf("%d", &bt[i]);\
\
        printf("Priority for P%d: ", i + 1);\
        scanf("%d", &pr[i]);\
\
        p[i] = i + 1;\
    \}\
\
    /* Sorting based on priority */\
    for(i = 0; i < n; i++) \{\
\
        for(j = i + 1; j < n; j++) \{\
\
            if(pr[i] > pr[j]) \{\
\
                temp = pr[i];\
                pr[i] = pr[j];\
                pr[j] = temp;\
\
                temp = bt[i];\
                bt[i] = bt[j];\
                bt[j] = temp;\
\
                temp = p[i];\
                p[i] = p[j];\
                p[j] = temp;\
            \}\
        \}\
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
    printf("\\nProcess\\tBT\\tPR\\tWT\\tTAT\\n");\
\
    for(i = 0; i < n; i++)\
        printf("P%d\\t%d\\t%d\\t%d\\t%d\\n",\
               p[i], bt[i], pr[i], wt[i], tat[i]);\
\
    return 0;\
\}}