{\rtf1\ansi\ansicpg1252\cocoartf2822
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <stdio.h>\
#include <stdlib.h>\
\
int main() \{\
\
    int ms, ps, nop, np, rempages;\
    int i, j, x, y, pa, offset;\
\
    int s[10], fno[10][20];\
\
    printf("\\nEnter the memory size -- ");\
    scanf("%d", &ms);\
\
    printf("\\nEnter the page size -- ");\
    scanf("%d", &ps);\
\
    nop = ms / ps;\
\
    printf("\\nThe no. of pages available in memory are -- %d", nop);\
\
    printf("\\nEnter number of processes -- ");\
    scanf("%d", &np);\
\
    rempages = nop;\
\
    for(i = 1; i <= np; i++) \{\
\
        printf("\\nEnter no. of pages required for P[%d] -- ", i);\
        scanf("%d", &s[i]);\
\
        if(s[i] > rempages) \{\
            printf("\\nMemory is Full\\n");\
            break;\
        \}\
\
        rempages = rempages - s[i];\
\
        printf("\\nEnter page table for P[%d] -- ", i);\
\
        for(j = 0; j < s[i]; j++)\
            scanf("%d", &fno[i][j]);\
    \}\
\
    printf("\\nEnter Logical Address to find Physical Address");\
\
    printf("\\nEnter process no., page number and offset -- ");\
    scanf("%d %d %d", &x, &y, &offset);\
\
    if(x > np || y >= s[x] || offset >= ps) \{\
\
        printf("\\nInvalid Process or Page Number or Offset");\
\
    \} else \{\
\
        pa = fno[x][y] * ps + offset;\
\
        printf("\\nThe Physical Address is -- %d", pa);\
    \}\
\
    return 0;\
\}}