#pragma once
typedef unsigned short USH;  //短整型
typedef unsigned char UCH;   //字符
typedef unsigned long long ULL;  //长整型

static USH WMASK = 32 * 1024 - 1;    //滑动窗口掩码
static USH MIN_MATCH = 3;           //最小匹配长度
static USH MAX_DIST = WMASK;

static size_t WSIZE = 32 * 1024;    //滑动窗口大小