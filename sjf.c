{\rtf1\ansi\ansicpg1252\cocoartf2822
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <stdio.h>\
\
int main() \{\
    int bt[20], p[20], wt[20], tat[20];\
    int n, i, j, temp;\
\
    printf("Enter number of processes: ");\
    scanf("%d", &n);\
\
    for(i = 0; i < n; i++) \{\
        printf("Enter Burst Time for P%d: ", i + 1);\
        scanf("%d", &bt[i]);\
\
        p[i] = i + 1;\
    \}\
\
    /* Sorting burst times in ascending order */\
    for(i = 0; i < n; i++) \{\
\
        for(j = i + 1; j < n; j++) \{\
\
            if(bt[i] > bt[j]) \{\
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
    printf("\\nProcess\\tBT\\tWT\\tTAT\\n");\
\
    for(i = 0; i < n; i++)\
        printf("P%d\\t%d\\t%d\\t%d\\n",\
               p[i], bt[i], wt[i], tat[i]);\
\
    return 0;\
\}}