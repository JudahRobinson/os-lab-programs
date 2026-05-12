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
\
    int n, m, i, j;\
\
    printf("Enter number of processes: ");\
    scanf("%d", &n);\
\
    printf("Enter number of resources: ");\
    scanf("%d", &m);\
\
    int allocation[n][m], request[n][m], available[m];\
    int finish[n], work[m];\
\
    printf("Enter Allocation Matrix:\\n");\
\
    for(i = 0; i < n; i++)\
        for(j = 0; j < m; j++)\
            scanf("%d", &allocation[i][j]);\
\
    printf("Enter Request Matrix:\\n");\
\
    for(i = 0; i < n; i++)\
        for(j = 0; j < m; j++)\
            scanf("%d", &request[i][j]);\
\
    printf("Enter Available Resources:\\n");\
\
    for(i = 0; i < m; i++) \{\
        scanf("%d", &available[i]);\
        work[i] = available[i];\
    \}\
\
    for(i = 0; i < n; i++)\
        finish[i] = 0;\
\
    int found;\
\
    do \{\
\
        found = 0;\
\
        for(i = 0; i < n; i++) \{\
\
            if(!finish[i]) \{\
\
                int possible = 1;\
\
                for(j = 0; j < m; j++) \{\
\
                    if(request[i][j] > work[j]) \{\
                        possible = 0;\
                        break;\
                    \}\
                \}\
\
                if(possible) \{\
\
                    for(j = 0; j < m; j++)\
                        work[j] += allocation[i][j];\
\
                    finish[i] = 1;\
                    found = 1;\
                \}\
            \}\
        \}\
\
    \} while(found);\
\
    int deadlock = 0;\
\
    for(i = 0; i < n; i++) \{\
\
        if(!finish[i]) \{\
            deadlock = 1;\
            printf("Process P%d is in deadlock\\n", i);\
        \}\
    \}\
\
    if(!deadlock)\
        printf("No Deadlock Detected\\n");\
\
    return 0;\
\}}